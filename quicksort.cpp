#include <iostream>
#define MAXL 256
using namespace std;

template<class T>void QuickSort(T*, int, int);
template<class T>int Partition(T*, int, int);
template<class T>void Swap(T &a, T &b);

int main()
{
	int a[MAXL];
	int num = 0;
	int tmp;
	while(1)
	{
		cin >> tmp;
		if(tmp == -1) break;
		a[num] = tmp;
		num++; 
	}
	
	QuickSort(a,0,num - 1);
	
	for(int i = 0; i < num; i++)
		cout << a[i] <<' ';
	
	return 0;
}

template<class T>
void QuickSort(T *a,int p,int q)
{
	if(q <= p) 
		return;
	int mid = Partition(a, p, q);
	QuickSort(a, p, mid-1);
	QuickSort(a, mid + 1, q);
}

template<class T>
int Partition(T *a, int p, int q)
{
	T midV = a[p];
	int forward = p + 1;
	int backward = q;
	
	while(1)
	{
		while(a[forward] <= midV) forward++;
		while(a[backward] > midV) backward--;
		if(forward < backward)
			Swap(a[forward], a[backward]);
		else 
			break;		
	}
	a[p] = a[backward];
	a[backward] = midV;
	return backward;
}


template<class T>
void Swap(T &a,T &b)
{
	T c = a;
	a = b;
	b = c;
}