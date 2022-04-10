#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* a,const void* b){
    return (*(int*)a-*(int*)b);
}

void dfs(int* candidates, int layers, int idx, int len, int target, int* temp, int* returnSize, int* ColumnSizes,int **ret){
    if(idx==layers)return;
    if(target==0){
        int *ans=(int*)malloc(sizeof(int)*len);
        for(int i=0;i<len;i++)ans[i]=temp[i];
        ret[*returnSize]=ans;
        ColumnSizes[*returnSize]=len;
        (*returnSize)++;
        return;
    }
    dfs(candidates,layers,idx+1,len,target,temp,returnSize,ColumnSizes,ret);
    if(target>=candidates[idx]){
        temp[len]=candidates[idx];
        dfs(candidates,layers,idx,len+1,target-candidates[idx],temp,returnSize,ColumnSizes,ret);
        temp[len]='\0';
    }
    return;
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    // qsort(candidates,candidatesSize,sizeof(int),cmp);
    int *returnsize=malloc(sizeof(int));
    int **ret=(int**)malloc(sizeof(int*)*150);
    int *ColumnSizes=(int*)malloc(sizeof(int)*150);
    int *temp=(int*)malloc(sizeof(int)*500);
    memset(ColumnSizes,0,150);
    memset(temp,0,500);
    *returnsize=0;
    dfs(candidates,candidatesSize,0,0,target,temp,returnsize,ColumnSizes,ret);
    *returnSize=*returnsize;
    *returnColumnSizes=ColumnSizes;
    return ret;
}


int main(){
    int candidates[]={2,3,6,7};
    int target=7;
    int returnSize[]={0};
    int **returnColumnSizes;
    int **ret=combinationSum(candidates,sizeof(candidates)/sizeof(int),target,returnSize,returnColumnSizes);
    int n=*returnSize;
    for(int i=0;i<n;i++){
        int m=(*returnColumnSizes)[i];
        for(int j=0;j<m;j++)
            printf("%d ",ret[i][j]);
        printf("\n");
    }
    return 0;
}