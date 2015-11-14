#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXLEN 110
#define ALPHASIZE 26

int main()
{
    int m_size;
    char original[MAXLEN];
    char encryted[MAXLEN];
    int o_count[ALPHASIZE] = {0};
    int e_count[ALPHASIZE] = {0};

    cin >> original >> encryted;
    m_size = strlen(original);
    if(m_size != strlen(encryted))
    {
        cout << "NO" << endl;
        return 0;
    }

    for(int i = 0; i < m_size; i++)
    {
        o_count[original[i] - 'A']++;
        e_count[encryted[i] - 'A']++;
    }
    sort(o_count,o_count + ALPHASIZE,greater<char>());
    sort(e_count,e_count + ALPHASIZE,greater<char>());
    for(int i = 0; e_count && i < ALPHASIZE; i++)
    {
        if(e_count[i] != o_count[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
