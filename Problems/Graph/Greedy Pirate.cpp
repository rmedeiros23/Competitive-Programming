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
#define debug true
#define MAX 100005  
#define MOD 1000000007

struct liga
{
	int v,c1,c2;
};

int id[MAX],ida;
vector<liga> v[MAX];
int dp1[MAX],dp2[MAX];
int tot;
void inicializa(int tam)
{
	for(int i=0;i<=tam;i++)
		v[i].clear();
	ida = 1;
	tot = 0;
}

void calculaid(int u,int pai)
{
	id[u] = ida;
	ida++;
	for(int i=0;i<v[u].size();i++)
	{
		liga aux = v[u][i];
		int nxt = aux.v;
		if(nxt!=pai)
			calculaid(nxt,u);
	}
}

void dfs(int u,int pai,int cost1,int cost2)
{
	dp1[u] = cost1;
	dp2[u] = cost2;
	for(int i=0;i<v[u].size();i++)
	{
		liga aux = v[u][i];
		int nxt = aux.v;
		if(nxt!=pai)
		{
			dfs(nxt,u,cost1+aux.c1, cost2 + aux.c2);
		}
	}
}
int main()
{
	fastcin;
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		inicializa(n);
		for(int i=0;i<n-1;i++)
		{
			int a,b,cst1,cst2;
			liga aux;
			cin >> a >> b >> cst1 >> cst2;
			tot+= cst1 + cst2;
			aux.v = b;
			aux.c1 = cst1;
			aux.c2 = cst2;
			v[a].pb(aux);
			aux.c1 = cst2;
			aux.c2 = cst1;
			aux.v = a;
			v[b].pb(aux);
		}
		calculaid(1,-1);
		dfs(1,-1,0,0);
		if(debug)
		{
			for(int i=1;i<=n;i++)
				cout << "dp[" << i << "] = " << dp1[i] << endl;
			for(int i=1;i<=n;i++)
				cout << "dp[" << i << "] = " << dp2[i] << endl;
		}
		int q;
		cin >> q;
		while(q--)
		{
			int x,y;
			cin >> x >> y;
			if(id[x] < id[y]) // x esta em cima 
				cout << tot - (dp2[y] - dp2[x]) << endl;
			else
				cout << tot - (dp1[x] - dp1[y]) << endl;


		}
	}
			
}
