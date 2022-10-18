#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
} * first;

void create(int A[], int n)
{
    struct node *t;
    struct node *last;
    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int sum(struct node *p)
{
    int addition = 0;
    while (p != NULL)
    {
        addition = addition + p->data;
        p = p->next;
    }
    return addition;
}
int rsum(struct node *p)
{
    if (p != 0)
    {
        return p->data + rsum(p->next);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A[] = {1, 2, 3, 4, 5};
    int n = 5;
    create(A, n);
    int add = sum(first);
    int rs = rsum(first);
    cout << "The sum of the node is " << rs << endl;
    return 0;
}
