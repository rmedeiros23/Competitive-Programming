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
#define MAX 100005

int lps[MAX];
string pattern,text;

/*
	Encontrando uma sequencia em um texto maior
	O(N)
	ABAA
	ABAA	
	lps -> precalcular para cada posição do pattern, seu maior prefixo que é igual a um sufixo
*/
void buildkmp()
{
	int size = pattern.size();
	int i=1,j=0;
	lps[0] = 0;
	while(i<size) // crio o lps
	{
		if(pattern[i] == pattern[j])
		{
			j++;
			lps[i] = j; // 
			i++;
		}
		else
		{
			if(j==0)
			{ 
				// se deu errado no primeiro caractere, não tem o que reaproveitar
				i++;
				lps[i] = 0; 
			}
			else
			{
				j = lps[j-1]; // caso já tenha alguma coisa pra reaproveitar, reaproveita
			}
			
		}
	}
}	

int searchkmp()
{
	int i=0,j=0,resp=0;
	while(i<text.size())
	{
		if(text[i] == pattern[j]) // match, logo avança ambos
		{
			i++;
			j++;
		}
		else // mismatch
		{
			if(j == 0)
				i++;
			else
				j = lps[j-1];
		}
		if(j == pattern.size()) // match completo, vai pra o prefixo de maior tamanho igual a um sufixo
		{
			resp++; // incrementa número de matchs
			j = lps[j-1];
		}
	}
	return resp;
}

int main()
{	
	fastcin;
	cin >> text;
	cin >> pattern;
	buildkmp();
	cout << searchkmp() << endl;

	return 0;
}
