#include <iostream>
#include <cstdio>
using namespace std;
int n, m, T;
int nxt[10001];
int b[10001];
int a[1000001];

inline void cal_nxt (int *b, int m){
    nxt[0] = -1;
    int j = -1;
    for (int i = 0; i < m;){
        if (j == -1 || b[i] == b[j]){
            j++;
            i++;
            nxt[i] = j;
        }else{
            j = nxt[j];
        }
    }
}

int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; ++i){
            scanf("%d", &b[i]);
        }
        cal_nxt(b, m);
        int ans = -1, j = 0;
        for (int i = 0; i < n; ++i){
            while (j != -1 && a[i] != b[j]){
                j = nxt[j]; 
            }
            j++;
            if (j == m){
                ans = i - j + 2;
                break;
            }
        }
        printf ("%d\n", ans);
    }
    return 0;
}
