#include <cstdio>
#include <cstring>
#include <iostream>

const int maxn = 200+10;

char num1[maxn], num2[maxn], ans[2*maxn];

void reverse(char *s) {
    int len = strlen(s);
    for (int i = 0; i < (int)len/2; i ++) {
        int temp = s[len-i-1];
        s[len-1-i] = s[i];
        s[i] = temp;
    }
}

void add(char *num1, char *num2, char *num3) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    char *ans = new char[len1 > len2 ? len1+1 : len2+1];
    int carry, x, y, cnt;
    cnt = carry = 0;
    while (len1 > 0 || len2 > 0) {
        if (len1 > 0) x = num1[len1-1] - '0';
        else x = 0;
        if (len2 > 0) y = num2[len2-1] - '0';
        else y = 0;
        ans[cnt ++] = (x+y+carry) % 10 + '0';
        carry = (x+y+carry) / 10;
        len1 --; len2 --;
    }
    if (carry > 0) { ans[cnt ++] = carry + '0'; }
    ans[cnt ++] = '\0';
    reverse(ans);
    strcpy(num3, ans);
}

void mul(char *num1, char *num2, char *ans) {
    if (strlen(num1) > strlen(num2)) {
        char temp[maxn];
        strcpy(temp, num1);
        strcpy(num1, num2);
        strcpy(num2, temp);
    }
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    memset(ans, 0, sizeof(ans));
    char *temp = new char[2*maxn];

    for (int i = len1-1; i >= 0; i --) {
        int x = num1[i]-'0';
        int carry = 0;
        int cnt = 0;
        for (int j = len2-1; j >= 0; j --) {
            temp[cnt] = (carry + x*(num2[j]-'0')) % 10 + '0';
            carry = (carry + x*(num2[j]-'0')) / 10;
            cnt ++;
        }
        if (carry > 0) temp[cnt ++] = carry + '0';
        temp[cnt ++] = '\0';
        reverse(temp);
        int len = strlen(temp);
        for (int j = len; j < len+(len1-1-i); j ++) {
            temp[j] = '0';
        }
        temp[len+(len-1-i)] = '\0';
        add(ans, temp, ans);
    }
}

int main() {
    scanf("%s %s", num1, num2);
   // printf("%s %s\n", num1, num2);
    mul(num1, num2, ans);
    printf("%s\n", ans);
    return 0;
}
