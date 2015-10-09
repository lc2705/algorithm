#include <iostream>
#define NUM 9  //1~9
using namespace std;

void Permutation(int*, int);
void PrintArray(int*, int);

int cnt = 0;

int main()
{
	int a[NUM];
	Permutation(a,0);
	cout << cnt << endl;
	return 0;
}

void Permutation(int *a,int cur)
{
	if(cur == NUM) 
	{
//		PrintArray(a, NUM);
		cnt++;
		return;		
	}
	bool flag = false;
	for(int i = 1; i <= NUM; i++)
	{
		flag = false;
		for(int j = 0; j < cur; j++)
		{
			if(a[j] == i) 
			{
				flag = true;
				break;
			}
		}
		if(!flag)
		{
			a[cur] = i;
			Permutation(a, cur + 1);
		}
	}
}

void PrintArray(int *a, int num)
{
	int i;
	for(i = 0; i < num; i++)
		cout << a[i];
	cout << endl;
}
