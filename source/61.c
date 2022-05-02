#include<stdio.h>
#include<stdlib.h>
struct ListNode {
   int val;
   struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head||!head->next||k==0)return head;
    struct ListNode *p=head,*q=head;
    int cnt=0;
    while(cnt<k){
        if(q->next){
            q=q->next;
            cnt++;
        }
        else {
            q=p;
            k=k%(cnt+1);
            cnt=0;
        }
        printf("%d %d\n",cnt,k);
    }
    while(q->next){
        q=q->next;
        p=p->next;
    }
    q->next=head;
    head=p->next;
    p->next=NULL;
    return head;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    struct ListNode *head=NULL,*p;
    for(int i=0;i<n;i++){
        struct ListNode *temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d",&temp->val);
        temp->next=NULL;
        if(!head){
            head=temp;
            p=head;
        }
        else{
            p->next=temp;
            p=p->next;
        }
    }
    p=rotateRight(head,k);
    while(p){
        printf("%d ",p->val);
        p=p->next;
    }
    return 0;
}