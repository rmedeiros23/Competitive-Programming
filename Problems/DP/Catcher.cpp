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
#define MAX 2004 
int n,dp[MAX][MAX];
vector<int> v;
int back(int posi,int lim)
{

	int ret = -1;
	if(posi>=n)
		return 0;
	if(dp[posi][lim]!=-1)
		return dp[posi][lim];
	if(v[posi]>lim)
		ret = back(posi+1,lim);
	else
	{
		ret = max(back(posi+1,lim),back(posi+1,v[posi])+1);
	}
	return dp[posi][lim] = ret; 
}
int main()
{	
	fastcin;
	int a;
	int teste = 0;
	while(1)
	{
		int maioraq = -1;
		teste++;
		cin >> a;
		if(a == -1)
			break;
		if(teste!=0)
			cout << endl;
		v.clear();
		v.pb(a);
		maioraq = max(maioraq,a);
		while(1)
		{
			cin >> a;
			if(a == -1)
				break;
			v.pb(a);
			maioraq = max(maioraq,a);
		}
		n = v.size();
		for(int i=0;i<MAX;i++)
			for(int j=0;j<MAX;j++)
			{
				dp[i][j] = -1;
			}
		cout << "Test #" << teste << ":" << endl;
		cout <<"  maximum possible interceptions: " <<  back(0,maioraq) << endl; 
	}
}
