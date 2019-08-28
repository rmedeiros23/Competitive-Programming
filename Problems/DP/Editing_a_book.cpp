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
#define debug true
#define MAX 

vector<int> padrao,v;
set<vector<int> > freq;
int resp = INF;
int at = 0;
int n;
vector<int> corte(int l,int r,int k)
{
	vector<int> copia,ret;
	for(int i=l;i<=r;i++)
		copia.pb(v[i]);
	for(int i = 0;i<k;i++)
	{
		if(i>=l and i<=r)
			continue;// parte do intervalo não copia
		ret.pb(v[i]);
	}
	for(int i =0 ;i<copia.size();i++)
		ret.pb(copia[i]);
	for(int i = k;i<n;i++)
	{
		if(i>=l and i<=r)
			continue;// parte do intervalo não copia
		ret.pb(v[i]);
	}
	if(debug)
	{
		cout << "L = " << l << " R = " << r << endl; 
		for(int i =0 ;i<ret.size();i++)
		{
			cout << ret[i] << " ";
		}
		cout << endl;
	}
	return ret;

}
void solve()
{
	if(v == padrao)
	{
		resp = min(resp,at);
		return;
	}
	if(freq.count(v) == true)
		return;
	if(debug)
	{
		cout << "at = " << at << endl;
		for(int i=0;i<v.size();i++)
			cout << v[i] << endl;
	}
	freq.insert(v);
	vector<int> aux;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) // intervalo l,r 
		{
			for(int k = 0;k<=n;k++) // lugar do ctrl V 
			{
				if(k>=i and k<=j)
					continue; // não posso pegar pra colar em coisa que está no intervalo
				aux = v;
				at++;
				v  = corte(i,j,k); // copio intervao i,j e colo na posi k;
				solve();
				at--;
				v = aux;
			}
		}
	}
}
int main()
{	
	fastcin;
	cin >> n;
	while(n!=0)
	{
		v.clear();
		padrao.clear();
		freq.clear();
		resp = INF;
		for(int i=0;i<n;i++)
		{
			int a;
			cin >> a;
			v.pb(a);
			padrao.pb(i+1);
		}
		solve();
		cout << resp << endl;
		cin >> n;
	}

}
