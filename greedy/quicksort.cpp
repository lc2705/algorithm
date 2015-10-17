#include <iostream>
#include <fstream>
#include <sys/time.h>
using namespace std;
#define MAXLEN 1000010

int init();
void PrintArray(int num);
void QuickSort(int low, int high);
int Partition(int low, int high);//return the partition element

int a[MAXLEN];

int main(int argc, char **argv)
{
	struct timeval start_t,end_t;
	int num = init();
	gettimeofday(&start_t, NULL);
	QuickSort(0,num);
	gettimeofday(&end_t, NULL);
	
	cout << end_t.tv_sec - start_t.tv_sec << '.' << end_t.tv_usec - start_t.tv_usec << endl;
//	PrintArray(num);
	return 0;
}

int init()
{
    ifstream file;
    char value[50];

    file.open("test_100000");
    if( !file.is_open())
    {
        cout << "File open failed !" << endl;
        exit(-1);
    }

    int n = 0;
    while( file >> value)
    {
        a[n] = atoi(value);
        n++;
    }
    file.close();
    return n;
}

void PrintArray(int num)
{
	int i;
	for(i = 0; i < num; i++)
		cout << a[i] << endl;
}

void QuickSort(int low, int high)
{
	if(low >= high - 1)
		return;
	int pindex = Partition(low, high);
	QuickSort(low, pindex);
	QuickSort(pindex + 1, high);
}

int Partition(int low, int high)
{
	int pindex = low;
	int p = a[low];
	int i = low,j = high;
	while(1)
	{
		while(i++ < high && a[i] <= p);
	 	while(j-- > low && a[j] > p);
		if(i < j)
		{
			int tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}
		else
			break;	
	}
	a[low] = a[j];
	a[j] = p;
	return j;
}