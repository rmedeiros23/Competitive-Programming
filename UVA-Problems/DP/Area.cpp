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
#define MAX 112

int p[MAX][MAX];
int acm[MAX][MAX];
int main()
{	
	fastcin;
	int t;
	int caso = 1;
	cin>> t;
	while(t>0)
	{
		int n,m,k;
		cin >> n >> m >> k;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin >> p[i][j];
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) // pre-caulcula;
				acm[i][j] = acm[i-1][j] + acm[i][j-1] - acm[i-1][j-1] + p[i][j];
		
		// responde verdadeiramente;
		int plots=-1,valorfin=INF;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				for(int ii=i;ii>=1;ii--)
					for(int jj=j;jj>=1;jj--)
					{	
						int valor = acm[i][j] - acm[ii-1][j] - acm[i][jj-1] + acm[ii-1][jj-1];
						int area = i*j - (ii-1)*j - i*(jj-1) + (ii-1)*(jj-1);
						if(valor>k)
							break;
						
						if(valor <=k and area > plots)
						{
							plots = area;
							valorfin = valor;
						}
						else if(valor <=valorfin and area == plots)
							valorfin = valor;
					}	
		if(valorfin == INF and plots == -1)
		{
			valorfin = 0;
			plots = 0;
		}
		cout << "Case #" << caso << ": " << plots << " " << valorfin << endl;
		t--;
		caso++;
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
