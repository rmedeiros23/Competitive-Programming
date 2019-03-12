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
#define MAX 10004
 
typedef struct // armazena todas as arestas do grafo
{
	int u,v; // vai de u pra v
	int f,cap; // flow atual = f e cap = capacidade maxima de passar na aresta;
}edge;
 
int cnt=0;
edge edges[MAX];
vector<int> e[MAX];
int target,source;
int dis[MAX];
int n;
 
/* 
	cria aresta comum entre o nó U->V e aresta reversa V->U
	Ambas são armazenadas seguidas no vector edges
*/
 
void add_edge(int u,int v, int c)
{
	edge aux;
	aux.u = u;
	aux.v = v;
	aux.cap = c;
	aux.f = 0;
 
	edges[cnt] = aux; // crio aresta, inicialmente fluxo que passa = 0 e capacidade = máxima
	e[u].pb(cnt);
	cnt++;
 
	// vetor exemplo 
	//[1][!1][2][!2][3][!3] -> xor entre p e 1 retorna aresta inversa, sendo p, posição de uma aresta
	aux.u = v;
	aux.v = u;
	aux.cap = c;
	aux.f = c;
 
	edges[cnt] = aux; // crio aresta reversa na posição exatamente seguinte
	e[v].pb(cnt);  
	cnt++;
}
 
bool bfs()
{
	memset(dis,INF,sizeof dis);
	dis[source] = 0; // distância de Source = 0
	queue <int> q;
	q.push(source);
	while(q.size()!=0)
	{
		int u = q.front();
		q.pop();
		for(int i=0;i<e[u].size();i++)// todas arestas saindo de U
		{
 
			int p,v;
			edge at;
			p = e[u][i]; // e[u] armazena todos os índices de edges saindo de U, p é esse específico
			at = edges[p];
			v = edges[p].v; // aresta atual = aresta de V
 
 
			if(dis[v] == INF and at.cap > at.f) // se não foi visitado e pode ser visitado (alguma dfs ainda não limitou aquela aresta)
			{
				dis[v] = dis[u]+1;
				q.push(v);
			}
		}
	}
	if(dis[target]!=INF) // visitou
		return true;
	return false;
}
 
 
int dfs(int u,int f) // estou no nó U e tenho de flow livre -> f;
{
	//cout << u << endl;
	if(f <= 0) // deu ruim esse caminho
		return 0;
	if(u == target)
		return f; // cheguei no final e entreguei f de água por esse caminho
	for(int i=0;i<e[u].size();i++) // ver todas as arestas saindo de u
	{
		int x;
		int p = e[u][i];
		edge at = edges[p];
		int v = at.v;
		if(dis[v] == dis[u]+1 and (x = dfs(v,min(f,at.cap-at.f))) )// se a recursão der certo e dfs!=0 e estiver o caminho na bfs() ->dis[v] é filho de dis[u]                                       
		{
			edges[p].f+=x;
			edges[(p^1)].f-=x;
			return x;
		}
	}
	return 0;
}
 
int max_flow()
{
	int f = 0;
	int x;
	while(bfs())
	{
		while((x = dfs(source,INF)))
		{
			f+=x;
		}
	}
	return f;
}
void incializa()
{
	cnt = 0;
	for(int i=0;i<MAX;i++)
	{
		e[i].clear();
		edges[i].u = -1;
		edges[i].v = -1;
		edges[i].f = 0;
		edges[i].cap = 0;
	}
}


int main()
{
	int n;
	int ans;
	while((cin >> n))
	{
		ans = 0;
		source = 0;
		target = 2*n+1;
		vector<int> liga[MAX];
		for(int i = 1;i<=n;i++)
		{
			int a,b;
			cin >> a >> b;
			liga[i].pb(a);
			liga[i].pb(b);
		}
		for(int i=0;i<n;i++)
		{	
			incializa();
			int wolf = i+1;
			int m=0;
			int esp1,esp2;
			for(int j=1;j<=n;j++)
			{
				//cout << "at = " << j << endl;
 				if(j==wolf)
				{
					esp1 = liga[wolf][0]+n;
					esp2 = liga[wolf][1]+n;
					continue;
				}
				int op1,op2;
				op1 = liga[j][0];
				op2 = liga[j][1];
				if(op1 == wolf or op2 == wolf)
				{
					m++;
					continue;
				}
				//cout << "crio laco entre " << j << " e " << op1+n << endl;
				//cout << "crio laco entre " << j << " e " << op2+n << endl;
				add_edge(j,op1+n,1);
				add_edge(j,op2+n,1);
				add_edge(0,j,1);
			}
			// for(int j=1;j<=n;j++) // liga source no 
			// {
			// 	if(j == wolf)
			// 		continue;
			// 	cout << "crio laco entre " << 0 << " e " << j << endl;
			// 	add_edge(0,j,1);
			// }
			target = 2*n+1;
			for(int j=n+1;j<=2*n;j++) // liga todos no target;
			{
				if(j == wolf+n)
					continue;
				if(j == esp1 or j == esp2)
					add_edge(j,target,m-2);
				else
					add_edge(j,target,m-1);
				//cout << "crio laco entre " << j << " e " << target << endl;
			}

			int resp = max_flow();
			//cout << resp << endl;
			if(resp<((n-1)-m))
				ans++;
			//cout << endl << endl << endl;
		}
		cout << ans << endl;
	}
}
