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
#define MAX 205


int dp[MAX][15][22];
int num[MAX];
int n,q,m,d;
int solve(int posi,int pegou,int resto)
{
	if(pegou == m)
	{
		if(resto==0)
			return 1;
		return 0;
	}
	if(posi == n)
		return 0;
	if(dp[posi][pegou][resto]!=-1)
		return dp[posi][pegou][resto];
	return dp[posi][pegou][resto] = solve(posi+1,pegou,resto) + solve(posi+1,pegou+1,((resto%d + num[posi]%d)%d + d)%d);
}


int main()
{	
	fastcin;
	cin >> n >> q;
	int casog=1;
	while(n!=0 or q!=0)
	{
		cout << "SET " << casog << ":" << endl;

		for(int i=0;i<n;i++)
			cin >> num[i];
		for(int i=0;i<q;i++)
		{
			memset(dp,-1, sizeof dp);
			cin >> d >> m;
			cout << "QUERY " << i+1 << ": " << solve(0,0,0) << endl;
		}
		cin >> n >> q;
		casog++;
	}
	return 0;
}
