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
#define MAX 112



int main()
{	
	fastcin;
	int n,m;
	cin >> n >> m;
	while(n!=0 or m !=0)
	{
		bool vis[MAX];
		vector<int> resp;
		std::vector<int> grafo[MAX],seq;
		for(int i=1;i<=n;i++)
		{
			vis[i] = false;
		}
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin >> a >>b;
			grafo[b].pb(a);
		}
		int cont = 0;
		while(cont<n)
		{

			for(int i=1;i<=n;i++)
			{
				//cout << "i = " << i << "e vis = " << vis[i] << " CONT = " << cont << endl;
				bool pode = true;
				if(vis[i] == false)
				{
					
					for(int j=0;j<grafo[i].size();j++)
						if(vis[grafo[i][j]]==false){
							pode = false;
						}

					if(pode)
					{
						//cout << "Visitei " << i << endl;
						vis[i]=true;
						cont++;
						seq.pb(i);
					}
				}
			}
		}
		for(int i=0;i<seq.size();i++)
			cout << seq[i] << " ";
		cout << endl;

		cin >> n >> m;
	
	}
	return 0;
}