#include <iostream>
#include <cstdio>

using namespace std;

inline int getmax(int x,int y){return x<y?y:x;}

struct node{
    int l,r;
    int max;
};
node tree[800010];
int stu[200010];

void build(int cur, const int& l,const int& r){
    if (l>r){
        return;
    }
    tree[cur].l = l;
    tree[cur].r = r;
    if (l==r){
        tree[cur].max = stu[l];
        return;
    }
    int mid = (l+r)>>1;
    int lchild = (cur<<1);
    int rchild = (cur<<1)|1;
    build(lchild, l, mid);
    build(rchild, mid+1,r);
    tree[cur].max = getmax(tree[lchild].max,tree[rchild].max);
}


void update(int cur, const int& id, const int& value){
    if (tree[cur].l> id || tree[cur].r<id){
        return;
    }
   if (tree[cur].l==id && tree[cur].r==id){
        tree[cur].max = value;
        return;
   }
    int lchild = (cur<<1);
    int rchild = (cur<<1)|1;
    if (id<=tree[lchild].r){
        update(lchild, id, value);
    }else{
        update(rchild, id, value);
    }
   tree[cur].max = getmax(tree[(cur<<1)].max, tree[(cur<<1)|1].max);
}

int query(int cur, int l, int r){
    if (tree[cur].l> r || tree[cur].r<l){
        return -1;
    }
    if (tree[cur].l>=l && tree[cur].r<=r){
        return tree[cur].max;
    }
    int m1 = -1,m2=-1;
    int lchild = (cur<<1);
    int rchild = (cur<<1)|1;
    if (tree[lchild].r>=l){
         m1 = query(lchild, l, r);
    }
    if (tree[rchild].l<=r){
        m2 = query(rchild, l, r);
    }
    return getmax(m1, m2);
}

char c[5];
int a,b;
int n,m;

int main(){
      while( cin>>n>>m ) {
        for (int i=1; i <= n; i++){
            scanf("%d", &stu[i]);
        }
        build(1,1,n);
        for(int i=0;i<m;++i){
            scanf("%s%d%d",c,&a,&b);
            if(c[0]=='Q') {printf( "%d\n",query(1,a,b) );}
            else update(1,a,b);
        }
    }
    return 0;
}
