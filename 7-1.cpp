#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int sigma_size = 26+1;

char rec[sigma_size];
int deg[sigma_size];
int vis[sigma_size];
vector<int> G[sigma_size];
vector<int> ans;

void dfs(int u) {
    for (int i = 0; i < G[u].size(); i ++) {
        int v = G[u][i];
        dfs(v);
    }
    ans.push_back(u);
}

int main() {
    int n;
    char data[100];
    scanf("%d\n", &n);
    for (int i = 0; i < n; i ++) {
        gets(data);
        //printf("%s\n", data);
        int cnt = 0;
        for (int j = 0; j < strlen(data); j += 4) {
            rec[cnt] = data[j];
            deg[cnt] = data[j+2]-'0';
            cnt ++;
        }
        G[0].push_back(rec[0]-'A'+1);
        memset(vis, 0, sizeof(vis));
        for (int j = 0; j < cnt; j ++) {
           // printf("%c %d\n", rec[j], deg[j]);
            int k = j+1;
            while(deg[j] > 0 && k < cnt) {
                if(!vis[k]) {
                    G[rec[j]-'A'+1].push_back(rec[k]-'A'+1);
                    vis[k] = 1;
                    deg[j] --;
                }
                k ++;
            }
        }
    }

//    for (int i = 0; i < sigma_size; i ++) {
//        if(G[i].size()) printf("%c ", i+'A'-1);
//        for (int j = 0; j < G[i].size(); j ++) {
//            printf("%c ", G[i][j]+'A'-1);
//        }
//        if(G[i].size()) cout << endl;
//    }
    ans.clear();
    dfs(0);
    for (int i = 0; i < ans.size()-1; i ++) {
        printf("%c ", ans[i]+'A'-1);
    }
    return 0;
}
