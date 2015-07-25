#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int maxn = 30+5;
const int inf = 0x3f3f3f3f;

int maze[maxn][maxn];
string temp[maxn];

int dist[maxn];
int vis[maxn];
int path[maxn];

void print(int s, int t) {
    if(path[t] != -1) {
        print(s, path[t]);
        //cout << temp[path[t]] << " " << temp[t] << " " << maze[path[t]][t] << endl;
        cout << temp[path[t]] << "->(" << maze[path[t]][t] << ")->";
    }
}

void dijkstra(int s, int t, int p) {
    memset(dist, inf, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    memset(path, -1, sizeof(path));
    path[s] = -1;
    for (int i = 0; i < p; i ++) {
        if(maze[s][i] != inf) {
            dist[i] = maze[s][i];
            if(i != s) path[i] = s;
        }
    }
    vis[s] = 1;

    for (int i = 0; i < p; i ++) {
        int mmin = inf;
        int next = -1;
        for (int j = 0; j < p; j ++) {
        //        cout << dist[j] << " ";
            if(dist[j] < mmin && vis[j] == 0) {
                mmin = dist[j];
                next = j;
            }
        }
      //  cout << endl;
        if(mmin == inf) break;
        vis[next] = 1;
        for (int j = 0; j < p; j ++) {
            if(maze[next][j] != inf && dist[next] + maze[next][j] < dist[j]) {
                dist[j] = dist[next] + maze[next][j];
                path[j] = next;
            }
        }
    }
    //printf("%d\n", dist[t]);
    print(s, t);
    cout << temp[t] << endl;
}

int main() {
    int r, p, q, cost;
    string x, y;
    map<string, int> mp;
    while(scanf("%d", &p) != EOF) {
        mp.clear();
        memset(maze, inf, sizeof(maze));
        for (int i = 0; i < p; i ++) {
            cin >> x;
            temp[i] = x;
            mp[x] = i;
            maze[i][i] = 0;
        }
        scanf("%d", &q);
        for (int i = 0; i < q; i ++) {
            cin >> x >> y >> cost;
            int a = mp[x];
            int b = mp[y];
           // cout << a << " " << b << " " << cost << endl;
           if(maze[a][b] > cost)
                maze[a][b] = maze[b][a] = cost;
        }
        scanf("%d", &r);
        for (int i = 0; i < r; i ++) {
            cin >> x >> y;
            int a = mp[x];
            int b = mp[y];
            if(a != b) dijkstra(a, b, p);
            else cout << y << endl;
        }
    }
    return 0;
}
