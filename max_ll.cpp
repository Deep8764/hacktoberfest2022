#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
} * first;
void create(int A[], int n)
{
    struct node *t, *last;
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
int maximum(struct node *p)
{
    int maxi = INT_MIN;
    while (p != NULL)
    {
        maxi = max(maxi, p->data);
        p = p->next;
    }
    return maxi;
}
int rmaximum(struct node *p)
{
    static int maxi = INT_MIN;
    if (p != 0)
    {
        if (p->data > rmaximum(p->next))
        {
            return p->data;
        }
        else
        {
            return rmaximum(p->next);
        }
        // return max(p->data, rmaximum(p->next));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A[] = {100, 2, 8, 4, 55};
    int n = 5;
    create(A, n);
    int max = maximum(first);
    int rmax = rmaximum(first);
    cout << "The maximum element is " << rmax << endl;
    return 0;
}
