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

int main()
{	
	fastcin;	
	for(int i=0;i<MAX;i++)
		pai[i] = i; // inicialmente todo mundo é seu próprio lider 
}



