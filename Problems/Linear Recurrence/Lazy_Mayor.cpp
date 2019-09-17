#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 112345678912345678LL
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
#define endl "\n"
#define DEBUG false
#define MOD 1000000007   // Em geral necessário em exponenciação de matriz
#define MAX 

typedef vector<vector<ll int > > matrix;

matrix tudozero(int N)
{
	matrix ident;
	ident.resize(N);
	for(int i=0;i<N;i++)
	{
		ident[i].resize(N);
		for(int j=0;j<N;j++)
        {
            if(i==j)
				ident[i][j]=1;
            else
                ident[i][j] =0;
        }
	}
	return ident;
}
matrix tudoinf(int N)
{
    matrix ident;
	ident.resize(N);
	for(int i=0;i<N;i++)
	{
		ident[i].resize(N);
		for(int j=0;j<N;j++)
        {
            if(i==j)
				ident[i][j]=0;
            else
                ident[i][j] = INF;
            
        }
	}
	return ident;
}
// O(N^3)
pair<matrix,matrix>  mult(matrix A,matrix B,matrix C, matrix D) // matriz C/D = possibilidades A/B = distancias
{
	int linhas_A = A.size();
	int colunas_B = B[0].size();
	int colunas_A,linhas_B;
	colunas_A = linhas_B = B.size();// = A[0].size();

	matrix retD(linhas_A, vector<ll int> (colunas_B)),retP(linhas_A, vector<ll int> (colunas_B));

	// cada linha de A
	for(int i =0;i<linhas_A;i++)
	{
		// colunas de A -> defino elemento do ret (ret[i][j])
		for(int j = 0 ; j<colunas_B;j++) 
		{
			ll int val = INF,posi=0;
			// parte que vai ser percorrida na multiplicação (linhas_B = Colunas_A)	
			for(int z =0 ;z<linhas_B;z++)
			{
				if(A[i][z] + B[z][j] < val)// quero saber distancia
				{
					val = A[i][z] + B[z][j];
				}
			}
			retD[i][j] = (val);
			for(int z=0;z<linhas_B;z++)
			{
				if(A[i][z] + B[z][j] == val)
				{
					posi+=((C[i][z]%MOD)*(D[z][j]%MOD)%MOD);			
					posi%=MOD;
				}
			}
			retP[i][j] = posi;
		}
	}
	return mp(retD,retP);
}
// O(N^3 * log2(B) 
pair<matrix,matrix>  Fast_matrix_exp (matrix dist,matrix possib,ll int b) 
{
	int N = dist.size();// Para matriz se exponenciada, a matriz deve ser quadrada.
	matrix Mp0  = tudozero(N); // toda matriz elevada a 0 = identidade, sendo esse o caso base.
    matrix Md1 = tudoinf(N);
    pair<matrix,matrix> ret = mp(Md1,Mp0);
    pair<matrix,matrix> at = mp(dist,possib);
	while(b>0)
	{
		if(b%2 == 1)
			ret = mult(ret.fi,at.fi,ret.se,at.se);
		b/=2;
		at = mult(at.fi,at.fi,at.se,at.se);
	}
	return ret;
}

/*
   Função que inicializa matriz base (dependende da recorrência)
   Para matriz ser exponenciada, precisa ser matriz quadrada, por isso N único.
   */
void PrintMat(matrix A)
{
	int N = A.size();/*
	   Matriz de retorno tem número de linhas de A e número de colunas de B (axm . mxb = axb) 
	   a = número de linhas de A, cada linha de A é um vetor, logo número de vetores
	   b = número de colunas em B, como tem pelo menos 1 linha, número de colunas d linha 0 
	   */
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{	
	fastcin;
	int n,m,k;
	cin >> n >> m >> k;
	matrix dist(n,vector<ll int>(n)),possib(n,vector<ll int>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			possib[i][j] = 0;
			dist[i][j] = INF;
		}
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		a--;b--;
		dist[a][b] = c;
		dist[b][a] = c;
		possib[a][b] = 1;
		possib[b][a] = 1;
	} 
	if(DEBUG)
	{
		PrintMat(dist);
		cout << endl;
		PrintMat(possib);
	}
	pair<matrix,matrix> resp = Fast_matrix_exp(dist,possib,k);  
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
        {
            if(resp.fi[i][j] == INF)
                cout << "X" << " " << resp.se[i][j] << " "; 
            else
    			cout << resp.fi[i][j] << " " << resp.se[i][j] << " ";
        }
        cout << endl;
	}

}
