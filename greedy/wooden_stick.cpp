#include <iostream>
#include <algorithm>
using namespace std;

struct stick
{
	int l,w;
	bool vis;
}s[5100];

bool cmp(stick a, stick b)
{
	if(a.l == b.l)
		return a.w > b.w;
	
	return a.l > b.l;
}

int main()
{
	int T,n;
	int i,j;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(i = 0; i < n; i++)
		{
			cin >> s[i].l >> s[i].w ;
			s[i].vis = false;
		}
		sort(s, s + n, cmp);	
		
		int ret = 0;
		int wei;
		for(i = 0; i < n; i++)
		{
			if(s[i].vis) 
				continue;
				
			wei = s[i].w;
//			s[i].vis = true;
			for(j = i + 1; j < n; j++)
			{
				if(!s[j].vis && s[j].w <= wei) 
				{
					wei = s[j].w;
					s[j].vis = true;
				}
			}
			ret++;
		}
		cout << ret << endl; 
	}
}
