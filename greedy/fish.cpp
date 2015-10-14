#include <iostream>
using namespace std;
int findIndexOfMax(int *a,int n);

int main()
{
	int h,n;
	int fi[30], di[30], ti[30],cnt[30],fish[30];
	int fishSum,lacknum;
	int i,j;

	cin >> n;
	while(n)
	{
		cin >> h;
		for(i = 0; i < n; i++)
		{
			cin >> fi[i];
		}
		for(i = 0; i < n; i++)
		{
			cin >> di[i];
			cnt[i] = 0;
			fish[i] = 0; 
		}
		
		int tsum = 0;
		for(i = 0; i < n-1; i++)
		{
			cin >> ti[i];
		}
		ti[i] = 0;
		
		fishSum = 0;	
		int index;
		h = h * 12;
		i = 0;
		while(i < n)
		{
			if(h < ti[i])
			{
				i++;
				break;
			}
			h -= ti[i];
			i++;
		}
		lacknum = i;
	
		while(h > 0)
		{
			index = findIndexOfMax(fi, lacknum);
			if(fi[index] == 0)
				break;
			fish[index] += fi[index];
			cnt[index]++;
#ifdef DEGUBB
			cout << "h :" << h <<endl;
			cout << "index:" << index << " fi:" << fi[index] << " cnt:" << cnt[index] <<endl;	
#endif
			fi[index] -= di[index];
			if(fi[index] < 0) 
				fi[index] = 0;		
			h--;
		}
		
		cnt[0] += h;
		int tadd;
		int addfish = 0;
		int addfishmax = 0;
		int addcnt[30] = {0};
		int addcnt_tmp[30] = {0};
		int lacknum_tmp = lacknum;
		for(i = lacknum - 2; i >= 0; i--)
		{
			tadd = ti[i] + cnt[i + 1] + addcnt_tmp[i + 1];
			while(tadd > 0)
			{
				index = findIndexOfMax(fi, i + 1);
				if(fi[index] == 0)
					break;
#ifdef DEGUBB
				cout << "index:" << index << " fi:" << fi[index] << " di" << di[index] << "    " << addfish <<endl;
#endif					
				addfish += fi[index];
				addcnt_tmp[index]++;
				fi[index] -= di[index];
				if(fi[index] < 0) 
					fi[index] = 0;
				
				tadd--;
			}
			addcnt_tmp[0] += tadd;
			addfish -= fish[i + 1];
			if(addfishmax <= addfish) 
			{	
				for(j = 0; j < i+1 ; j++)
					addcnt[j] = addcnt_tmp[j];
				lacknum_tmp = i + 1;
				addfishmax = addfish;
			}
		}
		for(i = lacknum_tmp ; i < n; i++)
			cnt[i] = addcnt[i] = 0;
			
		for(i = 0; i < n - 1; i++)
		{
			cout << (cnt[i] + addcnt[i]) * 5 << ", ";
			fishSum += fish[i];
		}
			
		cout << (cnt[i] + addcnt[i]) * 5 << endl;
		fishSum += fish[i];
		cout << "Number of fish expected: " << fishSum + addfishmax << endl << endl;
		
		cin >> n;
	}
	return 0;
}


int findIndexOfMax(int *a,int n)
{
	int maxindex = 0;
	for(int i = 0;i < n; i++)
	{
		if(a[i] > a[maxindex]) maxindex = i;
	}
	return maxindex;
}
