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
#define MAX 102
#define N 998244353

int proibido =-1;
std::vector<int> grafo[MAX];
bool vis[MAX];
int resp=0;
void inicializa()
{
	resp = 0;
	for(int j=0;j<MAX;j++)
		grafo[j].clear();
	proibido =-1;
}

void dfs(int a)
{	
	vis[a] = true;
	for(int i=0;i<grafo[a].size();i++)
	{
		if(vis[grafo[a][i]]==false and grafo[a][i]!=proibido)
			dfs(grafo[a][i]);
	}
}

int main()
{	
	fastcin;
	int n;
	cin >> n;
	while(n!=0)
	{
		inicializa();
		while(1)
		{	
			string line;
			getline(cin,line);
			stringstream ss(line);
			vector<int> aux;
			int x;
			while(ss >> x)
				aux.pb(x);
			if(aux.size() == 1 and aux[0] == 0)
				break;
			for(int i=1;i<aux.size();i++)
			{
				grafo[aux[0]].pb(aux[i]);// criand grafo
				grafo[aux[i]].pb(aux[0]);
			}
		}
		for(int i=1;i<=n;i++) // faco uma dfs pra cada elemento
		{
			memset(vis,0,sizeof vis);
			proibido = i;
			if(i == 1)
				dfs(2);
			else
				dfs(1);
			int quant =0;
			for(int j=1;j<=n;j++)
			{
				if(vis[j] == true)
					quant++;
			}
			if(quant < n-1)
				resp++;
		}
		cout << resp << endl;
		cin >> n;
	}
	
	return 0;
}
