#include <bits/stdc++.h>
using namespace std;

struct node
{

    int data;
    struct node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct node *t, *last;
    first = new node;
    first->data = A[0];
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

void display(struct node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void insertll(int n)
{
    struct node *t, *last;
    if (first == NULL)
    {
        t = new node;
        t->data = n;
        t->next = NULL;
        first = t;
        last = t;
    }
    else
    {
        t = new node;
        t->data = n;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void deleting()
{

    struct node *p;
    p = first;
    first = first->next;
    delete p;
}
void deletepos(int pos)
{
    struct node *p, *q;
    p = first;
    q = NULL;

    if (pos == 0)
    {
        first = first->next;
        delete p;
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        delete p;
    }
}

void sortedllornot()
{

    struct node *p, *q;
    p = first->next;
    q = first;
    bool ans = true;
    while (p != NULL)
    {
        if (p->data < q->data)
        {
            ans = false;
            cout << "Not sorted" << endl;
        }
        q = p;
        p = p->next;
    }

    if (ans == true)
    {
        cout << "sorted" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // create(A, 10);
    insertll(0);
    insertll(1);
    insertll(2);
    insertll(3);
    insertll(4);
    insertll(5);
    // deleting();
    // deletepos(0);
    // deletepos(2);
    // display(first);
    sortedllornot();
    return 0;
}
