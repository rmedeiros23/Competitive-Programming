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
#define MAX 1003
#define MAX2 1000006
int n,m;
int matriz[MAX][MAX];
int custo[MAX][MAX];
int calc(int x, int y)
{
	return x*m + y;
}
pair<int,int> volta(int val)
{
	int aux = val/m;
	return mp(aux,val%m);
}

void dji()
{
	priority_queue<pair<int,int > >pq;
	custo[0][0] = matriz[0][0];
	pq.push(mp(-custo[0][0],calc(0,0)));

	while(pq.size()!=0)
	{
		int custoat = -pq.top().first;
		int posi = pq.top().se;
		int posix = volta(posi).fi;
		int posiy = volta(posi).se;
		pq.pop();
		if(posix==n-1 and posiy == m-1)
			return ;
			int nextx,nexty;
			nextx = posix-1;
			nexty = posiy;
			if(nextx < n and nextx >=0 and nexty <m and nexty >=0 and custo[nextx][nexty]==INF)
			{
				pq.push(mp(-(matriz[nextx][nexty]+custoat),calc(nextx,nexty)));
				custo[nextx][nexty] = matriz[nextx][nexty] + custoat;
			}
			nextx = posix+1;
			nexty = posiy;
			if(nextx < n and nextx >=0 and nexty <m and nexty >=0 and custo[nextx][nexty]==INF)
			{
				pq.push(mp(-(matriz[nextx][nexty]+custoat),calc(nextx,nexty)));
				custo[nextx][nexty] = matriz[nextx][nexty] + custoat;
			}
			nextx = posix;
			nexty = posiy-1;
			if(nextx < n and nextx >=0 and nexty <m and nexty >=0 and custo[nextx][nexty]==INF)
			{
				pq.push(mp(-(matriz[nextx][nexty]+custoat),calc(nextx,nexty)));
				custo[nextx][nexty] = matriz[nextx][nexty] + custoat;
			}
			nextx = posix;
			nexty = posiy+1;
			if(nextx < n and nextx >=0 and nexty <m and nexty >=0 and custo[nextx][nexty]==INF)
			{
				pq.push(mp(-(matriz[nextx][nexty]+custoat),calc(nextx,nexty)));
				custo[nextx][nexty] = matriz[nextx][nexty] + custoat;
			}
	}

}
int main()
{	
	fastcin;
	int t;
	cin >> t;
	while(t>0)
	{
		cin >> n >> m;
		memset(matriz,0,sizeof matriz);
		memset(custo,INF,sizeof custo);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cin >> matriz[i][j];
		}
		dji();
		cout << custo[n-1][m-1] << endl;
		t--;
	}
	
	

	return 0;
}

