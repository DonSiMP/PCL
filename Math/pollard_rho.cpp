/*
 * Author:  xtestw
 * Created Time:  2014/6/9 16:00:28
 * File Name: pollard_rho.cpp
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
long long fac[100];
int tot=0;
long long ll_multi(long long a,long long b,long long mod){
    long long ret=0;
    a=a%mod;
    for(;b;a=(a<<1)%mod,b=b>>1){
        if(b&1) ret=(ret+a)%mod;
    }
    return ret;
}

long long pow_mod(long long a,long long b,long long mod){
    long long ret=1;
    while(b){
        if (b&1) ret=ll_multi(ret,a,mod);
        b>>=1;
        a=ll_multi(a,a,mod);
    }
    return ret;
}
int miller_rabin(long long  n){
    if( n<2) return 0;
    if(n==2) return 1;
    if (n&1==0) return 0;
    long long u=n-1;
    int sum=4;
    int t=0;
    while (u&1==0){u>>=1;t++;}
    while(sum--){    
        long long a=rand()%(n-1)+1;
        long long ans=pow_mod(a,u,n);
        long long pre=1;
        for(int i=0;i<t;i++)
        {
            ans=ll_multi(ans,ans,n);
            if (ans==1 && pre!=1 && pre!=n-1){
                return 0;
            }
            pre=ans;
        }
        if(ans!=1) return 0;
    }
    return 1;
}

long long gcd(long long a,long long b){
    if (a<0) return gcd(-a,b);
    if (b==0) return a;
    while  (b){
        long long tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}
long long pollard_rho(long long n,long long c){
    long long x=rand()%n,k=2;
    long long y=x;
    long long i=0;
    while (1){
        i++;
        x=(ll_multi(x,x,n)+c)%n;
        long long p=gcd(y-x,n);
        if (p!=1 && p!=n) return p;
        if (x==y) return n;
        if (i==k) {y=x;k+=k;}
    }
}
void get_facs(long long n)
{
    if (miller_rabin(n)){
        fac[tot++]=n;
        return;
    }
    long long p=n;
    while (p>=n) p=pollard_rho(n,rand()%(n-1)+1);
    get_facs(p);
    get_facs(n/p);
}
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("f:/in.txt","r",stdin);
    #endif
    long long n;
    while (scanf("%I64d",&n)!=EOF){
        memset(fac,0,sizeof(fac));
        tot=0;
        get_facs(n);
        for(int i=0;i<tot;i++)
        {
            cout<<fac[i]<<endl;
        }
    }
    return 0;
}

