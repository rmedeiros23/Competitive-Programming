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
#define MAX 102
#define CIMA 0
#define DIR 1 
#define BAIXO 2
#define ESQ 3
#define x posii
#define y posij
int dirat;
string mat[MAX];
int n,m,s;
int posii,posij;
void viradir()
{
	dirat++;
	dirat%=4;
}
void viraesq()
{
	dirat--;
	dirat+=4;
	dirat%=4;
}
void andafrente()
{
	if(dirat == CIMA and x>0 and mat[x-1][y] != '#')
		x--;
	else if(dirat == DIR and y<(m-1) and mat[x][y+1] != '#')
		y++;
	else if(dirat == BAIXO and x<(n-1) and mat[x+1][y] != '#' )
		x++;
	else if(dirat == ESQ and y>0 and mat[x][y-1] != '#')
		y--;

}

int main()
{	
	fastcin;
	cin >> n >> m >>s;
	while(n!=0 or m!=0 or s!=0)
	{
		// inicializa?
		string comando;
		for(int i=0;i<n;i++)
		{
			cin >> mat[i]; 
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(mat[i][j] == 'N')
				{
					dirat = CIMA;
					posii = i;
					posij = j; 
				}
				else if(mat[i][j] == 'L')
				{
					dirat = DIR;
					posii = i;
					posij = j;

				}
				else if(mat[i][j] == 'S')
				{
					dirat = BAIXO; 
					posii = i;
					posij = j;
				}
				else if(mat[i][j] == 'O')
				{
					dirat = ESQ; 
					posii = i;
					posij = j;
				}
			}

		int resp =0;
		cin >> comando;
		for(int i=0;i<comando.size();i++)
		{
			if(mat[posii][posij] == '*')
			{
				resp++;
				mat[posii][posij] = '.';
			}
			if(comando[i] == 'D')
				viradir();
			if(comando[i] == 'E')	
				viraesq();
			if (comando[i] == 'F')
				andafrente();
			
		}
		if(mat[posii][posij] == '*')
		{
			resp++;
			mat[posii][posij] = '.';
		}
		cout << resp << endl;
		cin >> n >> m >>s;
	}
}