#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
#define endl "\n"
#define debug false
#define MAX 500005 

ll int sm[1003][1003];
ll int v[MAX];
void upd(int posi, int add)
{
	for(int i = 1;i<=800;i++)
		sm[i][posi%i]-=v[posi];
	v[posi]+=add;
	for(int i = 1;i<=800;i++)
		sm[i][posi%i]+=v[posi];
	return;
	
}
ll int solve_big(int m, int x)
{
	ll int resp =0 ;
	int busco = x;
	if(busco == 0)
		busco+=m;
	while(busco <= MAX-5)
	{
		resp+=v[busco];
		busco+=m;
	}
	return resp;

}
ll int solve_small(int m,int x)
{
	return sm[m][x];
}

int main()
{	
	fastcin;
	int q;
	cin >> q;
	while(q--)
	{
		int op,x,y;
		cin >> op >> x >> y;
		if(op == 1)
		{
			upd(x,y);
		}
		else
		{
			if(x>=800)
				cout << solve_big(x,y) << endl;
			else
				cout << solve_small(x,y) << endl;
		}
	}
}
