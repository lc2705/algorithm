#include <iostream>
#include <set>
using namespace std;
#define MAXLEN 1010

int main()
{
    int m,n,i,j;
    int win,case_n = 0;
    int me_tmp[MAXLEN];

    set<int,greater<int> > me;
    set<int,greater<int> > other;

    cin >> m >> n;
    while(m && n)
    {
        case_n++;
        win = 0;
        me.clear();
        other.clear();
        for(i = 0; i < n; i++)
        {
            cin >> me_tmp[i];
            me.insert(me_tmp[i]);
        }
        int card = m * n;

        set<int>::iterator iter = me.begin();
        i = 0;
        while(iter != me.end() && other.size() < n)
        {
            if(card != *iter)
                other.insert(card);
            else
                iter++;
            card--;
        }

        set<int>::iterator tmp_iter;
        for(iter = other.begin(); iter != other.end(); iter ++)
        {
            tmp_iter = me.upper_bound(*iter);
            if(tmp_iter != me.end())
            {
                win++;
                me.erase(tmp_iter);
            }
        }
        cout << "Case " << case_n << ": " << n - win << endl;
        cin >> m >> n;
    }

}
