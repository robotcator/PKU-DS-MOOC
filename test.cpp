#include <cstdio>

int s(int * a, int * b) {
    printf("%p -- %p\n", a, b);
    printf("%d --- %d\n", *a, *b);
    int *temp = a;
    a = b;
    b = temp;
    printf("%p -- %p\n", a, b);
    printf("%d --- %d\n", *a, *b);
}

int t(int &a, int &b) {
    printf("%p == %p\n", &a, &b);
    int temp = a;
    a = b;
    b = temp;
    printf("%p == %p\n", &a, &b);
}

int main() {
    int a, b;
    a = 10;
    b = 20;
    printf("%d %d\n", a, b);
    printf("%p %p\n", &a, &b);
    s(&a, &b);
    printf("%d %d\n", a, b);
    printf("%p %p\n", &a, &b);

    int x, y;
    x = 10;
    y = 20;
    printf("%d %d\n", x, y);
    printf("%p %p\n", &x, &y);
    t(a, b);
    printf("%d %d\n", y, x);
    printf("%p %p\n", &x, &y);
}
