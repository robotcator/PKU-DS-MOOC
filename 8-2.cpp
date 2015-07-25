/*
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100+10;

int vis[maxn];
int in[maxn];
int graph[maxn][maxn];

int main() {
    int n, m, a, b;
    while(scanf("%d%d", &n, &m) != EOF) {
        memset(vis, 0, sizeof(vis));
        memset(in, 0, sizeof(in));
        memset(graph, 0, sizeof(graph));
        for (int i = 0; i < m; i ++) {
            scanf("%d%d", &a, &b);
            graph[a][b] = 1;
            in[b] ++;
        }
        int pos, flag;
        while(true) {
            flag = 0;
            pos = n+1;
            for (int i = 1; i <= n; i ++) {
                if(vis[i] == 0 && in[i] == 0) {
                    if(i < pos) {
                        pos = i;
                        flag = 1;
                    }
                }
            }
            if(!flag) break;
            printf("v%d ", pos);
            vis[pos] = 1;

            for (int i = 1; i <= n; i ++) {
                if(graph[pos][i]) {
                    in[i] --;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
*/
