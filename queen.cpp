#include <iostream>
using namespace std;

void SetQueen(int *a,int cur,int n);
void Print(int *a,int n);
int vis[3][600] = {0};

int main()
{
	int n;
	int a[300];
	while(1)
	{
		cin >> n;
		if(n == 0) break;
		SetQueen(a,0,n);
	}
	return 0;	
}

void SetQueen(int *a, int cur, int n)
{
	if(cur == n)
	{
		Print(a, n);
		return;
	}
	for(int i = 0; i < n; i++)
	{
		bool flag = false;
		for(int j = 0; j < cur; j++)
		{
		//	if(a[j] == i || (cur - j == i - a[j]) || (cur - j == a[j] - i))
			if(vis[0][i] || vis[1][cur + i] || vis[2][cur - i + n])
			{
				flag = true;
				break;
			}
		}
		if(!flag)
		{
			a[cur] = i;
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
			SetQueen(a, cur + 1, n);
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
		}
	}
		
}

void Print(int *a, int n)
{
	for(int i = 0; i < n; i++)
		cout << a[i] + 1 << ' ';
	cout << endl;
}
