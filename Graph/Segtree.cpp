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
#define MAX 
/*
	Segtree Implementada com arvore em vetor 
	cada nó será guardado em sua respectiva posição no vetor
	nó 2, fica no índice 2 do vetor segtree análogo para demais 
		
		1-> root
	2			3
4		5	6		7 
	seg[4*N] pois arvore terá até log(n) níveis, cada nível terá nivel anterior/2 nós - 4*n suficiente para N 10^5
	

*/
const int N = 100005; // N do problema
int seg[N*4];
int v[N];
void build(int at,int i,int j)
{
	if(i == j)
		seg[at] = v[i]; // intervalo único -> folha
	else
	{
		build(2*at,i,(i+j)/2);
		build(2*at+1,(i+j)/2+1,j); // divide o intervalo no meio, primeira parte pega metade, segunda parte pega metade + 1
		seg[at] = seg[2*at] + seg[2*at+1];
	}
}
int query(int at,int i,int j,int l, int r) // l,r = intervalo da query i,j = intervalo de busca
{
	cout << "estou no intervalo" << i << " " << j << " l = " << l << " r = " << r << endl;	 
	if(i>=l and j<=r) // casos base
	{
		cout << "intervalo completo" << seg[at] << endl; 
		return seg[at];
	}
	if(i>r or j<l)
	{
		cout << "intervalo nulo"<< endl;
		return 0;
	}
	int L = query(2*at,i,(i+j)/2,l,r);// parcialmente incluído, chama pra primeira metade e pra segunda metade
	int R = query(2*at+1,(i+j)/2+1,j,l,r);
	return L+R;
}
void update(int at,int i,int j,int pos,int val)
{
	if(pos > j or pos < i)
               return;
	if(i == j)
	{
		seg[at] = val;
		return;
	}
	
	update(at*2,i,(i+j)/2,pos,val);
	update(at*2,(i+j)/2+1,j,pos,val);
	seg[at] = seg[2*at] + seg[2*at+1];
}
int main()
{	
	fastcin;
	int n;
	cin >> n ;
	for(int i=1;i<=n;i++)
	{	
		cin >> v[i];
	}
	build(1,1,n);
	
	return 0;

}
