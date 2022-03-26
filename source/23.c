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
void printlistk(struct ListNode **list,int listsize){
    for(int i=0;i<listsize;i++){
        struct ListNode *ptr=list[i];
        while(ptr){
            printf("%d->",ptr->val);
            ptr=ptr->next;
        }
        printf("\n");
    }
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize);
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
int main(){
    int k;
    scanf("%d",&k);
    int *length=(int*)malloc(sizeof(int)*k);
    struct ListNode **list=(struct ListNode**)malloc(sizeof(struct ListNode*)*k);
    struct ListNode *ptr;
    int item;
    list[0]=NULL;
    for(int i=0;i<k;i++){
        int n=0;
        scanf("%d",&n);
        length[i]=n;
        if(n>0){
            scanf("%d",&item);
            list[i]=create(item);
            ptr=list[i];
            for(int i=1;i<n;i++){
                scanf("%d",&item);
                ptr->next=create(item);
                ptr=ptr->next;
            }
        }
        else list[i]=NULL;
    }
    struct ListNode *combine=mergeKLists(list,k);
    ptr=combine;
    while(ptr){
        printf("%d->",ptr->val);
        ptr=ptr->next;
    }
    // printlistk(list,k);
    return 0;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize<1)return NULL;
    for(int i=listsSize;i>1;i=(i+1)/2){
        int idx1=0,idx2=i-1;
        while(idx1<idx2){
            lists[idx1]=mergeTwoLists(lists[idx1],lists[idx2]);
            idx1++;
            idx2--;
        }
    }
    return lists[0];
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