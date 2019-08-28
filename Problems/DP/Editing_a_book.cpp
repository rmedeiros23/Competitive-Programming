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
#define MAX 
int limite;
vector<int> padrao,v;
int resp = INF;
int at = 0;
int n;

int geth()
{
	int num = 0;
	for (int i = 0; i < n-1;++i)
	if (v[i] + 1 != v[i + 1]) num++;
	return num;
}


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
bool solve(int at)
{
	if(v == padrao)
	{
		return true;
	}
    int h = geth();
    if(at >= limite or at *3 + h > 3*limite)
        return false;
	if(debug)
	{
		cout << "at = " << at << endl;
		for(int i=0;i<v.size();i++)
			cout << v[i] << endl;
	}
	vector<int> aux;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++) // intervalo l,r 
		{
			for(int k = j+1;k<=n;k++) // lugar do ctrl V 
			{
				if(k>=i and k<=j)
					continue; // não posso pegar pra colar em coisa que está no intervalo
				aux = v;
				v  = corte(i,j,k); // copio intervao i,j e colo na posi k;
				if(solve(at + 1))
                    return true;
				v = aux;
			}
		}
	}
    return false;
}
int main()
{	
	fastcin;
	cin >> n;
    int cont = 0;
	while(n!=0)
	{
        cont++;
        cout << "Case " << cont << ": ";
		v.clear();
		padrao.clear();
		resp = INF;
		for(int i=0;i<n;i++)
		{
			int a;
			cin >> a;
			v.pb(a);
			padrao.pb(i+1);
		}
        int resp;
        for(limite =0;limite<n;limite++)
            if(solve(0))        
            {
                resp = limite;
                break;
            }
		cout << resp << endl;
		cin >> n;
	}

}
