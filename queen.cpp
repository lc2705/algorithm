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

/*��ͳDFS���� TLE (n����30����������)*/

typedef class
{
    public:
        int r,c;
}location;

location pos[301];  //�������ŵĻʺ�����

bool col[301];  //�б��
int n;  //�ʺ���

bool DFS(int x,int p)
{
    if(p==n)
        return true;

    bool sign;
    for(int y=1;y<=n;y++)  //ö�ٵ�ǰ��x��ÿһ��
    {
        bool flag=false;
        for(int i=1;i<=p;i++)  //ö��ÿһ������ŵĻʺ�
            if(abs(x-pos[i].r) == abs(y-pos[i].c))   //��鵱ǰ׼����Żʺ��λ��(x,y)�Ƿ������ǵ�б����
            {        //��ʵ���Ǳ��б�ʣ�б�ʵ���1��-1�ĸ�������Żʺ�
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
                col[y]=false; //����,pos[]�ļ�¼���Զ�����ֵ���ǣ����Բ������⴦��
        }
    }
    return false;  //��ǰ��x��������y��������Żʺ�˵��ǰһ�������
}

int main(void)
{
    while(cin>>n)
    {
        if(!n)
            break;

        int p=0; //pos[]ָ��,������������
        memset(col,false,sizeof(col));

        DFS(1,p);

        for(int i=1;i<=n;i++)
            cout<<pos[i].c<<' ';
        cout<<endl;
    }
    return 0;
}
#endif