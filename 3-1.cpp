#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int n;
    char data[10000];
    scanf("%d\n", &n);
    for (int test = 1; test <= n; test ++) {
        gets(data);
        int len = strlen(data);
        for (int i = 0; i < len; i ++) {
            if (!((data[i] >= 'A' && data[i] <= 'Z')
                  || (data[i] >= 'a' && data[i] <= 'z'))) printf("%c", data[i]);
            else {
                if (data[i] == 'Z' || data[i] == 'z') {
                    printf("%c", data[i] == 'Z' ? 'A' : 'a');
                }else{
                    printf("%c", data[i]+1);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
