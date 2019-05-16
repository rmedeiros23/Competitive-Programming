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
#define MAX 50005


long double query(double xfin)
{

}
long double ternary()
{
	long double l = -200005*1.0;
	long double r = 200005*1.0;
	int cont =0;
	while(cont < 400005)
	{
		long double m1,m2;
		m1 = l + ((r-l)/3.0);
		m2 = r - ((r-l)/3.0);
		if(query(m1) < query(m2))
			r = m2;
		else
			l = m1;
		cont++;
	}
	return (r+l)/2.0;
}

int main()
{	
	fastcin;

	return 0;
}
