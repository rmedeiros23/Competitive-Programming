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
// #define endl "\n"
#define debug false
#define MAX 1000006 

set<int> s;
int n;
ll int dp[MAX][4];
vector< ll int> v[MAX];
map<int,pair<ll int, ll int> > menor,maior;
ll int back(int posi, int t) // t = teste , 0 = maior1 maior2 , 1 = maior1 menor1 2 = menor1 maior1 3 = menor1 menor2
{
    if(posi == s.size())
        return 0;
    if(dp[posi][t] != -1)
        return dp[posi][t];
    ll int op1,op2,op3,op4; 
    ll int valat;
    if(t == 0)
        valat = maior[posi].se;
    else if(t ==1)
        valat = menor[posi].fi;
    else if ( t == 2)
        valat = maior[posi].fi;
    else
        valat = menor[posi].se;
    op1 = back(posi+1,0) + abs(maior[posi+1].fi - valat);
    op2 = back(posi+1,1) + abs(maior[posi+1].fi - valat);
    op3 = back(posi+1,2) + abs(menor[posi+1].fi - valat);
    op4 = back(posi+1,3) + abs(menor[posi+1].fi - valat);

    ll int respat = max(op1,max(op2,max(op3,op4)));
    cout << "posi = " << posi << " t= " << t << "respat = " << respat << endl;
    return dp[posi][t] = max(op1,max(op2,max(op3,op4)));
}
int main()
{	
	fastcin;
    cin >> n;
    for(int i=0;i<MAX;i++)
        for(int j=0;j<4;j++)
            dp[i][j] = -1;
            cout << endl;
    map<int,int> troca;
    for(int i=0;i<n;i++)
    {
        int id,p;
        cin >> id >> p;
        if(s.count(id) == true)
            id = troca[id];
        else
        {
            s.insert(id);
            troca[id] = s.size()-1; 
            id = troca[id];
        }
        v[id].pb(p);
    }
    for(int i=0;i<n;i++)
        sort(v[i].begin(),v[i].end());
    for(int i=0;i<s.size();i++)
    {
        if(v[i].size() == 1)
        {
            menor[i] = mp(v[i][0],v[i][0]);
            maior[i] = mp(v[i][0],v[i][0]);
        }
        else
        {
            int last = v[i].size()-1;
            maior[i] = mp(v[i][last],v[i][last-1]);
            menor[i] = mp(v[i][0],v[i][1]);
        }
    }
    ll int resp= -1;
    resp = max(back(0,0),max(back(0,1),max(back(0,2),back(0,3))));
    cout << resp << endl;


}