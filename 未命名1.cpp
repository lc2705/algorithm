#include <iostream>
#include <algorithm>

#define MAXNUM 100010
using namespace std;

struct troop
{
	int attack;
	int defense;
};

troop me[MAXNUM];
troop enemgy[MAXNUM];

bool battle(int n,int m);
int CountRes(int n, int m);
void InitFun(int n,int m);
bool cmp_me(troop a,troop b);
bool cmp_enemgy(troop,troop);

int main()
{
	int T,m,n;
	cin >> T;
	int i;
	for(i = 0; i < T; i++)
	{
		cin >> n >> m;
		if(n < m)
		{
			cout << "Case #" << i+1 <<": "<< -1 << endl;
			continue;
		}
		InitFun(n,m);
		if(battle(n, m))
		{
			cout << "Case #" << i+1 << ": " << n - m + CountRes(n,m) << endl;
		}
		else
			cout << "Case #" << i+1 <<": "<< -1 << endl;
	}
	return 0;
}

bool battle(int n,int m)
{
	sort(me,me+n,cmp_me);
	sort(enemgy,enemgy+m,cmp_enemgy);
	
	for(int i = 0; i < m; i++)
	{
		if(me[i].attack <= enemgy[i].defense)
			return false;
	}
	return true;
}

void InitFun(int n,int m)
{
	int i;
	for(i = 0;i < n; i ++)
	{
		cin >> me[i].attack >> me[i].defense;
	}
	for(i = 0; i < m; i++)
	{
		cin >> enemgy[i].attack >> enemgy[i].defense;
	}
}

int CountRes(int n,int m)
{
	sort(me, me + n, cmp_enemgy);
	sort(enemgy, enemgy + m, cmp_me);
	
	int i = n-1;
	int j = m-1;
	int cnt = 0;
	for(; i >= 0; i--)
	{
		if(me[i].defense > enemgy[j].attack)
		{
			j--;
			cnt++;
		}
	}	
	return cnt;
}

bool cmp_me(troop a,troop b)
{
	return a.attack > b.attack;
}

bool cmp_enemgy(troop a,troop b)
{
	return a.defense > b.defense; 
}
