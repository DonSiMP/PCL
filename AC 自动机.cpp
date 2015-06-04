/*
 * Author:  xtestw
 * Created Time:  2014/7/7 8:54:30
 * File Name: 2222.cpp
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
string image;
string strs[10010];
struct Node{
    Node *next[26];
    Node *fail;
    int count;
    Node(){
        fail=NULL;
        memset(next,NULL,sizeof(next));
        count=0;
    }
}*q[500010];
Node* root;


void insert(string str,Node *root)
{
    Node *p=root;
    int i=0,index;
    while (str[i]){
        index=str[i]-'a';
        if (p->next[index]==NULL) p->next[index]=new Node();
        p=p->next[index];
        i++;
    }
    p->count++;
}

void buildfail(Node *root){
    int i;
    root->fail=NULL;
    int head,tail;
    head=tail=0;
    q[head++]=root;
    while (head!=tail)
    {
        Node *tmp=q[tail++];
        Node *p=NULL;
        for(int i=0;i<26;i++)
        {
            if (tmp->next[i]!=NULL)
            {
                if (tmp==root) tmp->next[i]->fail=root;
                else{
                    p=tmp->fail;
                    while (p!=NULL)
                    {
                        if (p->next[i]!=NULL)
                        {
                            tmp->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if (p==NULL) tmp->next[i]->fail=root;
                }
                q[head++]=tmp->next[i];
            }
        }
    }
}

int query(Node *root)
{
    int i=0,cnt=0,index,len=image.size();
    Node *p=root;
    while (image[i])
    {
        index=image[i]-'a';
        while (p->next[index]==NULL && p!=root) p=p->fail;
        p=p->next[index];
        p=(p==NULL)?root:p;
        Node *tmp=p;
        while (tmp!=root && tmp->count!=-1){
            cnt+=tmp->count;
            tmp->count=-1;
            tmp=tmp->fail;
        }
        i++;
    }
    return cnt;
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("f:/in.txt","r",stdin);
#endif
  ios::sync_with_stdio(0); 
    int T;
    cin>>T;
    while (T--){
        root=new Node();
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>strs[i];
        cin>>image;
        for(int i=0;i<n;i++)
        {
            insert(strs[i],root);
        }
            buildfail(root);
        cout<<query(root)<<endl;
    }
       return 0;
}


