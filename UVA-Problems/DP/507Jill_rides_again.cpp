#include <vector>
#include <iostream>
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
#define MAX 20004 



int main()
{	
	fastcin;
	int t;
	cin >> t;
	int teste= 0;
	while(t--)
	{
		teste++;
		int n;
		cin >> n;
		int arr[MAX];
		for(int i=0;i<n-1;i++)
		{
			cin >> arr[i];
		}
		int l,r;
		int maior=-INF;
		for(int i=0;i<n-1;i++)
		{
			int at = 0;
			for(int j=i;j<n-1;j++)
			{
				at+=arr[j];
				if(at>=maior)
				{
					maior = at;
					l = i;
					r = j;
				}

			}
			
		}
		if(maior<=0)
		{
			cout << "Route " << teste  << " has no nice parts" << endl;
		}
		else
			cout << "The nicest part of route " << teste << " is between stops " << l+1 << " and " << r+2 << endl;
	}
}
