#include <iostream>
#include <cmath>
#define MAXL 256
using namespace std;

void Merge(int,int,int);
void MergeSort(int,int);

int a[MAXL] = {1,4,7,6,7};

int main()
{
	int n = 0;
	int tmp;
	while(1)
	{
		cin >> tmp;
		if(tmp == -1) break;
		a[n] = tmp;
		n++; 
	}
	MergeSort(0,n-1);
	for(int i = 0; i < n; i++)
		cout << a[i] << ' ';
	return 0;
}

void Merge(int low,int mid,int high)
{
	int local[MAXL];
	int i = low; 
	int j = mid+1;
	int k = low; //position in a
	
	while(i <= mid && j <= high)
	{
		if(a[i] <= a[j])
		{
			local[k] = a[i];
			i++;
		}	
		else
		{
			local[k] = a[j];
			j++;
		}
		k++;
	}
	while(i <= mid)
	{
		local[k] = a[i];
		i++;
		k++;
	}
	while(j <= high)
	{
		local[k] = a[j];
		j++;
		k++;
	}
	for(k = low; k <= high; k++)
		a[k] = local[k];
}

void MergeSort(int low,int high)
{
	if(low < high)
	{
		int mid = (int)floor((low + high)/2);
		MergeSort(low,mid);
		MergeSort(mid+1,high);
		Merge(low,mid,high);
	}
}
