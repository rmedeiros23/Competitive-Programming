#include <bits/stdc++.h>
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define endl "\n"
#define MAX 2000005
#define PI acos(-1)

vector<pair<int,int > > grafo[MAX];

int djikstra(int root,int target)
{
	int dist[MAX];
	for(int i=0;i<MAX;i++)
		dist[i] = INF;
	priority_queue<pair<int,int > > pq;
	dist[root] = 0;
	pq.push(mp(0,root));
	while(pq.size())
	{
		int topo = pq.top().se;
		int peso = -pq.top().fi;
		pq.pop();
		if(dist[topo] < peso)
			continue;
		for(int i=0;i<(int)grafo[topo].size();i++)
		{
			int next = grafo[topo][i].se;
			if(dist[next] > dist[topo] + grafo[topo][i].fi)
			{
				dist[next] = dist[topo] + grafo[topo][i].fi;
				pq.push(mp(-dist[next],next));
			}
		}
	}
	return dist[target];
}



int main()
{	
    fastcin;
}
