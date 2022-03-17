#include<stdio.h>
#define MAX 1005
double findMedianSortedArrays1(int* nums1, int nums1Size, int* nums2, int nums2Size);
double findMedianSortedArrays2(int* nums1, int nums1Size, int* nums2, int nums2Size);
int main(){
    int m,n;
    int nums1[MAX]={0};
    int nums2[MAX]={0};
    scanf("%d",&m);
    for(int i=0;i<m;i++)scanf("%d",&nums1[i]);
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&nums2[i]);
    double media=findMedianSortedArrays1(nums1,m,nums2,n);
    printf("%.5f",media);
    return 0;
}

/*solution1*/
double findMedianSortedArrays1(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int sum=nums2Size+nums1Size;
    int nums3[MAX+MAX]={0};
    int re=sum%2;
    int index=0;
    int a1=0,a2=0;
    while(a1<nums1Size&&a2<nums2Size){
        if(nums1[a1]<nums2[a2])nums3[index++]=nums1[a1++];
        else nums3[index++]=nums2[a2++];
    }
    while(a1<nums1Size)nums3[index++]=nums1[a1++];
    while(a2<nums2Size)nums3[index++]=nums2[a2++];
    if(re){
        index=(sum-re)/2;
        return (double)nums3[index];
    }
    else{
        index=sum/2;
        return ((double)nums3[index]+(double)nums3[index-1])/2.0;
    }
}
/*solution2*/
double findMedianSortedArrays2(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int sum=nums2Size+nums1Size;
    int re=sum%2;
    int index=0;
    int a1=0,a2=0;
    double cnt1=0,cnt2=0;
    while(a1<nums1Size&&a2<nums2Size){
        if(nums1[a1]<nums2[a2]){
            if(index==(sum-re)/2)cnt1=(double)nums1[a1];
            if(index+1==(sum-re)/2)cnt2=(double)nums1[a1];
            a1++;
        }
        else{
            if(index==(sum-re)/2)cnt1=(double)nums2[a2];
            if(index+1==(sum-re)/2)cnt2=(double)nums2[a2];
            a2++;
        }
        index++;
    }
    while(a1<nums1Size){
            if(index==(sum-re)/2)cnt1=(double)nums1[a1];
            if(index+1==(sum-re)/2)cnt2=(double)nums1[a1];
            index++;
            a1++;
        }
    while(a2<nums2Size){
            if(index==(sum-re)/2)cnt1=(double)nums2[a2];
            if(index+1==(sum-re)/2)cnt2=(double)nums2[a2];
            index++;
            a2++;
        }
        if(re)return cnt1;
        else return (cnt1+cnt2)/2.0;
}