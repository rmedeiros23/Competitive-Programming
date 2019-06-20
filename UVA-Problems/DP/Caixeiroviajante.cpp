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
#define MAX 2050 
int dp[MAX][405];
vector<pair<int,int> > v;
int n;
int x,y;
int trans(pair<int,int> a)
{
	int val = a.fi*x + a.se;
	return val;
}
int Cdist(int a,int b)
{
	int x1,x2,y1,y2;
	x1 = a/x;
	y1 = a%x;
	x2 = b/x;
	y2 = b%x;
	return abs(x1-x2) + abs(y1-y2);
}
int back(int vis, int last)
{
	cout << "vis = " << vis << endl;
	if(vis == (1 << n)-1)
		return 0;
	int ret = INF;
	if(dp[vis][last]!=-1)
		return dp[vis][last];
	for(int i=0;i<n;i++)
	{
		cout << "op = " << (1 << i) << " estado = "<<  !((vis >>  i)%2) << endl;
		if((vis >> i)%2 == 0)
		{
			vis += (1 << i);
			int next = trans(v[i]);
			int dist = Cdist(last,next);
			ret = min(ret,back(vis,next)+ dist);
			vis -= (1 << i);
		}
		
	}
	cout << "ret = " << ret << endl;
	return dp[vis][last] = ret;
}

int main()
{	
	fastcin;
	int t;
	cin >> t;
	while(t--)
	{
		v.clear();
		cin >> x >> y;
		int xini,yini;
		cin >> xini >> yini;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin >> a >> b;
			v.pb(mp(a,b));
		}
		for(int i=0;i<MAX;i++)
			for(int j=0;j<405;j++)
				dp[i][j] = -1;
		cout <<	back(0,trans(mp(xini,yini))) << endl;
	}

}
