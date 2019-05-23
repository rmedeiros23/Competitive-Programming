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
#define MAXT 10005
#define aquiei cout << "aqui!" << endl;
vector<int> grafo[MAXT];
bool vis[MAXT];


void dfs(int at,bool vis[],std::vector<int> grafo[])
{
	vis[at] = true;
	for(int i=0;i<grafo[at].size();i++)
	{
		if(vis[grafo[at][i]] == false)
			dfs(grafo[at][i],vis,grafo);
	}
}


int main()
{	
	fastcin;
	int t;
	cin >> t;
	int casos=0;
	while(t>0)
	{	
		casos++;
		int n,resp=0;
		cin >>n;
		string mat[MAX];
		for(int i=0;i<n;i++)
		{
			cin >> mat[i];
		}
	
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(mat[i][j] != '.')
				{
					//cout << "No ponto " << i << " " << j ;
					if(i!=0 and mat[i-1][j] !='.')
					{
						//cout << "crio laço com " << i-1 << " " << j << endl ;	
						grafo[i*n+j].pb((i-1)*n+j);
					}
					
					if(i!=(n-1) and mat[i+1][j]!='.'){
						grafo[i*n+j].pb((i+1)*n+j);
						//cout << "crio laço com " << i+1 << " " << j << endl ;	
					}

					if(j!=0 and mat[i][j-1]!='.'){
						grafo[i*n+j].pb((i)*n+j-1);
						//cout << "crio laço com " << i << " " << j-1 << endl ;	
					}

					if(j!=(n-1) and mat[i][j+1]!='.'){
						//cout << "crio laço com " << i << " " << j+1 << endl ;	
						grafo[i*n+j].pb((i)*n+j+1);
					}

				}
			}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{

				int at = i*n + j;
				if(mat[i][j] == 'x' and vis[at] == false)
				{
					resp++;
					dfs(at,vis,grafo);
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int at = i*n + j;
				grafo[at].clear();
				vis[at] = false;
			}
		}
		cout << "Case " << casos << ": " << resp << endl;
		t--;
	}
	return 0;
}