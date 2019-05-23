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
#define MAX 100005
int n,m;
std::vector<int> grafo[MAX],ord[MAX];
stack<int> ordem;
bool vis[MAX],visord[MAX];

void topsort(int a)
{
	visord[a] = true;
	for(int i=0;i<ord[a].size();i++)
		if(visord[ord[a][i]] == false)
			topsort(ord[a][i]);
	ordem.push(a);
}

void inicializa()
{
	int n;
	for(int i=0;i<MAX;i++)
	{
		grafo[i].clear();
		ord[i].clear();
		visord[i] = false;
		vis[i] = false;
	}
	
}
void dfs(int a)
{
	vis[a] = true;
	for(int i=0;i<grafo[a].size();i++)
	{
		if(vis[grafo[a][i]] == false)
			dfs(grafo[a][i]);
	}
}
int main()
{	
	fastcin;
	int t;
	cin >> t;
	while(t>0)
	{
		int resp = 0;
		cin >> n >> m;
		inicializa();
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin >> x >> y;
			x--;
			y--;
			grafo[x].pb(y);
			ord[x].pb(y);
		}
		for(int i=0;i<n;i++)
		{
			if(visord[i] == false)
			{
				topsort(i);
			}
		}
		//cout << "Tam = " << ordem.size() << endl;
		while(ordem.size()!=0)
		{
			int topo = ordem.top();
			//cout << "topo = " << topo << endl;
			ordem.pop();
			if(vis[topo] == false)
			{
				resp++;
				dfs(topo);
			}
		}
		cout << resp << endl;
		t--;
	}
	return 0;
}
