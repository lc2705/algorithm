#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define MAX 100010

struct node
{
	int attack;
	int defence;
}me[MAX],enemy[MAX];

bool cmp_attack(node a, node b)
{
	return a.attack > b.attack;
}
bool cmp_defence(node a, node b)
{
	return a.defence > b.defence;
}

int main()
{
	int T,n,m;
	int i,j,k = 1;
	int ret;
	cin >> T;
	multiset<int> meset;
	multiset<int>::iterator sele;
	while(k <= T)
	{
		cin >> n >> m;
		for(i = 0; i < n; i++)
			cin >> me[i].attack >> me[i].defence;
		for(i = 0; i < m; i++)
	 		cin >> enemy[i].attack >> enemy[i].defence;
		sort(me, me + n, cmp_attack);
		sort(enemy, enemy + m, cmp_defence);
		
		ret = j = 0;
		meset.clear();
		for(i = 0; i < m; i++)
		{
			for( ; j < n && enemy[i].defence <= me[j].attack; j++)
				meset.insert(me[j].defence);
			if(meset.empty())
			{
				ret = n + 1;
				break;
			}
			
			sele = meset.upper_bound(enemy[i].attack);
			if(sele == meset.end())
			{
				ret++;
				sele = meset.begin(); 
			}
			meset.erase(sele);
		}
		cout << "Case #" << k << ": " << n - ret << endl;
		k++;
	}
	
	return 0;
}