/*
 * Author:  xtestw
 * Created Time:  2014/6/9 14:35:36
 * File Name: miller_rabin.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <time.h>
using namespace std;
const int maxint = -1u>>1;
long long ll_multi(long long a,long long b,long long mod){
    a=a%mod;
    long long ret=0;
    for(;b;a=(a<<1)%mod,b>>=1){
        if (b&1) ret=(ret+a)%mod;
    }
    return ret;
}

long long pow_mod(long long a,long long b,long long mod){
    long long ret=1;
    while(b!=0){
        if (b&1) ret=ll_multi(ret,a,mod);
        b>>=1;
        a=ll_multi(a,a,mod);
    }
    return ret;
}
int miller_rabin(long long n){
    if (n<2) return 0;
    if (n==2) return 1;
    if (!(n&1)) return 0;
    int sum=4;
    srand(time(0));
    while(sum--){
        long long a=rand()%(n-1)+1;
        int t=0;
        long long u=n-1;
        while (!(u&1)){ t++; u>>=1;}
        long long ans=pow_mod(a,u,n);
        long long pre=1,cur=ans;
       for(int i=0;i<t;i++)
       {
           cur=ll_multi(cur,cur,n); 
           if (cur==1 && pre!=1 && pre!=n-1){return false;}
           pre=cur;
       }
       if (cur!=1) return false;
    }
    return true;
}


int main() {
    #ifndef ONLINE_JUDGE
//        freopen("f:/in.txt","r",stdin);
    #endif
    long long n;
    while (scanf("%I64d",&n)!=EOF){
        if (miller_rabin(n)){
            cout<<"YES"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}

