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
#define MAXTOT 400
#define aquiei  cout << "Aqui" << endl;

map<char,int> ida;
map<int,char> volta;
vector<int> resp;
vector<int> grafo[MAXTOT];
vector<char> respfin[MAXTOT];
int quantans;
bool vis[MAXTOT];
int n;
void dfs(int posi)
{
	if(posi == n)
	{
		for(int i=0;i<n;i++)
		{
			char inu = volta[resp[i]];
			respfin[quantans].pb(inu);
		}
		quantans++;
		return;
	}

	for(int i=0;i<n;i++)
	{
		if(vis[i]==false)
		{
			bool deu = true;
			for(int j=0;j<grafo[i].size();j++)
			{
				int next =grafo[i][j];
				if(vis[next] == false)
					deu = false;
			}
			if(deu)
			{
				resp.pb(i);
				vis[i]=true;
				dfs(posi+1);
				vis[i]=false;
				resp.pop_back();
			}
		}
	}
}

void inicialize()
{
	for(int i=0;i<MAXTOT;i++)
	{
		respfin[i].clear();
		grafo[i].clear();
		vis[i]=false;
	}
	ida.clear();
	volta.clear();
	resp.clear();
	n=0;
	quantans = 0;
	return ;
}
int main(void)
{	
	int conta;
	int caso = 1;
	cin>>conta;
	getchar();
	while(caso<=conta)
	{
		
		inicialize();
		int posi = 0;
		string line;
		vector<char> aux,aux2;
		char at;
		getchar();
		getline(cin,line);
		stringstream ss(line);
		
		while(ss>>at)
			aux.pb(at);
		for(int i=0;i<aux.size();i++)
		{
			ida[aux[i]]=posi;
			volta[posi]=aux[i];
			posi++;
		}
		n = aux.size();
		getline(cin,line);
		stringstream ss2(line);
		while(ss2>>at)
		{
			aux2.pb(at);
		}
		for(int i=0;i<aux2.size();i+=3)
		{
			int a = ida[aux2[i]];
			int b = ida[aux2[i+2]];
			grafo[b].pb(a);
		}
		dfs(0);
		if(quantans == 0)
			cout << "NO" << endl;
		else
		{
			//aquiei;
			for(int i=0;i<quantans;i++)
			{
				//aquiei
				for(int j=i+1;j<quantans;j++) // buble normal
				{
					//cout<< "tam i = " << respfin[i].size() << endl;

					//cout<< "tam j = " << respfin[j].size() << endl;

					int desempate = 0;
					for(int z=0;z<n;z++)
					{
						//aquiei;
						if(respfin[i][z] < respfin[j][z])
						{
							desempate = 1;
							break;
						}
						else if(respfin[i][z] > respfin[j][z])
						{
							desempate = -1;
							break;
						}
					}
					//aquiei;
					if(desempate == -1)
					{
						std::vector<char> auxc;
						for(int z=0;z<n;z++)
							auxc.pb(respfin[i][z]);
						for(int z=0;z<n;z++)
							respfin[i][z]=respfin[j][z];
						for(int z=0;z<n;z++)
							respfin[j][z]=auxc[z];
					}
				}
			}
			//cout << "quant = " << quantans << endl;
			for(int i=0;i<quantans;i++)
			{
				//cout << "entrou" << endl;
				for(int j=0;j<respfin[i].size();j++)
				{
					cout << respfin[i][j];
					if(j!=respfin[i].size()-1)
						cout << " ";
					else
						cout << endl;
				}	
				
			}
		}
		//cout << "caso = " << caso << " conta = " << conta << endl;
		if(caso != (conta) )
			cout << endl;
		caso++;
	}

	return 0;
}