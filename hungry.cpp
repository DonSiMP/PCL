/*
 * Author:  xtestw
 * Created Time:  2014/7/6 21:55:04
 * File Name: hungry.cpp
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
int g[1000][1001];
int vis[1010];
int pre[1010];
int m,n1,n2;
void init(){
    memset(g,0,sizeof(g));
    memset(vis,0,sizeof(vis));
    memset(pre,-1,sizeof(pre));
    scanf("%d",&m);
    if (m==0) return;
    scanf("%d%d",&n1,&n2);
    for(int i = 0; i < m ; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a][b]=1;
    }
    
}
int find(int x){
    for(int i=1;i<=n2;i++)
    {
        if (g[x][i] && !vis[i]){
            vis[i]=1;
            if (pre[i]<0 || find(pre[i]))
            {
                pre[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int hungry(){
    int ret=0;
    for(int i=1;i<=n1;i++)
    {
        memset(vis,0,sizeof(vis));
        if (find(i)){
            ret++;
        }
    }
    return ret;
}
int main() {
#ifndef ONLINE_JUDGE
  // freopen("f:/in.txt","r",stdin);
#endif
    while (true){
         init();
         if (m==0) break;
        cout<<hungry()<<endl;
    }
    return 0;
}


