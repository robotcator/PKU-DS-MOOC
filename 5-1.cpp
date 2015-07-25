#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxn = 65535+5;

int in[maxn];
int tail[maxn];

int convert(char *s, int *in) {
    int len = strlen(s);
    int i, k;
    i = k = 0;
    while( i < len ) {
        char temp[maxn];
        int j = 0;
        while (s[i] != ' ' && i < len) {
            temp[j++] = s[i];
            i ++;
        }
        i ++;
        temp[j++] = '\0';
        in[k++] = atoi(temp);
    }
    return k;
}

void build(int l1, int r1, int l2, int r2) {
    //printf("%d %d %d %d\n", l1, r1, l2, r2);
    if (r1 >= l1 && r2 >= l2)
        printf("%d ", tail[r2]);

    if (r1 > l1 && r2 > l2) {
        int pos = -1;
        for (int i = l1; i <= r1; i ++) {
            if (in[i] == tail[r2]) {
                pos = i;
                break;
            }
        }
       // cout << l1 << " " << pos-1 << " " << l2 << " " << l2+pos-l2-1 << endl;
        build(l1, pos-1, l2, l2+pos-l1-1);
        build(pos+1, r1, r2-r1+pos, r2-1);
    }
}

int main() {
    char s[2*maxn];
    gets(s);
    int n = convert(s, in);
    gets(s);
    convert(s, tail);
    build(0, n-1, 0, n-1);
    printf("\n");
    return 0;
}
