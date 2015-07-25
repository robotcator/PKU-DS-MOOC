#include <iostream>
#include <list>
#include <cstdio>

int jesophe(int n, int m) {
    std::list<int> l;
    std::list<int>::iterator it;
    for (int i = 1; i <= n; i ++) {
        l.push_back(i);
    }
    it = l.begin();
    while (l.size() != 1) {
        int x = m % l.size();
        if (x == 0) x += l.size();
        while (--x) {
            it ++;
            if (it == l.end()) it = l.begin();
        }
        it = l.erase(it);
        if (it == l.end()) it = l.begin();
    }
    return *l.begin();
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int ans = jesophe(n, m);
    printf("%d\n", ans);
    return 0;
}
