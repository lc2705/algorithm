#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 1000

struct v
{
	int id;
	int dist;
	bool vis;
	
	v():id(-1),dist(MAXN),vis(false){}
};

int relate_array[MAXN][MAXN];
v v_set[MAXN];
int N;

void dijkstra(int source)
{
	int i,j;
	for(i = 0; i < N; i++)
	{
		v_set[i].id = i;
		v_set[i].dist = MAXN;
		v_set[i].vis = false;
	}
	v_set[source].dist = 0;
	
	for(i = 0; i < N;i++) 
	{
		v min_v;
		for(j = 0; j < N; j++)
		{
			if(!v_set[j].vis && v_set[j].dist < min_v.dist)
				min_v = v_set[j];
		}
		if(min_v.id == -1) break;
		v_set[min_v.id].vis = true;		
		
		for(j = 0; j < N; j++)
		{
			if(relate_array[min_v.id][j] && relate_array[min_v.id][j] + min_v.dist < v_set[j].dist)
			{
				v_set[j].dist = relate_array[min_v.id][j] + min_v.dist;
			}
			
		}		
	}
	
	for(i = 0; i < N;i++)
		cout << i << " " << v_set[i].dist << endl;
	
}

int main()
{
	int i,j;
	cin >> N;
	for(i = 0;i < N; i++)
	{
		for(j = 0;j < N; j++)
			cin >> relate_array[i][j];
	}		
	int source;
	cin >> source;	
	dijkstra(source);
	
	return 0;
}

/*
0 50 10 0 45 0
0 0 15 0 10 0
20 0 0 15 0 0
0 20 0 0 35 0
0 0 0 30 0 0
0 0 0 30 0 0

*/