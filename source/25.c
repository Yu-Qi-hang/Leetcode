#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* create(int item){
    struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val=item;
    temp->next=NULL;
    return temp;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    int length=0;
    struct ListNode*p=head;
    while(p){
        length++;
        p=p->next;
    }
    if(length<k)return head;
    struct ListNode *dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val=0;
    dummy->next=head;
    struct ListNode *pre,*tail,*newhead;
    pre=dummy;
    tail=pre->next;
    newhead=tail->next;
    int count=1;
    while(newhead){
        while(count<k){
            tail->next=newhead->next;
            newhead->next=pre->next;
            pre->next=newhead;
            newhead=tail->next;
            count++;
        }
        length-=k;
        if(length<k)break;
        pre=tail;
        tail=pre->next;
        newhead=tail->next;
        count=1;
    }
    head=dummy->next;
    free(dummy);
    return head;
}
int main(){
    int n;
    struct ListNode*list=NULL;
    scanf("%d",&n);
    if(n){
        int item;
        scanf("%d",&item);    
        list=create(item);
        struct ListNode*p=list;
        for(int i=1;i<n;i++){
            scanf("%d",&item);
            p->next=create(item);
            p=p->next;
        }
    }
    scanf("%d",&n);
    struct ListNode*newlist=reverseKGroup(list,n);
    struct ListNode*idx=newlist;
    while(idx){
        printf("%d->",idx->val);
        idx=idx->next;
    }
    return 0;
}