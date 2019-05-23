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
#define MAX 102
#define N 998244353


bool vis[MAX];
vector<int>grafo[MAX];
vector<pair <int,int > > liga;
set<pair < int,int > >foi;


void inicializa()
{
	foi.clear();
	liga.clear();
	for(int i=0;i<MAX;i++)
		grafo[i].clear();
}

void dfs(int a)
{
	vis[a] = true;
	for(int i=0;i<grafo[a].size();i++)
	{
		if(grafo[a][i]!=-1 and vis[grafo[a][i]] == false)
			dfs(grafo[a][i]);
	}
}

int main()
{	
	fastcin;
	int n;
	while((cin>>n))
	{
	
		inicializa();
		std::vector<pair <int,int > > respv;
		for(int i=0;i<n;i++)
		{
			int at;
			cin >> at;
			char part1,part2;
			int numdest;
			cin >> part1 >> numdest >> part2;
			for(int j=0;j<numdest;j++)
			{
				int a;
				cin >> a;
				grafo[at].pb(a);
				if(foi.count(mp(a,at)) == false and foi.count(mp(at,a)) == false)
				{	
					liga.pb(mp(a,at));
					foi.insert(mp(a,at));
				}
			}
		}
		for(int i=0;i<liga.size();i++) // faz uma dfs para cada liga
		{
			int ini = liga[i].fi;
			int dest = liga[i].se;
			int posi1,posi2;
			int quant1=0,quant2=0;
			memset(vis,0,sizeof vis);
			dfs(ini);
			for(int i=0;i<n;i++)
				if(vis[i]!=0)
					quant1++;
			memset(vis,0,sizeof vis);
			for(int j=0;j<grafo[ini].size();j++)
			{
				if(grafo[ini][j] == dest)
				{
					posi1 = j;
					grafo[ini][j] = -1;
				}
			}
			for(int j=0;j<grafo[dest].size();j++)
			{
				if(grafo[dest][j] == ini)
				{
					posi2 = j;
					grafo[dest][j] = -1;
				}
			}
			dfs(ini);
			for(int i=0;i<n;i++)
				if(vis[i]!=0)
					quant2++;
			if(quant1!=quant2)
			{
				if(ini<dest)
					respv.pb(mp(ini,dest));
				else
					respv.pb(mp(dest,ini));
			}
			grafo[ini][posi1] = dest;
			grafo[dest][posi2] = ini;
		}
		sort(respv.begin(),respv.end());
		cout << respv.size() <<  " critical links" << endl;
		for(int i=0;i<respv.size();i++)
			cout << respv[i].fi << " - " << respv[i].se << endl;
		cout << endl;
	}
	return 0;
}
/*
8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)
*/
