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
#define MAXN 200005
#define MAXLOG 20

int n,m,q;
int pai[MAXN],ancestral[MAXN][MAXLOG],level[MAXN];
vector<int> grafo[MAXN];

void bfs(int root) // pego o pai e o nivel
{
	queue<int>q;
	memset(level,-1, sizeof level);
	memset(pai, -1, sizeof pai);
	q.push(root);
	pai[root]=-1;
	level[root] = 0;
	while(q.size())
	{
		int at = q.front();
		q.pop();
		for(int i=0;i<grafo[at].size();i++)
		{
			int next = grafo[at][i];
			if(level[next] == -1)
			{
				level[next] = level[at] +1;
				pai[next] = at;
				q.push(next);
			}
		}
	}
}

void buildLCA()
{
	for(int i=0;i<MAXN;i++)
		for(int j=0;j<MAXLOG;j++)
			ancestral[i][j] = -1; // todo mundo igual a -1

	for(int i=0;i<n;i++)
		ancestral[i][0] = pai[i]; // ancestral de distancia 2^0 é o pai 

	/*
		Ancestral de distância x é ancestral de distancia x/2 do x/2 
		
		Exemplo: ancestral de distancia 1 é a mesma coisa de
		ancestral de distancia 1 do ancestral de distancia 1
		1 -> 2 -> 3
		2 é o ancestral de distancia 1 do 3 
		1 é o ancestral de distancia 1 do 2
		1 é o ancestral de distancia 1 do ancestral de distancia 1 do 3
		Exemplo: ancestral de distância 4 é a mesma coisa de 
		ancestral de distancia 2 do ancestral de distância 2
		1->2 ->3 -> 4 -> 5
		
		3 é o ancestral de distancia 2 do 5 
		1 é o ancestral de distancia 2 do 3
	 	1 é o ancestral de distancia 2 do ancestral de distancia 2 do 5
	*/
	for(int j=1;(1<<j) < n;j++)
	{
		for(int i=0;i<n;i++)
		{
			if(ancestral[i][j-1]!=-1)
			{
				ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
			}
		}
	}

}

int queryLCA(int a,int b)
{
	//Primeiramente preciso deixar os dois no mesmo nível (subo o que ta mais em baixo)
	if(level[a] < level[b])
		swap(a,b); // a é mais fundo;
	int dist = level[a]-level[b];
	int eleva=0; // quantos degraus eu subo

	while(dist>0)
	{
		if(dist%2 == 1)
		{
			a = ancestral[a][eleva];
		}
		eleva++;
		dist/=2;
	}
	
	if(a == b) // b era ancestral de a
		return a; // ou b

	/* 
		se não eram ancestrais diretos preciso subir ambos ao mesmo tempo
		até terem o próximo como primeiro ancestral direto
		(difícil subir direo ao de ancestral certo)
		Assim, preciso subir até achar o primeiro nó que tem pais iguais
	*/
	eleva = 0;
	for(int j=10;j>=0;j--)
	{
		if(ancestral[a][j]!=-1 and (ancestral[a][j] != ancestral[b][j]))
		{
			a = ancestral[a][j];
			b = ancestral[b][j];
		}
	}
	return pai[a];
}

int main()
{	
	/*
		0 BASED
	*/
	fastcin;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		// recebo one based e preciso de 0 based
		int a,b;
		cin >> a >> b;
		grafo[a].pb(b);
	}
	int root = 0;// ADICIONA A RAIZ
	bfs(root);
	buildLCA();
	cin >> q;
	for(int i=0;i<q;i++)
	{
		int a,b;
		cin >> a >> b;
		cout << queryLCA(a,b) << endl; 
	}
}
