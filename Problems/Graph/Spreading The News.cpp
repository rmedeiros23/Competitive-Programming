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
#define endl "\n"
#define MAX 3000

std::vector<int> grafo[MAX];

int main()
{	
	fastcin;
	int e;
	cin >>e;
	for(int i=0;i<e;i++)
	{
		int aux;
		cin >> aux;
		for(int j=0;j<aux;j++)
		{
			int a;
			cin >> a;
			grafo[i].pb(a);
		}
	}
	int t;
	cin >> t;
	while(t>0)
	{
		int dist[MAX];
		bool vis[MAX];
		int a;
		int last = -2;
		int dia=0,at=0; // valor e dia atual
		memset(vis,0,sizeof vis);
		memset(dist,-1,sizeof dist);
		queue<int> q;
		int respm=-1,respd=-1;
		cin >> a; // inicio da onda
		dist[a]=0;
		q.push(a);
		vis[a] = true;
		while(q.size()!=0)
		{
			int topo = q.front();
			q.pop();
			//cout << "Topo = " << topo << " pai = " << dist[topo] << "Last = " << last << endl;
			if(dist[topo]!=last)
			{
				//cout << " Mudou pai " << endl << endl <<endl;
				if(respm < at)
				{
					respm = at;
					respd = dia;
				}
				at = 0;
				dia++;
				last = dist[topo];
			}
			for(int i=0;i<grafo[topo].size();i++)
			{
				if(vis[grafo[topo][i]]== false)
				{
					q.push(grafo[topo][i]);
					vis[grafo[topo][i]] = true;
					dist[grafo[topo][i]] = dist[topo]+1;
					at++;
				}
			}
		}
		if(respm == 0 and respd == 0)
			cout << 0 << endl;
		else
			cout << respm << " " << respd << endl;
		t--;
	}
}