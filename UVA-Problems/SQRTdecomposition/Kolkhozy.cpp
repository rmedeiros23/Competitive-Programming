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
#define MAX 50004 
 
int n,q;
int k[MAX];
vector<int> big[MAX];
vector<int> small[305][305];
void preprocess_big()
{
    for(int i=0;i<n;i++)
    {
        big[k[i]].pb(i); // valores de k[i] 
    }
}
int solve_big(int l,int r,int x,int m)
{
    l--;
    r--;
   // quero achar x, x+m, x+2m ... enquanto x+i*m < 
   int busco = x;
   int resp =0;
   while(1) 
   {
       if(busco>MAX)
            break;
       resp+= upper_bound(big[busco].begin(),big[busco].end(),r)  - lower_bound(big[busco].begin(),big[busco].end(),l);
       busco+=m;
   }
   return resp;
}
void preprocess_small(int n)
{
   for(int i=0;i<n;i++)
   {
       for(int j = 1;j<=300;j++)
       {
           small[j][k[i]%j].pb(i);
       }
   } 
}
int solve_small(int l,int r,int x, int m)
{
    l--;
    r--;
    if(debug)
    {
        cout << "l = " << l << "r = " << r << " x = " << x << " m = " << m << endl;
        for(int i=0;i<small[m][x].size();i++)
            cout << small[m][x][i] << " ";
         cout << endl;
    }
  int resp = upper_bound(small[m][x].begin(),small[m][x].end(),r)  - lower_bound(small[m][x].begin(),small[m][x].end(),l);
  return resp;
 
}
int main()
{	
	fastcin;
    cin >> n >> q;
    for(int i=0;i<n;i++)
        cin >> k[i];
    preprocess_big();
    preprocess_small(n);
    while(q--)
    {
        int x,m;
        int l,r;
        cin >> l >> r >> x >> m;
        if(m >= 300)
        {
            cout << solve_big(l,r,x,m) << endl;
        }
        else
        {
            cout << solve_small(l,r,x,m) << endl;
        }
    }
}
