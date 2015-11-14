#include <iostream>
#include <algorithm>
using namespace std;
#define MAXNUM 1000

float length[MAXNUM];
int initLength();
int search_length(float len, int num);

int main()
{
    int num = initLength();
    float len;
    while(1)
    {
        cin >> len;
        if(len == 0.0) break;
        cout << search_length(len, num) << " card(s)" << endl;
    }
    return 0;
}

int initLength()
{
    int i;
    length[0] = 0.0;
    float a = 2.0;
    for(i = 1; i < MAXNUM; i++)
    {
        if(length[i - 1] > 5.20)
            break;
        length[i] = length[i - 1] + 1/a;
        a += 1.0;
    }
    return i;
}

int search_length(float len, int num)
{
    int beg = 0;
    int end = num - 1;
    int mid;
    while(beg != end)
    {
        mid = (beg + end) / 2;
        if( len <= length[mid] && len > length[mid - 1])
            return mid;
        else if( len > length[mid] )
        {
            beg = mid + 1;
        }
        else if( len <= length[mid - 1])
        {
            end = mid - 1;
        }
    }
    return end;
}
