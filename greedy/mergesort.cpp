#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#define MAXLEN 1000010
#define INSORTNUM 10
//#define DEBUG

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
int init(node *head);  //return the number  of element
void printArray(node *head);

int main(int argc, char **argv)
{
    node head;
    int num = init(&head);
    MergeSortL(0, num, &head);
    printArray(&head);
}

int init(node *head)
{
    ifstream file;
    char value[50];

    file.open("test");
    if( !file.is_open())
    {
        cout << "File open failed !" << endl;
        exit(-1);
    }

    head->next = NULL;
    int n = 0;
    node *p = head;
    node *tmp;
    while(file >> value )
    {
        tmp = &link[n];
        tmp->val = atoi(value);
        tmp->next = NULL;
 //       p->next = tmp;
   //     p = p->next;
        n++;
    #ifdef DEBUG
        cout << tmp << endl;
        cout << a[n-1] << endl;
    #endif // DEBUG
    }
    file.close();
    return n;
}

void printArray(node *head)
{
    node *p = head->next;
    while(p != NULL)
    {
        cout << p->val << endl;
        p = p->next;
    }
}

void InSort(int low, int high, node *head)
{
    int i, j;
    node *p = NULL, *q, *r;
    head->next = link;

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
            p = p->next;
            n = n->next;
        }
        else
        {
            p->next = m;
            p = p->next;
            m = m->next;
        }
    }
    while(n != NULL)
    {
        p->next = n;
        p = p->next;
        n = n->next;
    }
    while(m != NULL)
    {
        p->next = m;
        p = p->next;
        m = m->next;
    }
    p->next = NULL;
}
#endif // 0
