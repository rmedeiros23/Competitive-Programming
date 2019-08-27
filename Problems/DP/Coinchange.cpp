#include <vector>
#include <iostream>
#include <string.h>
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
#define MAX 300 
ll int n,dp[MAX][MAX];
vector<ll int> v;
int back(int posi,int money)
{
	if(money < 0)
		return -INF;
	if(posi == (int)v.size() and money ==0)
		return 1;
	if(posi == (int)v.size())
		return 0;
	if(dp[posi][money]!=-1)
		return dp[posi][money];
	ll int ret = max(back(posi,money-v[posi]),0) + max(back(posi+1,money),0);
	return dp[posi][money] = ret;
}
int main()
{	
	fastcin;
	int m,n;
	cin >> m >> n;
	for(int i=0;i<MAX;i++)
		for(int j=0;j<MAX;j++)
			dp[i][j] = -1;
	for(int i=0;i<n;i++)
	{
		int a;
		cin >>a;
		v.pb(a);
	}
	cout << back(0,m) << endl;
}
