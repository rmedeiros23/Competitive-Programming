#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 100000000000000000
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define MAX 5000006

ll int v[MAX];
ll int n =0;
vector<ll int > consulta;
ll int fim[MAX];
int main()
{	
	fastcin;
	ll int value;
	while(cin >> value)
	{
		v[n] = value;
		n++;
	}
	consulta.pb(-INF);
	for(int i=1;i<=n;i++)
	{
		consulta.pb(INF);
	}
	for(int i=0;i<n;i++)
	{
		auto it = lower_bound(consulta.begin(),consulta.end(),v[i]);
		int lugar = it - consulta.begin();
		consulta[lugar] = v[i];
		fim[i] = lugar;
	}
	ll int maior=-1,posi;
	for(int i=0;i<n;i++)
	{
		if(fim[i]>=maior)
		{
			maior = fim[i];
			posi = i;
		}
	}
	cout << maior << endl << "-" << endl;
	vector< ll int > resp;
	ll int last = -1;
	while(maior!=0)
	{
		resp.pb(v[posi]);
		last = v[posi];

		while(fim[posi] != maior-1 or v[posi]>=last)
		{
			if(posi == 0)
				break;
			posi--;
		}
		maior--;
	}
	for(int i=resp.size()-1;i>=0;i--)
		cout << resp[i] << endl;
	return 0;
}


