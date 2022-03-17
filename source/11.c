#include<stdio.h>
#define UP 100001
int maxArea(int* height, int heightSize);
int main(){
    int heightsize;
    int height[UP]={0};
    scanf("%d",&heightsize);
    for(int i=0;i<heightsize;i++)scanf("%d",&height[i]);
    printf("%d",maxArea(height,heightsize));
    return 0;
}
int maxArea(int* height, int heightSize){
    int h1=height[0],h2=height[heightSize-1];
    int h=(h1<h2)?h1:h2;
    int area=(heightSize-1)*h;
    int i=0,j=heightSize-1;
    while(j-i+1>=2){
        if(h1<h2){
            while(height[i]<=h1&&i<j)i++;
            h1=height[i];
        }
        else{
            while(height[j]<=h2&&j>i)j--;
            h2=height[j];
        }
        h=(h1<h2)?h1:h2;
        int area2=h*(j-i);
        if(area<area2)area=area2;
    }    
    return area;
}

// int maxArea(int* height, int heightSize){
//     if(heightSize<2)return 0;
//     int h=(height[0]<height[heightSize-1])?height[0]:height[heightSize-1];
//     int area=(heightSize-1)*h;
//     int i=0,j=heightSize-1;
//     if(height[0]<height[heightSize-1])
//         while(height[i]<=height[0]&&i<j)i++;
//     else
//         while(height[j]<=height[heightSize-1]&&j>i)j--;
//     int area2=maxArea(&height[i],j-i+1);
//     return (area2>area)?area2:area;
// }