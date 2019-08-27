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
#define MAX 202
int n,m;
int cor[MAX];
std::vector<int> grafo[MAX];
bool possible = true;

int bfs(int a)
{
	queue<int> q;
	q.push(a);
	cor[a] = 1;
	int black =0;
	int num = 0;
	while(q.size()!=0)
	{
		num++;
		int at = q.front();
		q.pop();
		if(cor[at] == 1)
			black++;
		for(int i=0;i<grafo[at].size();i++)
		{
			int next = grafo[at][i];
			if(cor[next] == 2)
			{
				q.push(next);
				cor[next] = 1 - cor[at];
			}
			else if(cor[next] == cor[at])
			{
				possible=false;
				return -1;
			}
		}
	}
	if(num == 1)
		return (1);
	else
		return min(black,num-black);
}


int main()
{	
	fastcin;
	int t;
	while(1)
	{
		possible = true;
		for(int i=0;i<MAX;i++)
		{
			grafo[i].clear();
			cor[i]=2;
		}
		cin >> n;
		if(n == 0)
			break;
		cin >> m;
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin >> a >> b;
			grafo[a].pb(b);
			grafo[b].pb(a);
		}
		int val=0;
		for(int i=0;i<n;i++)
		{
			
			if(cor[i] == 2)
				val+= bfs(i);
			if(!possible)
				break;
		}
		if(!possible)
			cout << "NOT BICOLORABLE." << endl;
		else
			cout << "BICOLORABLE." << endl;
		t--;
	}
	return 0;
}
