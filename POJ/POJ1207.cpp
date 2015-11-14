#include <iostream>
using namespace std;

int getLen(int i)
{
    int len = 1;
    while(i > 1)
    {
        if(i % 2)
            i = i*3 + 1;
        else
            i = i/2;

        len++;
    }
    return len;
}
int main()
{
    int i,j;
    while(cin >> i >> j)
    {
        int maxLen = 0;
        int beg,end;
        if(i > j)
        {
            beg = j;
            end = i;
        }
        else
        {
            beg = i;
            end = j;
        }
        for(int k = beg; k <= end; k++)
        {
            int len = getLen(k);
            maxLen = len > maxLen ? len : maxLen;
        }

        cout << i << " " << j << " " << maxLen << endl;
    }
    return 0;
}
