#include <vector>
#include <iostream>

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
#define MAX 205 
int dp[MAX][MAX];
vector<int> v[22];
int lim;
int back(int posi,int money)
{
	if(money<0)
		return -INF;
	if(posi >= lim)
		return 0;
	if(dp[posi][money]!=-1)
		return dp[posi][money];
	int ret =-INF;
	for(int i=0;i<(int)v[posi].size();i++)
	{
		ret = max(ret,back(posi+1,money-v[posi][i])+v[posi][i]); 
	}
	return dp[posi][money] = ret;
} 
int main()
{	
	fastcin;
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		for(int i=0;i<21;i++)
		v[i].clear();
		cin >> n >> m;
		swap(n,m);
		lim = n;
		for(int i=0;i<n;i++)
		{
			int c;
			cin >> c;
			for(int j=0;j<c;j++)
			{
				int a;
				cin >> a;
				v[i].pb(a);
			}
		}
		for(int i=0;i<MAX;i++)
			for(int j =0 ;j<MAX;j++)
				dp[i][j] = -1;
		int resp = back(0,m);
		if(resp>0)
			cout << resp << endl;
		else
			cout << "no solution" << endl;
	}
}
