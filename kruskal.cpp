#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 1000
struct edge
{
    int s,d;
    int weight;

    edge(int s, int d, int weight):s(s),d(d),weight(weight){}
};
struct cmp
{
    bool operator()(edge a, edge b)
    {
        return a.weight > b.weight;
    }
};

int relate_array[MAXN][MAXN];
vector<edge> tree;
int root[MAXN];

int findRoot(int x)
{
    if(root[x] != x)
        return findRoot(root[x]);
    else
        return x;
}
void unionRoot(int x, int y)
{
    root[y] = root[x];
}
void kruskal(int N)
{
    int i,j;
    priority_queue<edge,vector<edge>, cmp> edge_q;
    for(i = 0; i < N; i++)
    {
        root[i] = i;
        for(j = 0; j <= i; j++)
        {
            if(relate_array[i][j])
                edge_q.push(edge(i,j,relate_array[i][j]));
        }
    }

    while(tree.size() < N-1)
    {
        edge min_edge = edge_q.top();
        edge_q.pop();
        if(findRoot(min_edge.s) != findRoot(min_edge.d))
        {
            tree.push_back(min_edge);
            unionRoot(min_edge.s,min_edge.d);
        }
    }
}

int main()
{
    int N,i,j;
    cin >> N;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            cin >> relate_array[i][j];
    }
    kruskal(N);
    for(vector<edge>::iterator iter = tree.begin(); iter != tree.end(); iter++)
        cout << iter->s << " - " << iter->d << " : " << iter->weight << endl;

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
