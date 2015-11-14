#include <iostream>
#include <iomanip>
using namespace std;
#define MONTH 12

int main()
{
    float sum = 0;
    float tmp;
    int i;
    for(i = 0; i < MONTH ; i++)
    {
        cin >> tmp;
        sum += tmp;
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << '$' << sum / MONTH << endl;


}
