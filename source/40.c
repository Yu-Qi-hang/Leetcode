#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* a,const void* b){
    return (*(int*)a-*(int*)b);
}

void dfs(int* candidates, int layers, int idx, int len, int target, int* temp, int* returnSize, int* ColumnSizes,int **ret){
    if(target==0){
        int flag=1;
        for(int i=0;i<(*returnSize);i++){
            if(ColumnSizes[i]==len){
                for(int j=0;j<len;j++){
                    flag=0;
                    if(ret[i][j]!=temp[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0)break;
            }
        }
        if(flag==0)return;
        int *ans=(int*)malloc(sizeof(int)*len);
        for(int i=0;i<len;i++)ans[i]=temp[i];
        ret[*returnSize]=ans;
        ColumnSizes[*returnSize]=len;
        (*returnSize)++;
        return;
    }
    if(idx==layers)return;
    if(len==0||temp[len-1]!=candidates[idx])
        dfs(candidates,layers,idx+1,len,target,temp,returnSize,ColumnSizes,ret);
    if(target>=candidates[idx]){
        temp[len]=candidates[idx];
        dfs(candidates,layers,idx+1,len+1,target-candidates[idx],temp,returnSize,ColumnSizes,ret);
        temp[len]='\0';
    }
    return;
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates,candidatesSize,sizeof(int),cmp);
    int *returnsize=malloc(sizeof(int));
    int **ret=(int**)malloc(sizeof(int*)*100);
    int *ColumnSizes=(int*)malloc(sizeof(int)*100);
    int *temp=(int*)malloc(sizeof(int)*50);
    memset(ColumnSizes,0,100);
    memset(temp,0,50);
    *returnsize=0;
    dfs(candidates,candidatesSize,0,0,target,temp,returnsize,ColumnSizes,ret);
    // for(int k=1;k<*returnsize;k++)
    // for(int i=0;i<(*returnsize)-k;i++){
    //     if(ColumnSizes[i]<ColumnSizes[i+1]){
    //         int size=ColumnSizes[i];
    //         ColumnSizes[i]=ColumnSizes[i+1];
    //         ColumnSizes[i+1]=size;
    //         int *change=ret[i];
    //         ret[i]=ret[i+1];
    //         ret[i+1]=change;
    //     }
    // }
    // int left=0,right=0;
    // while(left<(*returnsize)){
    //     while(ColumnSizes[right]==ColumnSizes[left]&&right<(*returnsize))right++;
    //     right--;
    //     if(left!=right){
    //         for(int offset=0;offset<ColumnSizes[left];offset++){
    //             for(int m=0;m<right-left;m++)
    //             for(int idx=left;idx<right-m;idx++){
    //                 if(ret[idx][offset]>ret[idx+1][offset]){
    //                     int *change=ret[idx];
    //                     ret[idx]=ret[idx+1];
    //                     ret[idx+1]=change;
    //                 }
    //             }
    //         }
    //     }
    //     left=right+1;
    //     right=left;
    // }
    // for(int i=1;i<(*returnsize);i++){
    //     if(ColumnSizes[i]==ColumnSizes[i-1]){
    //         int flag=0;
    //         for(int j=0;j<ColumnSizes[i];j++){
    //             if(ret[i][j]!=ret[i-1][j]){
    //                 flag=1;
    //                 break;
    //             }
    //         }
    //         if(!flag){                
    //             for(int idx=i;idx+1<*returnsize;idx++){
    //                 ret[idx]=ret[idx+1];
    //                 ColumnSizes[idx]=ColumnSizes[idx+1];
    //             }
    //             (*returnsize)--;
    //             i--;
    //         }
    //     }
    // }
    *returnSize=*returnsize;
    *returnColumnSizes=ColumnSizes;
    return ret;
}


int main(){
    int candidates[]={2,5,2,1,2};
    int target=5;
    int returnSize[]={0};
    int **returnColumnSizes;
    int **ret=combinationSum2(candidates,sizeof(candidates)/sizeof(int),target,returnSize,returnColumnSizes);
    int n=*returnSize;
    for(int i=0;i<n;i++){
        int m=(*returnColumnSizes)[i];
        for(int j=0;j<m;j++)
            printf("%d ",ret[i][j]);
        printf("\n");
    }
    return 0;
}