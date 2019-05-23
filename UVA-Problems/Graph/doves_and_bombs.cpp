#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define MAX 10004
#define N 998244353


std::vector<int> grafo[MAX];
bool vis[MAX];
int tempo[MAX];
int desconexo;
int cont =0;
int pai[MAX];
int back[MAX];
int resp[MAX];
int nfilho;
int root;
void inicializa()
{
	memset(back,INF,sizeof back);
	memset(tempo,INF,sizeof tempo);
	memset(vis,false,sizeof vis);
	memset(resp,0,sizeof resp);
	for(int i=0;i<MAX;i++)
		grafo[i].clear();
	desconexo = 0;
	nfilho =0;
}

void dfs(int a)
{
	cont++;
	tempo[a]=cont;
	vis[a] = true;
	back[a] = tempo[a];
	for(int i=0;i<grafo[a].size();i++)
	{
		int next = grafo[a][i];
		if(vis[next] == true and pai[a]!=next)
		{
			back[a] = min(back[a],tempo[next]);	
		}
		else if(vis[next] == false)
		{
			if(a == root)
				nfilho++;
			pai[next] = a;
			dfs(next);
			if((back[next]) >= tempo[a])
			{
				/*if(a == 5)
				{
					cout << "Meu back = " << back[a] << " o meu filho tem " << back[next] << " Sendo meu filho " << next << endl;
				}*/
				resp[a]++;
			}
			back[a] = min(back[a],back[next]);
		}
	}
}

int main()
{	
	fastcin;

	int n,m;
	cin >> n >> m;
	while(n!=0 or m!=0)
	{
		//cout << "N = " << n << " M = " << m << endl;
		inicializa();
		int a,b;
		cin >> a >> b;
		while(a!=-1 or b!=-1)
		{
			if(a<n and b<n)
			{
				grafo[a].pb(b);
				grafo[b].pb(a);
			}
			cin >> a >> b;
		}
		for(int i=0;i<n;i++)
		{
			if(vis[i] == false)
			{
				desconexo++;
				cont=0;
				root = i;
				nfilho=0;
				dfs(i);
				resp[i] = nfilho-1;
			}
		}
		std::vector<pair <int,int > > respv;
		for(int i=0;i<n;i++)
		{
			//cout << "Resp de " << i << " é igual a " << resp[i] << endl;
			respv.pb(mp(resp[i]+desconexo,-i));
		}
		sort(respv.rbegin(),respv.rend());
		for(int i=0;i<m;i++)
			cout << -respv[i].se << " " << respv[i].fi << endl;
		cout << endl;
		cin >> n >> m;
	}
	return 0;
}
/*

4 4
0 1
0 2
1 2
1 3

11 11
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0 9
0 10
1 2
1 3
5 8
6 1
6 3
6 5
6 7
6 10
9 4
-1 -1

4 3
0 1
0 3
1 2
-1 -1

22 4
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 9
0 10
0 11
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 17
2 3
2 4
2 5
2 6
2 7
2 8
2 9
3 4
3 5
3 6
3 7
3 8
3 9
4 5
4 6
4 7
4 8
4 9
5 6
5 7
5 8
9 18
9 20
9 21
15 13
16 12
17 4
17 5
17 16
18 2
19 1
19 7
19 15
21 3
21 14
21 19
-1 -1

3 1
0 1
0 2
*/
