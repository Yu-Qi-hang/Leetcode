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
struct ListNode* swapPairs(struct ListNode* head){
    if(head&&head->next){
        struct ListNode*pre=NULL;
        struct ListNode*first=head;
        struct ListNode*second=head->next;
        head=head->next;
        while(first&&second){
            first->next=second->next;
            second->next=first;
            if(pre)pre->next=second;
            pre=first;
            if(first->next)first=first->next;
            else break;
            if(first->next)second=first->next;
            else break;
        }
    }
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
    struct ListNode*newlist=swapPairs(list);
    struct ListNode*idx=newlist;
    while(idx){
        printf("%d->",idx->val);
        idx=idx->next;
    }
    return 0;
}