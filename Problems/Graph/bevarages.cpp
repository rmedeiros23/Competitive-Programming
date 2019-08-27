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
#define MAX 110
#define aquiei  cout << "Aqui" << endl;
int main(void)
{	
	fastcin;
	int n;
	int caso = 1;
	while(cin >> n)
	{
		int m;
		map<string,int> ida;
		map<int,string> volta;
		vector<int> resp;
		vector<int> grafo[MAX];
		bool vis[MAX];
		for(int i=0;i<MAX;i++)
			vis[i]=false;
		int posi=0;

		for(int i=0;i<n;i++)
		{
			string a;
			cin >> a;
			ida[a] = posi;
			volta[posi] = a;
			posi++;
		}
		cin >> m;
		for(int i=0;i<m;i++)
		{
			string a,b;
			cin >> a >> b;
			int aa,bb;
			aa = ida[a];
			bb = ida[b];
			grafo[bb].pb(aa);
		}
		int foi =0;
		int rodadas = 0;
		while(rodadas<n)
		{
			
			vector<int> vez;
			for(int i=0;i<n;i++)
			{
				if(vis[i]==false)
				{

					bool da = true;
					for(int j=0;j<grafo[i].size();j++)
					{
						if(vis[grafo[i][j]]== false)
						{
							da = false;
						}
					}
					if(da)
					{
						vez.pb(i);
					}
				}
			}
			//cout << "rodada = " << rodadas << endl << "livres: ";
			sort(vez.begin(),vez.end());
			for(int i=0;i<1;i++)
			{
				//cout << volta[vez[i]] << " ";
				vis[vez[i]]= true;
				resp.pb(vez[i]);
			}
			//cout << endl;
			rodadas++;
		}
		cout << "Case #" << caso << ": Dilbert should drink beverages in this order: ";
		for(int i=0;i<n-1;i++)
			cout << volta[resp[i]] << " ";
		cout << volta[resp[n-1]] << "." << endl << endl;
		caso++;
	}

	return 0;
}