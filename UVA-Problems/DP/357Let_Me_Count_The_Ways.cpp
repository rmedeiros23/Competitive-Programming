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
#define MAX 30004
long long int dp[10][MAX];
int v[10],n=5;

ll int solve(ll int quant,int posi)
{
	//cout << "posi = " << posi << " quant = " << quant << endl;
	if (quant == 0)
		return 1;
	if(posi == n or quant<0)
		return 0;
	if(dp[posi][quant]!=-1)
		return dp[posi][quant];
	if(quant-v[posi] >= 0)
		dp[posi][quant]= solve(quant-v[posi],posi) + solve(quant,posi+1);
	else
		dp[posi][quant] = solve(quant,posi+1);
	return dp[posi][quant];
}


int main()
{	
	v[0] = 1;
	v[1] = 5;
	v[2] = 10;
	v[3] = 25;
	v[4] = 50;
	fastcin;
	int a;
	for(int i=0;i<10;i++)
		for(int j=0;j<MAX;j++)
			dp[i][j]=-1;
	while(cin >> a)
	{
		ll int resp;
		resp = solve(a,0);
		if(resp>1)
			cout << "There are " << resp << " ways to produce " << a << " cents change." << endl;
		else
			cout << "There is only " << resp << " way to produce " << a << " cents change." << endl;
	}

}