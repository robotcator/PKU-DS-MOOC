#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef struct node {
    int x, y;
    struct node *next;
}Lnode, *linklist;

void Insert(linklist &l, int x, int y) {
    if (l == NULL) {
        l = (linklist)malloc(sizeof(Lnode));
        l->x = x; l->y = y;
        l->next = NULL;
    } else {
        linklist temp = (linklist)malloc(sizeof(Lnode));
        temp->x = x; temp->y = y;
        temp->next = NULL;

        linklist q = l;
        linklist p = NULL;
        while (q->next != NULL && q->y > y) {
            p = q;
            q = q->next;
        }
        if (q->next == NULL) {
            // only one node
            if (q->y > y)
                q->next = temp;
            else if(q->y == y)
                q->x = q->x + x;
            else {
                l = temp;
                temp->next = q;
            }
        }else if (q->next != NULL && q->y == y) {
            q->x = q->x + x;
        }else{
            if (p == NULL) {
                p = q;
                l = temp;
                temp->next = p;
            } else {
                p->next = temp;
                temp->next = q;
            }
        }
    }
}

void input(linklist &l) {
    int x, y;
    while (true) {
        scanf("%d%d", &x, &y);
        if (y < 0) break;
        Insert(l, x, y);
    }

    linklist p = l;
    while (p != NULL) {
        printf("%d %d ", p->x, p->y);
        p = p->next;
    }
    printf("\n");
}

void add(linklist l1, linklist l2, linklist &l3) {
    linklist q1 = l1;
    linklist q2 = l2;
    linklist q3 = l3;
    while (q1 != NULL && q2 != NULL) {
        linklist temp = (linklist)malloc(sizeof(Lnode));
        if (q1->y > q2->y) {
            temp->x = q1->x; temp->y = q1->y;
            temp->next = NULL;
            q1 = q1->next;
        } else if (q1->y == q2->y) {
            temp->x = q1->x + q2->x;
            temp->y = q1->y;
            temp->next = NULL;
            q1 = q1->next;
            q2 = q2->next;
        } else {
            temp->x = q2->x; temp->y = q2->y;
            temp->next = NULL;
            q2 = q2->next;
        }
        if (l3 == NULL) {
            l3 = temp;
            q3 = l3;
        }else {
            q3->next = temp;
            q3 = q3->next;
        }
    }
    if (q1 != NULL) {
        linklist temp = (linklist)malloc(sizeof(Lnode));
        temp->x = q1->x; temp->y = temp->y;
        temp->next = NULL;
        if (q1->y == q3->y) {
            q3->x = q3->x + q1->x;
        } else {
            q3->next = temp;
            q3 = q3->next;
        }
        q1 = q1->next;
    }
    if (q2 != NULL) {
        linklist temp = (linklist)malloc(sizeof(Lnode));
        temp->x = q2->x; temp->y = q2->y;
        temp->next = NULL;
        if (q3->y == q2->y) {
            q3->x = q3->x + q2->x;
        } else {
            q3->next = temp;
            q3 = q3->next;
        }
        q2 = q2->next;
    }
}

int main() {
    int t;
//    freopen("in.txt", "r", stdin);
//    freopen("out1.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        linklist l1, l2, l3;
        l1 = l2 = l3 = NULL;
        input(l1);
        input(l2);
        add(l1, l2, l3);
        linklist p = l3;
        while (p != NULL) {
            if(p->x != 0)  printf("[ %d %d ] ", p->x, p->y);
            p = p->next;
        }
        //if (p->x != 0) printf("[ %d %d ]", p->x, p->y);
        printf("\n");
    }
    return 0;
}
