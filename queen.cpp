#include <iostream>
using namespace std;

void SetQueen(int *a,int cur,int n);
void Print(int *a,int n);
int vis[3][600] = {0};
bool finded;

int main()
{
	int n;
	int a[300];
	while(1)
	{
		cin >> n;
		if(n == 0) break;
		finded = false;
		SetQueen(a,0,n);
	}
	return 0;	
}

void SetQueen(int *a, int cur, int n)
{
	if(finded)
		return;
		
	if(cur == n)
	{
		finded = true;
		Print(a, n);
		return;
	}
	for(int i = 0; i < n; i++)
	{
		bool flag = false;
		for(int j = 0; j < cur; j++)
		{
		//	if(a[j] == i || (cur - j == i - a[j]) || (cur - j == a[j] - i))
			if(vis[0][i] || vis[1][cur + i] || vis[2][cur - i + n])
			{
				flag = true;
				break;
			}
		}
		if(!flag)
		{
			a[cur] = i;
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
			SetQueen(a, cur + 1, n);
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
		}
	}
		
}

void Print(int *a, int n)
{
	for(int i = 0; i < n; i++)
		cout << a[i] + 1 << ' ';
	cout << endl;
}

#if 0

/*传统DFS回溯 TLE (n超过30就难以搜索)*/

typedef class
{
    public:
        int r,c;
}location;

location pos[301];  //标记已填放的皇后坐标

bool col[301];  //列标记
int n;  //皇后数

bool DFS(int x,int p)
{
    if(p==n)
        return true;

    bool sign;
    for(int y=1;y<=n;y++)  //枚举当前行x的每一列
    {
        bool flag=false;
        for(int i=1;i<=p;i++)  //枚举每一个已填放的皇后
            if(abs(x-pos[i].r) == abs(y-pos[i].c))   //检查当前准备填放皇后的位置(x,y)是否在他们的斜边上
            {        //其实就是标记斜率，斜率等于1或-1的格不允许填放皇后
                flag=true;
                break;
            }
            
        if(!flag && !col[y])
        {
            col[y]=true;
            pos[p+1].r=x;
            pos[p+1].c=y;
            sign=DFS(x+1,p+1);

            if(sign)
                return true;
            else
                col[y]=false; //回溯,pos[]的记录会自动被新值覆盖，所以不用特意处理
        }
    }
    return false;  //当前行x的所有列y均不允许放皇后，说明前一行填错了
}

int main(void)
{
    while(cin>>n)
    {
        if(!n)
            break;

        int p=0; //pos[]指针,已填充的棋子数
        memset(col,false,sizeof(col));

        DFS(1,p);

        for(int i=1;i<=n;i++)
            cout<<pos[i].c<<' ';
        cout<<endl;
    }
    return 0;
}
#endif