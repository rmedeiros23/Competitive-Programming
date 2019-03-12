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

int n;
long double x[MAX],y[MAX];
long double query(double xfin)
{
	long double tempo = -1.0;
	for(int i=0;i<n;i++)
	{
		long double dist = (x[i]-xfin)*(x[i]-xfin) + y[i]*y[i];
		dist = sqrt(dist);
		tempo = max(dist,tempo);
	}
	return tempo;


}

int main()
{	
	fastcin;
	int t;
	cin >> n;
	while(n!=0)
	{
		for(int i=0;i<n;i++)
		{
			cin >> x[i] >> y[i];
		}
		long double l = -200005*1.0;
		long double r = 200005*1.0;
		int cont =0;
		while(cont < 400010/((1.5)*n))
		{
			long double m1,m2;
			m1 = l + ((r-l)/3.0);
			m2 = r - ((r-l)/3.0);
			//cout << "l = " << setprecision (20) << l << " r = " << setprecision (20) << r << endl;
			//cout << "m1 = " << setprecision (20) << m1 << " m2 = " << setprecision (20) <<  m2  << endl;;
			if(query(m1) < query(m2))
				r = m2;
			else
				l = m1;
			cont++;
		}
		cout << setprecision (20) << (l+r)/2.0 << " " << setprecision(20) <<  query((l+r)/2.0) << endl;
		cin >> n;
	}
	return 0;
}
