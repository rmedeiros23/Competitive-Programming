#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
#define endl "\n"
#define debug false
#define MAX 100005 
// PREISA SER CRIADO MAS COMO? map<int,int> resolvido[MAX];
map<int,vector<int> > grafo[MAX];
int quantc[MAX];
int pai[MAX];
vector<int> bigcor;
vector< <pair<int,int> > edge[MAX];
vector<int> cores[MAX]; // pra cade elemento fala as cores ao qual pertence
int f(int i,int cor)
{	
	if(i == pai[cor][i]) // achou o lider
		return i;
	return pai[cor][i] = f(pai[cor][i]);
} 
bool unir(int a,int b,int cor)
{
	a = f(a,cor);
	b = f(b,cor); // vamos lidar com os lideres dos grupos
	if(a == b) // já pertencem ao mesmo grupo
		return false;
	pai[cor][a]= b;
	return true;
}
void precalc_big() // para cada cor com + de 300 nós precalcula os elementos na mesma componente
{
	int auxcont =0;
	while(auxcont<n)
	{
		if(quant[auxcont]<300)
		{
			auxcont++;
			continue;
		}
		for(int i=0;i<edge[auxcont].size();i++)
		{
			pair<int,int> at = edge[auxcont][i];
			unir(at.fi,at.se,auxcont);
		}
		auxcont++;
	}
	return;
}
int solve_big(int a,int b,int corat)
{
	a = f(a,corat);
	b = f(b,corat);
	if(a == b)
		return 1;
	return 0;
}

int solve_small(int a,int corat)
{

}
int main()
{	
	fastcin;
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			pai[i][j] = i; // inicialmente todo mundo é seu próprio lider 
	int n,m,q;
	cin >> n >> m;
	set<int> nosexistem;
	for(int i =0 ;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		quant[c]++;	
		edge[c].pb(mp(a,b));
		grafo[c][a].pb(b);
		grafo[c][b].pb(a);
		nosexistem.insert(a);
		nosexistem.insert(b);
		cores[a].pb(c);
		cores[b].pb(c);
	}
	for(auto it : nosexistem)
	{
		int at = it;
		unique(cores[a].begin(),cores[a].end());// 
	}
	for(int i=0;i<MAX;i++)
		if(quant[i] > 300)
			bigcor.pb(i);
	solve_big();
	cin >> q;
	/*
		Small -> quando rodar uma com U, todos small do  U ficam salvas,precisa separar as cores em tamanho
		assim na query que tem u, as respostas do small já estão prontas e são adicionadas em resp

		Big -> só acessa o union find na hora O(alfa)
	*/
	while(q--) // melhor offline? ou só armazenar as respostas resolve?
	{
		int resp =0;
		int u,v;
		cin >> u >> v;
		if(cores[v].size()>cores[u].size())
			swap(u,v);
		for(int i=0;i<cores[u].size();i++) // percorre todas as cores que o elemento u tem
		{
		
		}

		cout << resp << endl;
			
	}
}
