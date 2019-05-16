#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
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
#define MAX 100005

vector<tuple<int,int,int> > grafo;
int pai[MAX];

int f(int i)
{	
	if(i == pai[i]) // achou o lider
		return i;
	return pai[i] = f(pai[i]);
} 
bool unir(int a,int b)
{
	a = f(a);
	b = f(b); // vamos lidar com os lideres dos grupos
	if(a == b) // já pertencem ao mesmo grupo
		return false;
	pai[a]= b;
	return true;
}
int kruskal()
{
	sort(grafo.begin(),grafo.end());
	int mst = 0;
	for(int i=0;i<(int)grafo.size();i++)
	{
		int peso,a,b;
		tie(peso,a,b) = grafo[i];
		if(unir(a,b))
			mst+=peso;

	}
	return mst;
}

int main()
{	
	fastcin;	

}



