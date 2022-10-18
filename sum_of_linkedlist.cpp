#include<iostream>
using namespace std;
struct Node{
    int val;
    Node *next;
    Node(int x){ val = x; next = NULL;}
};
void push_front(Node **head, int x){
    Node* temp = new Node(x);
    temp->next = *head;
    *head = temp;
}
void printit(Node *head){
    cout<<"head -> ";
    while(head){
        cout<<head->val<<" -> ";
        head = head->next;
    }
    cout<<"NULL \n";
}
Node* maxsumlist(Node* a, Node* b){
    Node *ca, *cb;
    Node *pa, *pb;
    ca = pa = a;
    cb = pb = b;
    Node *ans = NULL, *ans_end = NULL;
    while(ca!=NULL || cb!=NULL){
        int suma = 0, sumb = 0;
    
    // to calculate sums between two common nodes in
    // the two linked lists
        while(ca!=NULL && cb!=NULL && ca->val!=cb->val){
            if(ca->val < cb->val){
                suma += ca->val;
                ca = ca->next;
            } else {
                sumb += cb->val;
                cb = cb->next;
            }
        }
        if(ca==NULL || cb==NULL){
            while(ca){
                suma += ca->val;
                ca = ca->next;
            }
            while(cb){
                sumb += cb->val;
                cb = cb->next;
            }
        }
        // if it is our first traversal
        if( pa == a || pb == b){
            if(suma > sumb){
                ans = pa;
                ans_end = ca;
            } else {
                ans = pb;
                ans_end = cb;
            }
        }
        else {
            if(suma > sumb){
                ans_end->next = pa;
                ans_end = ca;
            } else {
                ans_end->next = pb;
                ans_end = cb;
            }
        }
        if(ca) ca = ca->next;
        if(cb) cb = cb->next;
        
        pa = ca;
        pb = cb;
    }
    
    return ans;
}
int main()
{
    Node *a, *b;
    a = b = NULL;
    push_front(&a,517);
    push_front(&a,240);
    push_front(&a,121);
    push_front(&a,90);
    push_front(&a,31);
    push_front(&a,3);
    push_front(&a,1);
    push_front(&b,249);
    push_front(&b,240);
    push_front(&b,125);
    push_front(&b,90);
    push_front(&b,42);
    push_front(&b,12);
    push_front(&b,3);
    push_front(&b,-1);
    Node* ans = maxsumlist(a,b);
    printit(ans);
}
</head-></iostream>
