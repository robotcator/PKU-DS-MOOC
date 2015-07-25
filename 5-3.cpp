#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node{
    char val;
    struct node *l, *r;
};

int main() {
    int t;
    char data[100];
    scanf("%d", &t);
    for (int test = 1; test <= t; test ++) {
        while(scanf("%s", data)) {
           if(strcmp(data, "0") == 0) break;

        }
    }
    return 0;
}
