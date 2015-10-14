#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

#define WIDTH 100
struct wall
{
	int beg;
	int end;
};

struct cmp
{
	bool operator()(const wall &a, const wall &b)const
	{
		if(a.end == b.end)
			return a.beg < b.beg;
		else
			return a.end > b.end;
	}
};

int main()
{
	int T,n,k;
	multiset<wall,cmp> wset;
	int wn[WIDTH];
	cin >> T;
	while(T--)
	{
		wall tmp;
		int i,j,val;
		int cnt = 0;
		memset(wn,0,sizeof(int) * 100);
		
		cin >> n >> k;
		for(i = 0; i < n; i++)
		{
			cin >> tmp.beg >> val >> tmp.end >> val;
			if(tmp.beg > tmp.end)
			{
				val = tmp.beg;
				tmp.beg = tmp.end;
				tmp.end = val;
			}
			wset.insert(tmp);
			for(j = tmp.beg; j <= tmp.end; j++)
				wn[j]++;
		}
		for(i = 0; i < WIDTH; i++)
		{
			cout << wn[i] << endl;
		}
		
		for(i = 0; i < WIDTH; i++)
		{
			while(wn[i] > k)
			{
				multiset<wall,cmp>::iterator iter = wset.begin();
				while(iter != wset.end())
				{
					if(iter->beg <= i)
					{
						cout << iter->beg << " " << iter->end << endl;
						for(int s = iter->beg; s <= iter->end; s++)
							wn[s]--;
						wset.erase(iter);
						cnt++;
						break;
					}
					iter++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}