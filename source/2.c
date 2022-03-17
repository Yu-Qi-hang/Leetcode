#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int increase=0;
    struct ListNode *l3;
    struct ListNode *p3=l3;
    struct ListNode *p1=l1;
    struct ListNode *p2=l2;
    while(p1&&p2){
        struct ListNode *new;
        new=(struct ListNode*)malloc(sizeof(struct ListNode));
        new->val=p1->val+p2->val+increase;
        increase=0;
        while(new->val>9){
            new->val-=10;
            increase+=1;
        }
        new->next=NULL;
        if(p3)p3->next=new;
        else l3=new;
        p3=new;
        p2=p2->next;
        p1=p1->next;
    }
    while(p1){
        struct ListNode *new;
        new=(struct ListNode*)malloc(sizeof(struct ListNode));
        new->val=p1->val+increase;
        increase=0;
        while(new->val>9){
            new->val-=10;
            increase+=1;
        }
        new->next=NULL;
        if(p3)p3->next=new;
        else l3=new;
        p3=new;
        p1=p1->next;
    }
    while(p2){
        struct ListNode *new;
        new=(struct ListNode*)malloc(sizeof(struct ListNode));
        new->val=p2->val+increase;
        increase=0;
        while(new->val>9){
            new->val-=10;
            increase+=1;
        }
        new->next=NULL;
        if(p3)p3->next=new;
        else l3=new;
        p3=new;
        p2=p2->next;
    }
    if(increase){
        struct ListNode *new;
        new=(struct ListNode*)malloc(sizeof(struct ListNode));
        new->val=increase;
        increase=0;
        new->next=NULL;
        if(p3)p3->next=new;
        else l3=new;
        p3=new;
    }
    return l3;    
}