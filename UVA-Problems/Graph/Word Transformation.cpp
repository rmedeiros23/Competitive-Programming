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
#define endl "\n"
#define MAX

int main()
{	
	fastcin;
	int  t;
	cin >> t;
	while(t!=0)
	{
		map<string,bool>dic; 
		string s;
		while((cin >> s))
		{
			if(s == "*")
				break;
			dic[s] = true;
		}
		cin.ignore();
		string line;
        while (getline(cin, line) && line != "")
        {
        	map<string,bool>vis;
        	map<string,int>dist;
			queue <string> q;
            string ini,fim;
            stringstream ss(line);
			
			ss >> ini >> fim;
			vis[ini] = true;
			q.push(ini);
			dist[ini] = 0;

			while(q.size()!=0)
			{
				string at = q.front();
				q.pop();
				//cout << "At = " << at << " dist = " << dist[at] << endl;
				if(at == fim)
					break;
				for(int j=0;j<at.size();j++)
				{
					for(char i = 'a';i<='z';i++)
					{
						string aux;
						for(int z=0;z<j;z++)
							aux.pb(at[z]);
						
						aux.pb(i);

						for(int z=j+1;z<at.size();z++)
							aux.pb(at[z]);

						if(dic.count(aux) == true and vis.count(aux) == false)
						{
							q.push(aux);
							vis[aux] = true;
							//cout << "dist[at] = " << dist[at] << " somando 1 fica " << dist[at] + 1 << endl;
							dist[aux] = dist[at]+1;
							//cout << "prox = " << aux << " dist = " << dist[aux];
						}
					}
				}
				//cout << endl << endl;
			}
			cout << ini << " " << fim << " " << dist[fim] << endl;
		}
		t--;
		if(t)
			cout << endl;
	}
	
}