#include <cstdio>
#include <cstring>

const int maxn = 1e6;
char data[maxn];
int fail[maxn];

void get_fail(char *s, int n) {
    fail[1] = 0;
    int j = 0;
    for (int i = 2; i <= n; i ++) {
        while (s[i] != s[j+1] && j) j = fail[j];
        if (s[i] == s[j+1]) j ++;
        fail[i] = j;
    }
    for (int i = 0; i <= n; i ++) {
        printf("%d ", fail[i]);
    }
    printf("\n");
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        scanf("%s", data+1);
        get_fail(data, n);
        for (int i = 2; i <= n; i ++) {
            if (i % (i-fail[i]) == 0) {
                printf("%d %d\n", i, i-fail[i]+1);
            }
        }
    }
    return 0;
}
