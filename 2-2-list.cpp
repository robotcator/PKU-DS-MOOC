#include <iostream>
#include <cstdio>
#include <list>
#include <algorithm>
#include <vector>


#define list vector

void input(std::list<std::pair<int, int> >&l) {
    int x, y;
    while (true) {
        scanf("%d %d", &x, &y);
        if (y < 0) break;
        l.push_back(std::make_pair(x, y));
    }
}

int cmp(const std::pair<int, int> l1, const std::pair<int, int> l2) {
    return l1.second > l2.second;
}
/*
void remove_dup(std::list<std::pair<int,int> > &l) {
    std::list<std::pair<int, int> >::iterator it;
    std::list<std::pair<int, int> >::iterator next;
    for (it = l.begin(), next = l.begin(), next ++; it != l.end(); it ++) {
        while (next->second == it->second) {
            it->first += next->first;
            next->first = 0; next->second = 0;
            next ++;
        }
        it = next;
        it --;
        next ++;
    }
    l.remove(std::make_pair(0, 0));
}
*/

void add(std::list<std::pair<int, int> > &l1,
        std::list<std::pair<int, int> > &l2,
        std::list<std::pair<int, int> > &l3) {
    std::list<std::pair<int, int> >::iterator it1;
    std::list<std::pair<int, int> >::iterator it2;
    std::list<std::pair<int, int> >::iterator next;
    std::pair<int, int> tmp;
    //remove_dup(l1);
    //remove_dup(l2);
    it1 = l1.begin();
    it2 = l2.begin();
    while (it1 != l1.end() && it2 != l2.end()) {
        if (it1->second > it2->second) {
           // tmp = std::make_pair(it1->first, it1->second);
           tmp = *it1;
           // check this duplicate element
            next = it1; next ++;
            while (next != l1.end() && next->second == it1->second) {
                tmp.first += next->first;
                next ++;
            }
            it1 = next;
        } else if (it1->second == it2->second) {
            tmp = std::make_pair(it1->first+it2->first, it1->second);
            // check the duplicate element
            next = it1; next ++;
            while (next != l1.end() && next->second == it1->second) {
                tmp.first += next->first;
                next ++;
            }
            it1 = next;

            next = it2; next ++;
            while (next != l2.end() && next->second == it2->second) {
                tmp.first += next->first;
                next ++;
            }
            it2 = next;
        } else {
            //tmp = std::make_pair(it2->first, it2->second);
            tmp = *it2;
            next = it2; next ++;
            while (next != l2.end() && next->second == it2->second) {
                tmp.first += next->first;
                next ++;
            }
            it2 = next;
        }
        if (tmp.first != 0) l3.push_back(tmp);
    }
    while (it1 != l1.end()) {
       // printf("%d it %d\n", it1->first, it1->second);
        //tmp = std::make_pair(it1->first, it1->second);
        tmp = *it1;
        next = it1; next ++;
        while (next != l1.end() && next->second == it1->second) {
            tmp.first += next->first;
            next ++;
        }
        it1 = next;
        if(tmp.first != 0) l3.push_back(tmp);
    }
    while (it2 != l2.end()) {
        //printf("%d it2 %d\n", it2->first, it2->second);
        //tmp = std::make_pair(it2->first, it2->second);
        tmp = *it2;
        next = it2; next ++;
        while (next != l2.end() && next->second == it2->second) {
            tmp.first += next->first;
            next ++;
        }
        it2 = next;
        if(tmp.first != 0) l3.push_back(tmp);
    }
}

void print(std::list<std::pair<int, int> > l1) {
    std::list<std::pair<int, int> >::iterator it;
    for (it = l1.begin(); it != l1.end(); it ++) {
            printf("%d %d\n", it->first, it->second);
        }
}
int main() {
    int n;
    std::list<std::pair<int, int> > l1, l2, l3;
    std::list<std::pair<int, int> >::iterator it;
    scanf("%d", &n);
    while (n --) {
        l1.clear(); l2.clear(); l3.clear();
        input(l1);
        input(l2);
        // list sort
        // l1.sort(cmp);
        // l2.sort(cmp);
        // vector sort
        sort(l1.begin(), l1.end(), cmp);
        sort(l2.begin(), l2.end(), cmp);
        add(l1, l2, l3);
        for (it = l3.begin(); it != l3.end(); it ++) {
          if(it->first != 0)  printf("[ %d %d ] ", it->first, it->second);
        }
        printf("\n");
    }
    return 0;
}
