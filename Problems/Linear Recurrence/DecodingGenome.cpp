#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
#define endl "\n"
#define debug false
#define MOD 1000000007   // Em geral necessário em exponenciação de matriz
#define MAX 

typedef vector<vector<ll int > > matrix;
int numb(char a)
{
	if(a>='a')
		return a-'a';
	else
		return a-'A' + 26; 
}
matrix identity(int N)
{
	matrix ident;
	ident.resize(N);
	for(int i=0;i<N;i++)
	{
		ident[i].resize(N);
		for(int j=0;j<N;j++)
			if(i==j)
				ident[i][j]=1;
	}
	return ident;
}
// O(N^3)
matrix mult(matrix A,matrix B)
{
	/*
	 	Matriz de retorno tem número de linhas de A e número de colunas de B (axm . mxb = axb) 
		a = número de linhas de A, cada linha de A é um vetor, logo número de vetores
		b = número de colunas em B, como tem pelo menos 1 linha, número de colunas d linha 0 
	*/
	int linhas_A = A.size();
	int colunas_B = B[0].size();
	int colunas_A,linhas_B;
	colunas_A = linhas_B = B.size();// = A[0].size();

	matrix ret(linhas_A, vector<ll int> (colunas_B));

	// cada linha de A
	for(int i =0;i<linhas_A;i++)
	{
		// colunas de A -> defino elemento do ret (ret[i][j])
		for(int j = 0 ; j<colunas_B;j++) 
		{
			// parte que vai ser percorrida na multiplicação (linhas_B = Colunas_A)	
			for(int z =0 ;z<linhas_B;z++)
			{
				ret[i][j] += (A[i][z]%MOD*B[z][j]%MOD)%MOD;			
				ret[i][j]%=MOD;
			}
		}
	}
	return ret;
}

// O(N^3 * log2(B) 
matrix Fast_matrix_exp (matrix A,ll int b) 
{
	int N = A.size();// Para matriz se exponenciada, a matriz deve ser quadrada.
	matrix ret = identity(N); // toda matriz elevada a 0 = identidade, sendo esse o caso base.
	while(b>0)
	{
		if(b%2 == 1)
			ret = mult(ret,A);
		b/=2;
		A = mult(A,A);
	}
	return ret;
}

/*
	Função que inicializa matriz base (dependende da recorrência)
	Para matriz ser exponenciada, precisa ser matriz quadrada, por isso N único.
*/
vector<pair<int,int> > inv;
matrix base(int N)
{
	matrix ret(N,vector<ll int>(N));		
	for(int i=0;i<N;i++)
	{
		for(int j = 0;j<N;j++)
			ret[i][j] = 1;
	}
	for(int i=0;i<inv.size();i++)
		ret[inv[i].fi][inv[i].se] = 0;
	return ret;
}
void PrintMat(matrix A)
{
	int N = A.size();
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
	ll int n,m,k;
	cin >> n >> m >> k;
	for(int i=0;i<k;i++)
	{
		char a,b;
		cin >> a >> b;
		int c,d;
		c = numb(a);
		d = numb(b);
		swap(c,d);
		inv.pb(mp(c,d));
	}
	matrix ini = base(m);		
	matrix res = Fast_matrix_exp(ini,n-1);
	matrix turn_integer(m);
	for(int i=0;i<m;i++)
		turn_integer[i].pb(1LL);
	matrix res2 = mult(res,turn_integer);
	ll int resp = 0;
	for(int i=0;i<m;i++)
	{
		resp+=res2[i][0];
		resp%=MOD;
	}
	cout << resp  << endl;
}
