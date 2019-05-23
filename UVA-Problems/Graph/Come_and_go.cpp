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
#define MAX 2003
int n,m;
std::vector<int> grafo1[MAX],grafo2[MAX];
bool vis1[MAX],vis2[MAX],visfin[MAX];
std::vector<int> g1;
set<int> g2;

void dfs1(int a)
{
	//cout << "Visitando " << volta[a] << endl;
	g1.pb(a);
	vis1[a] = true;
	for(int i=0;i<grafo1[a].size();i++)
	{
		if(vis1[grafo1[a][i]] == false)
			dfs1(grafo1[a][i]);
	}
}
void dfs2(int a)
{
	//cout << "2Visitando " << volta[a] << endl;
	g2.insert(a);
	vis2[a] = true;
	for(int i=0;i<grafo2[a].size();i++)
	{
		if(vis2[grafo2[a][i]] == false)
			dfs2(grafo2[a][i]);
	}
}

void inicializa()
{
	for(int i=0;i<MAX;i++)
	{
		grafo1[i].clear();
		grafo2[i].clear();
		visfin[i] = false;
	}
	g1.clear();
	g2.clear();
	memset(vis1,0,sizeof vis1);
	memset(vis2,0,sizeof vis2);
}


int main()
{	
	fastcin;
	int casos = 1;
	cin >> n >> m;
	while(n!=0 or m!=0)
	{
		bool resp = true;;
		inicializa ();
		int aux =0;
		for(int i=0;i<m;i++)
		{
			int a,b,w;

			cin >> a >> b >> w;
			if(w == 1)
			{	
				grafo1[a].pb(b);
				grafo2[b].pb(a);
			}
			else
			{
				grafo1[a].pb(b);
				grafo1[b].pb(a);
				grafo2[b].pb(a);
				grafo2[a].pb(b);
			}

		}
		dfs1(1);
		dfs2(1);
		for(int i=1;i<=n;i++)
		{
			if(vis1[i] == false or vis2[i] == false)
				resp = false;
		}
		cout << resp << endl;
		cin >> n >> m;
	}
	

	return 0;
}

