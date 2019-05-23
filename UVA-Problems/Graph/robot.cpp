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
#define MAX 3000
#define north 1
#define east 2
#define west 3
#define south 4

int mat[MAX][MAX];
int n,m;
int dist[MAX][6];
queue< pair<int,int> > q;

bool pode(int val)
{
	int x,y;
	x = val/m;
	y = val%m;
	if(x>=0 and y>=0 and mat[x][y] !=1 and x+1<n and y+1 <m and mat[x+1][y]!=1 and mat[x][y+1]!=1 and mat[x+1][y+1]!=1)
		return true;
	return false;
}

void caminha(int dirat,int posiat,int muda1,int muda2)
{

	if(dist[posiat][muda1] == -1)
	{
		q.push(mp(posiat,muda1));
		dist[posiat][muda1] = dist[posiat][dirat] +1;
	}
	if(dist[posiat][muda2] == -1)
	{
		q.push(mp(posiat,muda2));
		dist[posiat][muda2] = dist[posiat][dirat] +1;
	}
}

int main()
{	
	fastcin;
	cin >> n >> m;
	while(n!=0 or m!=0)
	{
		// possivel memset na mat
		int inix,iniy,destx,desty;
		int dir;
		string dirs; 
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin >> mat[i][j];
			}
		}
		cin >> inix >> iniy >> destx >> desty;
		cin >> dirs;
		inix--;
		iniy--;
		destx--;
		desty--;
		if(dirs == "north")
			dir = 1;
		if(dirs == "east")
			dir = 2;
		if(dirs == "west")
			dir = 3;
		if(dirs == "south")
			dir = 4;

		// começo da bfs
		int posidest,posini;

		memset(dist,-1,sizeof dist);
		posini = inix*m + iniy; // transformando ponto em valor
		posidest = destx*m + desty; 
		
		while(q.size()!=0)
			q.pop();		

		if(pode(posini))
		{
			q.push(mp(posini,dir));
			dist[posini][dir] = 0;
			while(q.size()!=0)
			{
				int posiat,dirat;
				int atx,aty; // valores em coordenadas (mais facil de trabalhar)

				posiat = q.front().fi; // valor da posicao atual
				dirat = q.front().se; // valor da direcao atual
				atx = posiat/m;
				aty = posiat%m;
				q.pop();
				//cout << "Estou na posi " << atx << " " << aty;
				if(dirat == north)
				{
					//cout << " olhando para o norte" << " Distancia do inicio = " << dist[posiat][dirat] << endl;
					caminha(dirat,posiat,east,west);
					int next = posiat-m;
					if(pode(next) and dist[next][dirat]== -1) // anda mudando de lugar 
					{
						q.push(mp(next,dirat));
						dist[next][dirat] = dist[posiat][dirat] + 1;
					}
					else if (pode(next) == false)
						continue;
					next = posiat-2*m;
					if(pode(next) and  dist[next][dirat]== -1) // anda mudando de lugar 
					{
						q.push(mp(next,dirat));
						dist[next][dirat] = dist[posiat][dirat] + 1;
					}
					else if (pode(next) == false)
						continue;
					next = posiat-3*m;
					if(pode(next) and dist[next][dirat]== -1) // anda mudando de lugar 
					{
						q.push(mp(next,dirat));
						dist[next][dirat] = dist[posiat][dirat] + 1;
					}
				}
				else if(dirat == east)
				{
					//cout << " olhando para o lest (direita) " << " Distancia do inicio = " << dist[posiat][dirat] << endl;
					caminha(dirat,posiat,south,north);
					int next = posiat+1;
					if(pode(next) and dist[next][dirat]== -1) // anda mudando de lugar 
					{
						q.push(mp(next,dirat));
						dist[next][dirat] = dist[posiat][dirat] + 1;
					}
					else if (pode(next) == false) 
						continue;
					next = posiat+2;
					if(pode(next) and dist[next][dirat]== -1) // anda mudando de lugar 
					{
						q.push(mp(next,dirat));
						dist[next][dirat] = dist[posiat][dirat] + 1;
					}
					else if (pode(next) == false)
						continue;
					next = posiat+3;
					if(pode(next) and dist[next][dirat]== -1) // anda mudando de lugar 
					{
						q.push(mp(next,dirat));
						dist[next][dirat] = dist[posiat][dirat] + 1;
					}
				}
				
				else if(dirat == west)
				{
					//cout << " olhando para o oeste (esquerda)" << " Distancia do inicio = " << dist[posiat][dirat] << endl;
					caminha(dirat,posiat,south,north);
					int next = posiat-1;
					if(pode(next) and dist[next][dirat]== -1) // anda mudando de lugar 
					{
						q.push(mp(next,dirat));
						dist[next][dirat] = dist[posiat][dirat] + 1;
					}
					else if (pode(next) == false)
						continue;
					next = posiat-2;
					if(pode(next) and dist[next][dirat]== -1) // anda mudando de lugar 
					{
						q.push(mp(next,dirat));
						dist[next][dirat] = dist[posiat][dirat] + 1;
					}
					else if (pode(next) == false)
						continue;
					next = posiat-3;
					if(pode(next) and dist[next][dirat]== -1) // anda mudando de lugar 
					{
						q.push(mp(next,dirat));
						dist[next][dirat] = dist[posiat][dirat] + 1;
					}
				}
				else if(dirat == south)
				{
					//cout << " olhando para o sul" << " Distancia do inicio = " << dist[posiat][dirat] << endl;
					caminha(dirat,posiat,east,west);
					int next = posiat+m;
					if(pode(next) and dist[next][dirat]== -1) // anda mudando de lugar 
					{
						q.push(mp(next,dirat));
						dist[next][dirat] = dist[posiat][dirat] + 1;
					}
					else if (pode(next) == false)
						continue;
					next = posiat+ 2*m;
					if(pode(next) and dist[next][dirat]== -1) // anda mudando de lugar 
					{
						q.push(mp(next,dirat));
						dist[next][dirat] = dist[posiat][dirat] + 1;
					}
					else if (pode(next) == false)
						continue;
					next = posiat + 3*m;
					if(pode(next) and dist[next][dirat]== -1) // anda mudando de lugar 
					{
						q.push(mp(next,dirat));
						dist[next][dirat] = dist[posiat][dirat] + 1;
					}
				}
			}
		}
		int resp = INF;
		for(int i=1;i<=4;i++)
			if(dist[posidest][i]!=-1)
				resp = min(resp,dist[posidest][i]); 
		if(resp == INF)
			cout << -1 << endl;
		else
			cout << resp << endl;

		cin >> n >> m;
	}
}