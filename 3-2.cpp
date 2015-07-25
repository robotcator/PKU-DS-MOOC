#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int ans;

void dfs(int in, int out, int n, int top) {
   // printf("%d %d %d\n", cnt, n, top);
    if (out == n) {
        //printf("\n");
        ans ++;
        return;
    }
    if (top == 0) {
        //printf("in ");
        if(in <n ) dfs(in+1, out, n, top+1);
    }else if(top > 0 && top < n){
        //printf("in ");
        if(in < n) dfs(in+1, out, n, top+1);
        //printf("out ");
        if(out < n) dfs(in, out+1, n, top-1);
    }else if(top == n) {
       // printf("out ");
        if(out < n) dfs(in, out+1, n, top-1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    ans = 0;
    dfs(0, 0, n, 0);
    printf("%d\n", ans);
    return 0;
}
