#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode *List;
struct ListNode {
    int val;
    struct ListNode *next;
};

List createNode(int val){
    List temp=(List)malloc(sizeof(struct ListNode));
    temp->val=val;
    temp->next=NULL;
    return temp;
}
void printlist(List head){
    List p=head;
    while (p->next)
    {
        printf("%d->",p->val);
        p=p->next;
    }
    printf("%d\n",p->val);    
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);

int main(){
    int sz,n;
    scanf("%d %d",&sz,&n);
    int item;
    List head=NULL;
    scanf("%d",&item);
    head=createNode(item);
    List p=head;
    for(int i=1;i<sz;i++){
        scanf("%d",&item);
        p->next=createNode(item);
        p=p->next;
    }
    printlist(head);
    List new=removeNthFromEnd(head,n);
    printlist(new);
    return 0;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val=-1;
    dummy->next=head;
    struct ListNode *p,*q;
    p=head;
    q=dummy;
    int i=0;
    while(++i<n)p=p->next;
    while(p->next){
        p=p->next;
        q=q->next;
    }
    p=q->next;
    q->next=p->next;
    free(p);
    p=dummy->next;
    free(dummy);
    return p;
}