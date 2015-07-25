#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
using namespace std;

const int MAXSIZE = 1e5;

int elem[MAXSIZE];
int size;

void swimup(int p, int x) {
    while (p > 0) {
        int parent = (p-1)/2;
        if (elem[parent] < x) {
            break;
        }
        elem[p] = elem[parent];
        p = parent;
    }
    elem[p] = x;
}

void insert(int x) {
    if (size >= MAXSIZE) {
        printf("OVER FLOW\n");
        return ;
    }
    int s = size ++;
    swimup(s, x);
}

void swimdown(int p, int x) {
    int half = size/2;
    while (p < half) {
        int l = 2*p+1;
        int r = 2*p+2;
        if (r < size && elem[r] < elem[l]) {
            l = r;
        }
        if (x < elem[l]) {
            break;
        }
        elem[p] = elem[l];
        p = l;
    }
    elem[p] = x;
}

int extract() {
    if (size <= 0) {
        printf("UNDER FLOW\n");
        exit(-1);
    }
    int ans = elem[0];
    int s = --size;
    swimdown(0, elem[s]);
    return ans;
}

int main() {
    int n, t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        //priority_queue<int, vector<int>, greater<int> > q;
        size = 0;
        int c, x;
        for (int i = 0; i < n; i ++) {
            scanf("%d", &c);
            if (c == 1) {
                scanf("%d", &x);
                insert(x);
            }else{
                printf("%d\n", extract());
            }
        }
    }
    return 0;
}
