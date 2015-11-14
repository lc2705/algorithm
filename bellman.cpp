#include <iostream>
#include <vector>
using namespace std;
#define MAXN 1000
class edge
{
    public:
        int beg;
        int end;
        int value;

        edge(int beg,int end, int value): beg(beg),end(end),value(value){}
};

class vertex
{
public:
    int id;
    int value;
    int pre;

    vertex(int id): id(id),value(MAXN),pre(-1){}
};

int relate_array[MAXN][MAXN];
vector<vertex> v_vector;
vector<edge> e_vector;
int N;

void bellman(int source)
{
    int i,j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(relate_array[i][j])
            {
                e_vector.push_back(edge(i,j,relate_array[i][j]));
            }
        }
        v_vector.push_back(vertex(i));
    }
    v_vector.at(source).value = 0;
    bool flag = true;

    int count = 0;
    for(vector<vertex>::iterator i = v_vector.begin(); flag && i != v_vector.end(); i++)
    {
    	flag = false;
    	count++;
    	for(vector<edge>::iterator j = e_vector.begin(); j != e_vector.end(); j++)
    	{
	    	if(v_vector[j->end].value > v_vector[j->beg].value + j->value)
	    	{
	    		v_vector[j->end].value = v_vector[j->beg].value + j->value;
	    		v_vector[j->end].pre = j->beg;
	    		flag = true;
	    	}
	    }
    }
    cout << "circles: " << i << endl;

}

int main()
{
    int i,j;
    cin >> N;
    for(i = 0;i < N;i++)
        for(j = 0;j < N; j++)
            cin >> relate_array[i][j];

    int source;
    vector<vertex>::iterator iter;

    cin >> source;
    bellman(source);

	i = 0;
    for(iter = v_vector.begin(); iter != v_vector.end(); iter++)
        cout << iter->id  << " "<< iter->value << endl;

    int dest;
    cin >> dest;
    while(dest != source)
    {
        cout << dest << " <- ";
        dest = v_vector[dest].pre;
    }
    cout << dest << endl;

    return 0;
}

/*
6
0 50 10 0 45 0
0 0 15 0 10 0
20 0 0 15 0 0
0 20 0 0 35 0
0 0 0 30 0 0
0 0 0 30 0 0
0

*/
