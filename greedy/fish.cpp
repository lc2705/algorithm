#include <iostream>
#include <map>

using namespace std;

int main(）
{
	int h,n;
	int fi[30], di[30], ti[30],cnt[30],fish;
	int i,j;

	multimap<int,int> lack;
	while(1)
	{
		cin >> n;
		if(n == 0) break;
		cin >> h;
		lack.erase();

		for(i = 0; i < n; i++)
		{
			cin >> fi[i];
			cnt[i] = 0;
			lack.insert( make_pair(fi[i],i) );
		}
		for(i = 0; i < n; i++)
			cin >> di[i];
		int tsum = 0;
		for(i = 0; i < n-1; i++)
		{
			cin >> ti[i];
			tsum += ti[i];
		}

		fish = 0;
		multimap<int>::reverse_iterator iter;
		int index;
		
		h = h * 12 - tsum;
		while(h > 0)
		{
			iter = lack.rbegin();
			index = iter->second;
			cnt[index]++;
			fi[index] = (fi[index] - di[index] > 0) ? fi[index] - id[index] : 0;
			
			lack.erase(iter);
			if(fi[index])
				lack.insert(make_pair(fi[index],index));
			h--;
		}

		for(i = n - 2; i >= 0; i--)
		{
			int tadd = ti[i] + cnt[i];
			while(tadd > 0)
			{
				iter = lack.rbegin();
				tadd--;
			}
		}

	}

	return 0;
}
