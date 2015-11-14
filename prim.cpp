#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 10000
#define MAXN 1000
struct edge
{
    int s,d;
    int weight;

    edge(int s, int d, int weight):s(s),d(d),weight(weight){}
};
struct vertex
{
    int pre;
    int distance;

    vertex(int pre,int distance):pre(pre),distance(distance){}
};

int N;
vector<edge> tree;
vector<vertex> near_v;
int relate_array[MAXN][MAXN];

int findMin()
{
    vector<vertex>::iterator iter;
    int min_i = -1,min_dist = INF;
    for(int i = 0; i < near_v.size();i++)
    {
        if(near_v[i].distance && near_v[i].distance < min_dist)
        {
            min_dist = near_v[i].distance;
            min_i = i;
        }
    }
    return min_i;
}

void prim()
{
    //initialize
    int i,j;
    near_v.push_back(vertex(-1,0));  //vertext 0
    for(i = 1; i < N;i++)
    {
        if(relate_array[0][i] == 0)
            near_v.push_back(vertex(-1,INF));
        else
            near_v.push_back(vertex(0,relate_array[0][i]));
    }
    while(tree.size() != N-1)
    {
        int min_v = findMin();
 //       cout << near_v[min_v].pre << " " << min_v << " " << near_v[min_v].distance << endl;
        tree.push_back(edge(near_v[min_v].pre, min_v, near_v[min_v].distance));
        near_v[min_v].distance = 0;
        for(i = 0; i < N; i++)
        {
            if(relate_array[min_v][i] != 0 && relate_array[min_v][i] < near_v[i].distance)
            {
                near_v[i].distance = relate_array[min_v][i];
                near_v[i].pre = min_v;
            }
        }
    }
}

int main()
{
    int i,j;
    cin >> N;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            cin >> relate_array[i][j];
    }
    prim();
    for(vector<edge>::iterator iter = tree.begin();iter != tree.end();iter++)
        cout << iter->s << " -> " << iter->d << " : " << iter->weight << endl;
    return 0;
}

/*
6
0 10 0 30 45 0
10 0 50 0 40 25
0 50 0 0 35 15
30 0 0 0 0 20
45 40 35 0 0 55
0 25 15 20 55 0
*/
