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
#define MAX 50
int n,m;
map<string,int> ida;
map<int,string> volta;
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
	ida.clear();
	volta.clear();
}


int main()
{	
	fastcin;
	int casos = 1;
	cin >> n >> m;
	while(n!=0 or m!=0)
	{
		inicializa ();
		int aux =0;
		for(int i=0;i<m;i++)
		{
			string a,b;
			cin >> a >> b;
			if(ida.count(a) == false)
			{
				ida[a] = aux;
				volta[aux] = a;
				aux++;
			}
			if(ida.count(b) == false)
			{
				ida[b] = aux;
				volta[aux] = b;
				aux++;
			}
			grafo1[ida[a]].pb(ida[b]);
			grafo2[ida[b]].pb(ida[a]);
		}
		cout << "Calling circles for data set " << casos << ":" << endl;
		for(int i=0;i<n;i++)
		{
			vector<int> resp;
			g1.clear();
			g2.clear();
			memset(vis1,0,sizeof vis1);
			memset(vis2,0,sizeof vis2);
			if(visfin[i] == false)
			{
				dfs1(i);
				dfs2(i);
			}
			for(int j=0;j<g1.size();j++)
			{
				if(g2.count(g1[j]))
				{
					resp.pb(g1[j]);
					visfin[g1[j]] = true;
				}
			}
			for(int j=0;j<resp.size();j++)
			{
				cout << volta[resp[j]];
				if(j!=resp.size()-1)
					cout << ", ";
				else
					cout << endl;
			}
		}
		casos++;
		cin >> n >> m;
		if(n!=0 or m!=0)
			cout << endl;
	}
	

	return 0;
}

