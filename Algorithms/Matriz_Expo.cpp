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
#define MOD  // Em geral necessário em exponenciação de matriz
#define MAX 

typedef vector<vector<ll int > > matrix;

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
		for(int j = 0 ; j<colunas_A;j++) 
		{
			// parte que vai ser percorrida na multiplicação (linhas_B = Colunas_A)	
			for(int z =0 ;z<linhas_B;z++)
			{
				ret[i][j] += (A[i][z]*B[z][i])%MOD;			
			}
		}
	}
	return ret;
}

// O(N^3 * log2(B) 
matrix Fast_matrix_exp (matrix A,ll int b, ll int m)
{
	matrix ret = init();// função que inicializa matriz base (Ser codada)
	while(b>0)
	{
		if(b%2 == 1)
			ret = mult(ret,A);
		b/=2;
		A = mult(A,A);
	}
	return ret;
}

matrix init(int tam)
{

}

int main()
{	
	fastcin;
	

}
