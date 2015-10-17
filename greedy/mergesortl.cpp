#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/time.h>
#define MAXLEN 1000010
#define INSORTNUM 10

using namespace std;

struct node
{
    int val;
    node *next;
};

node link[MAXLEN];

void MergeSortL( int low, int high, node *p);
void InSort( int low, int high, node *p);
void MergeL(node q, node r, node *p);
int init();  //return the number  of element
void printArray(node *head);

int main(int argc, char **argv)
{
    node head;
    struct timeval start_t,end_t;
    
    int num = init();
    gettimeofday(&start_t,NULL);
    MergeSortL(0, num, &head);
    gettimeofday(&end_t,NULL);
   	
	cout << end_t.tv_sec - start_t.tv_sec << '.' << end_t.tv_usec - start_t.tv_usec << endl;
 //   printArray(&head);
}

int init()
{
    ifstream file;
    char value[50];

    file.open("test_1000000");
    if( !file.is_open())
    {
        cout << "File open failed !" << endl;
        exit(-1);
    }

    int n = 0;
    while(file >> value )
    {
        link[n].val = atoi(value);
        link[n].next = NULL;
        n++;
    }
    file.close();
    return n;
}

void printArray(node *head)
{
    node *p = head->next;
    int n = 0;
    while(p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
        n++;
    }
    cout << n << endl;
}

void InSort(int low, int high, node *head)
{
    int i, j;
    node *p = NULL, *q, *r;
    head->next = &link[low];

    for(i = low + 1; i < high; i++)
    {
        p = &link[i];
        q = head->next;
        r = head;
        while(r != NULL)
        {
            if(q == NULL || p->val < q->val)
            {
                    p->next = q;
                    r->next = p;
                    break;
            }
            q = q->next;
            r = r->next;
        }
    }
}

void MergeSortL(int low, int high, node *p)
{
    if(high - low <= INSORTNUM)
    {
        InSort(low, high, p);
        return;
    }
    int mid = (low + high) / 2;
    node q,r;
    MergeSortL(low, mid,  &q);
    MergeSortL(mid, high, &r);
    MergeL(q, r, p);
}
#if 1
void MergeL(node q, node r, node *head)
{
    node *n = q.next;
    node *m = r.next;
    node *p = head;
    while(n != NULL && m != NULL)
    {
        if(n->val < m->val)
        {
            p->next = n;
            p = n;
            n = n->next;
        }
        else
        {
            p->next = m;
            p = m;
            m = m->next;
        }
    }
    while(n != NULL)
    {
        p->next = n;
        p = n;
        n = n->next;
    }
    while(m != NULL)
    {
        p->next = m;
        p = m;
        m = m->next;
    }
    p->next = NULL;
}
#endif // 0
