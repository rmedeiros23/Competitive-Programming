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
#define MAX 1003 
ll int n,dp[MAX][MAX];
vector<pair<ll int,int >> v;
int back(int posi,int space)
{
	if(space<0)
		return -INF;
	if(posi == (int)v.size())
		return 0;
	if(dp[posi][space]!=-1)
		return dp[posi][space];
	int op = -1;
	op = max(back(posi+1,space),back(posi+1,space-v[posi].fi)+v[posi].se);
	return dp[posi][space] = op;
	
}
int main()
{	
	fastcin;
	int t;
	cin >> t;
	while(t--)
	{
		v.clear();
		for(int i=0;i<MAX;i++)
			for(int j=0;j<MAX;j++)
				dp[i][j] = -1;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin >>a >> b;
			v.pb(mp(b,a));
					
		}
		int m;
		ll int resp =0;
		cin >> m;
		for(int i=0;i<m;i++)
		{
			int at ;
			cin >> at;
			resp+=back(0,at);
		}
		cout << resp << endl;
	}
}
