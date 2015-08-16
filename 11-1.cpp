#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <hash_map>
#include <algorithm>

using namespace std;

const int maxn = 1e4;
int s[maxn];

int main() {
    int m, n, x, mm;
    while(scanf("%d%d", &m, &n) != EOF) {
        priority_queue<int, vector<int>, greater<int> > q;
        for(int i = 0; i < m; i ++) {
            scanf("%d", &s[i]);
        }
        for(int i = 0; i < n; i ++) {
            scanf("%d", &x);
            q.push(x);
        }
        int cnt = 0;
        int newm = 0;
        while(!q.empty() && cnt < m) {
            x = q.top(); q.pop();
            cout << x << " " ;
            if(s[cnt] > x) q.push(s[cnt]);
            else s[newm++] = s[cnt];
            cnt ++;
        }
        cout << endl;
        for(int i = 0; i < newm; i ++) {
            cout << s[i] << endl;
        }
    }
    return 0;
}
