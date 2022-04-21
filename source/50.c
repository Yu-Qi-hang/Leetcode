#include<stdio.h>
// double myPow(double x, int n){
//     // if(x==1.0)return 1.0;
//     double ret=1.0;
//     if(n<0){
//         for(int i=0;i>n;i--){
//             ret/=x;
//         }
//     }
//     else{
//         for(int i=0;i<n;i++){
//             ret*=x;
//         }
//     }
//     return ret;
// }
double myPow(double x, int n){
    if(n==0)return 1.0;
    double ret=1.0;
    if(n<0){
        if(n%2)return 1/x*myPow(x*x,(n+1)/2);
        else return myPow(x*x,n/2);
    }
    else{
        if(n%2)return x*myPow(x*x,(n-1)/2);
        else return myPow(x*x,n/2);
    }
    return ret;
}
int main(){
    double x;
    int n;
    scanf("%lf %d",&x,&n);
    printf("%.5lf",myPow(x,n));
    return 0;
}