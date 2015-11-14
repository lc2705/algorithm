#include <iostream>
using namespace std;
#define MAXNUM 110

float v_array[MAXNUM] = {0.0};
class currency
{
public:
    int A,B;
    float rab,cab,rba,cba;

    void setValue(int A, int B, float rab, float cab, float rba, float cba)
    {
        this->A = A;
        this->B = B;
        this->rab = rab;
        this->cab = cab;
        this->rba = rba;
        this->cba = cba;
    }
}c_array[MAXNUM];

bool bellman(int N, int M, int S, float V)
{
    int i,j;
    bool flag = true;
    v_array[S] = V;
    for(i = 0; flag && i < N; i++)
    {
        flag = false;
        for(j = 0; j < M; j++)
        {
            currency c = c_array[j];
            if((v_array[c.A] - c.cab) * c.rab > v_array[c.B])
            {
                v_array[c.B] = (v_array[c.A] - c.cab) * c.rab;
                flag = true;
            }
            if((v_array[c.B] - c.cba) * c.rba > v_array[c.A])
            {
                v_array[c.A] = (v_array[c.B] - c.cba) * c.rba;
                flag = true;
            }
        }
    }
    return flag;
}

int main(int argc, char* argv[])
{
    int i;
    int N,M,S;
    float V;
    cin >> N >> M >> S >> V;
    for(i = 0; i < M; i++)
    {
        int a,b;
        float r1,c1,r2,c2;
        cin >> a >> b >> r1 >> c1 >> r2 >> c2;
        c_array[i].setValue(a,b,r1,c1,r2,c2);
    }
    bool flag = bellman(N,M,S,V);
    if(flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
