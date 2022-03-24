#include<stdlib.h>
#include<stdio.h>


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
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    struct ListNode *list1,*list2,*p,*q;
    int item;
    scanf("%d",&item);
    list1=create(item);
    p=list1;
    for(int i=1;i<m;i++){
        scanf("%d",&item);
        p->next=create(item);
        p=p->next;
    }
    scanf("%d",&item);
    list2=create(item);
    q=list2;
    for(int i=1;i<n;i++){
        scanf("%d",&item);
        q->next=create(item);
        q=q->next;
    }
    struct ListNode *list=create(0);
    list->next=mergeTwoLists(list1,list2);
    struct ListNode* idx=list;
    while(idx->next){
        idx=idx->next;
        printf("%d->",idx->val);
    }
    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
     if(!list1)return list2;
     if(!list2)return list1;
    struct ListNode *p1,*p2,*p,*ret;
    p1=list1;
    p2=list2;
    if(p1->val<p2->val){
        ret=p1;
        p1=p1->next;
    }
    else{
        ret=p2;
        p2=p2->next;
    }
    p=ret;
    while(p1&&p2){
        if(p1->val<p2->val){
            p->next=p1;
            p1=p1->next;
            p=p->next;
        }
        else{
            p->next=p2;
            p2=p2->next;
            p=p->next;
        }
    }
    if(p1)p->next=p1;
    if(p2)p->next=p2;
    return ret;
}
// struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
//     if(!list1)return list2;
//     if(!list2)return list1;
//     struct ListNode *p1,*p2,*p;
//     p1=list1;
//     p2=list2;
//     if(p1->val<p2->val){
//         p=p1;
//         p1=p1->next;
//     }
//     else{
//         p=p2;
//         p2=p2->next;
//     }
//     p->next=mergeTwoLists(p1,p2);
//     return p;
// }