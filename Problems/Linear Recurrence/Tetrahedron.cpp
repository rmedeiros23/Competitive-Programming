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
#define MOD 1000000007LL 
#define REP(i,n) for (int i = 1; i <= n; i++)
const int K = 3; 
typedef vector<vector<ll int > > matrix;

matrix mat,v;

matrix mul(matrix A, matrix B)
{
    
}
matrix pow(matrix A, int p)
{
    
}


int main()
{	
	fastcin;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		vector<ll int> aux;
		for(int j=0;j<n;j++)
		{
			if(i == j)
				aux.pb(0);
			else
				aux.pb(1);
		}
		mat.pb(aux);
	}
	vector<ll int> auxv;
	auxv.pb(0);
	for(int i=1;i<n;i++)
		auxv.pb(1);
    v.pb(auxv);
    matrix resp = mul(pow(mat,n),v);
    cout << resp[0][0]%MOD << endl;
}
