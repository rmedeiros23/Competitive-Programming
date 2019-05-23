#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define MAX 300

int p[MAX][MAX];
int acm[MAX][MAX];
int main()
{	
	fastcin;
	int t;
	cin>> t;
	while(t>0)
	{
		int n,m,k;
		cin >> n;
		m=n;
		int antm = m;
		int antn = n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin >> p[i][j];

		for(int i=1;i<=n;i++)
			for(int j=m+1;j<=2*m;j++)
				p[i][j] = p[i][j-m];

		for(int i=n+1;i<=2*n;i++)
			for(int j=1;j<=m;j++)
				p[i][j] = p[i-m][j];
		for(int i=n+1;i<=2*n;i++)
			for(int j=m+1;j<=2*m;j++)
				p[i][j] = p[i-m][j-m];
		m = 2*m;
		n = 2*n;
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) // pre-caulcula;
			{
				acm[i][j] = acm[i-1][j] + acm[i][j-1] - acm[i-1][j-1] + p[i][j];
				//cout << "Calculando acm[" << i<< "]["<<j<<"] = " << acm[i][j]<<endl;
			}
		//cout << "AQUIII" << acm[3][3] << endl;
		// responde verdadeiramente;
		int valorfin=-INF;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				//cout << "Para j = " << j << " for mair interno vai ate " << max(1,j-antm+1) << endl;
				for(int ii=i;ii>=max(1,i-antn+1);ii--)
				{
					for(int jj=j;jj>=max(1,j-antm+1);jj--)
					{	
						int valor = acm[i][j] - acm[ii-1][j] - acm[i][jj-1] + acm[ii-1][jj-1];
						if(i == 3 and j == 4)
						{
							//cout << "Valor atual = " << valor << " equivalente a posi [3][4] - [" << ii <<"] [" << jj << "]" << endl; 
							//cout << "Acm [i][j] = " << acm[i][j] << " acm[[ii-1][j] =  " << acm[ii-1][j] << " acm[i][[jj-1] = " << acm[i][jj-1] << " acm[ii-1][jj-1] = " << acm[ii-1][jj-1] << endl << endl;
						
						}
						valorfin = max(valorfin,valor);
					}
				}
			}

		cout << valorfin << endl;
		t--;
	}
	return 0;
}
/*
1
5 6 15
10 1 10 20 10 10
30 1 1 5 1 1
50 1 1 20 1 1
10 5 5 10 5 1
40 10 90 1 10 10




1
4 5 18
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
*/
