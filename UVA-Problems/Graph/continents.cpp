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
#define MAXT 500
#define aquiei cout << "aqui!" << endl;
vector<int> grafo[MAXT];
int posirei;
bool vis[MAXT];
int ansat=0;
bool posatual =false;
int reix,reiy;
int n,m;
string mat[30];
void dfs(int at,bool vis[],std::vector<int> grafo[])
{
	//cout << "entrei e at = " << at << endl;
	vis[at] = true;
	int xx = at/m;
	int yy = at%m;
	//cout << "aqui x = "  << xx << " y = " << yy << " o char e " << mat[xx][yy] << endl;
	ansat++;
	if(at == posirei)
		posatual=true;
	for(int i=0;i<grafo[at].size();i++)
	{
		//cout << "ligação com " << grafo[at][i] << endl;
		if(vis[grafo[at][i]] == false)
			dfs(grafo[at][i],vis,grafo);
	}
}


int main()
{	
	fastcin;
	int casos=0;
	while((cin>>n) and (cin>>m))
	{	
		bool ja= posatual;
		posatual= false;
		casos++;
		int resp=0;
		char land;
		for(int i=0;i<n;i++)
		{
			cin >> mat[i];
		}
		cin >> reix >> reiy;
		posirei = reix*m + reiy;

		
		land = mat[reix][reiy];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(mat[i][j] == land)
				{
					//cout << "No ponto " << i << " " << j << endl;
					if(i!=0 and mat[(i-1+n)%n][j] == land)
					{	
						grafo[i*m+j].pb(((i-1+n)%n)*m+j);
						//cout << "crio laço com " << (i-1+n)%n << " " << j << " 1num = " << ((i-1+n)%n)*m+j << endl ;	
					}
					
					if(i!=n-1 and mat[(i+1+n)%n][j]== land)
					{
						grafo[i*m+j].pb(((i+1+n)%n)*m+j);
						//cout << "crio laço com " << (i+1+n)%n << " " << j << " 2num = " << ((i+1+n)%n)*m+j << endl ;	
					}

					if(mat[i][(j-1+m)%m]== land)
					{
						grafo[i*m+j].pb((i)*m+((j-1+m)%m));
						//cout << "crio laço com " << i << " " << (j-1+m)%m <<  " 3num = " << (i)*m+((j-1+m)%m) << endl ;	
					}

					if(mat[i][(j+1+m)%m]== land)
					{
						//cout << "crio laço com " << i << " " << (j+1+m)%m << " 4num = " << (i)*m+((j+1+m)%m) << endl ;	
						grafo[i*m+j].pb((i)*m+((j+1+m)%m));
					}

				}
			}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int at = i*m + j;
				if(mat[i][j] == land and vis[at] == false)
				{

					dfs(at,vis,grafo);
					//cout << "i = " << i << " j = " << j << endl << "Valor = " << ansat << endl;
					if(ja==false and posatual == true)
					{
						ja = true;
						ansat=0;
						continue;
					}
					resp = max(resp,ansat);
					//cout << "resp = " << resp << endl;
					ansat=0;
				}
			}
		}
		for(int i=0;i<=20;i++)
		{
			for(int j=0;j<=20;j++)
			{
				int at = i*n + j;
				grafo[at].clear();
				vis[at] = false;
			}
			mat[i].clear();
		}
		ja = false;
		posatual = false;
		ansat=0;
		ja = false;

		cout << resp << endl;
	}
	return 0;
}