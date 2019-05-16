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

}
