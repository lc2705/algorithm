#include <iostream>
#include <algorithm>
using namespace std;

bool selected[64];
int stick[64];

bool cmp(int a, int b);
int InitStick(int n);
bool FindLength(int initlen,int len,int cur, int n);

int main()
{
	int n;
	while(1)
	{
		cin >> n;
		if(n == 0)
	 		break;
	 		
		int i;
		int sum = InitStick(n);
		sort(stick,stick + n,cmp);
		for(i = stick[0]; i < sum ; i++)
		{
			if(!(sum % i) && FindLength(0,i,0,n))
				break;
		}
		cout << i << endl;
	}
	return 0;
}

bool FindLength(int initlen, int len, int cur, int n)
{
	if(cur == n)
	{
		if(initlen == 0)
			return true;
		else 
			return false;
	}

	int failstick = 0;	
	for(int i = 0; i < n ; i++)
	{
		if(selected[i] || stick[i] == failstick)
			continue;
		
		selected[i] = true;
		if(initlen + stick[i] < len)
		{
			if(FindLength(initlen + stick[i], len, cur + 1, n))
				return true;
		}
		else if(initlen + stick[i] == len)
		{
			if(FindLength(0, len, cur + 1, n))
				return true;
		}
		failstick = stick[i];
		selected[i] = false;
		
		if(initlen == 0) //important!!!
			break;
	}
	
	return false;	
}

int InitStick(int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)	
	{
		cin >> stick[i];
		sum += stick[i];
		selected[i] = false;
	}
	return sum;
}

bool cmp(int a,int b)
{
	return a > b;
}
