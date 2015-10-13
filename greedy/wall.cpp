#include <iostream>
#include <alorithm>
using namespace std;

struct wall
{
	int beg,end;
};

int main()
{
	int T,n,k;
	wall w[110];
	int wn[100];
	int i,j;
	cin >> T;
	while(T--)
	{
		int tmp;
		cin >> n >> k;
		for(i = 0; i < n; i++)
			cin >> w[i].beg >> tmp >> w[i].end >> tmp;
		
		memset(wn, 0, sizeof(int) * 100);
		sort(w, w + n, cmp);
		for(i = 0; i < n; i++)
			for(j = w[i].beg; j <= w[i].end; j++)
				wn[j]++;
#ifdef BUGDE
		for(i = 0; i < 100; i++)
			cout << wn[i] << endl;
#endif
		int a = 0,b = 0;
		for(i = 0; i < 100; i++)
		{
			if(wn[i] > k)
			{
				a = i;
				
			} 
		}
	}
	return 0;
}