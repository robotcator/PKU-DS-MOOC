#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;

const int maxn = 80+5;
char exp1[maxn], exp2[maxn];
char exp[maxn*2];

void remove_space(char *s) {
    int len = strlen(s);
    int i, j;
    i = j = 0;
    while(i < len) {
        if (isspace(s[i])) {
            i ++;
        }else {
            s[j] = s[i];
            i ++;
            j ++;
        }
    }
    s[j++] = '\0';
}

void merge_exp(char *exp1, char *exp2, char *exp) {
    int len1 = strlen(exp1);
    int len2 = strlen(exp2);
    strcpy(exp, exp1);
    exp[len1] = '-';
    exp[len1+1] = '(';
    strcpy(exp+len1+2, exp2);
    exp[len1+len2+2] = ')';
    exp[len1+len2+3] = '\0';
}

int val(char c) {
    if (c == '#') return -1;
    if (c == '(') return 0;
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
}

map<string, int> add(map<string, int> &a, map<string, int> &b, char ch) {
    map<string, int> mp = a;
    map<string, int>::iterator it;
    for (it = b.begin(); it != b.end(); it ++) {
        if (ch == '+') {
            mp[it->first] += it->second;
        }else if (ch == '-'){
            mp[it->first] -= it->second;
        }
        if (mp[it->first] == 0) {
            mp.erase(it->first);
        }
    }
    return mp;
}

map<string, int> mul(map<string, int> &a, map<string, int> &b) {
    map<string, int> mp;
    map<string, int>::iterator it1, it2;
    for (it1 = a.begin(); it1 != a.end(); it1 ++) {
        for (it2 = b.begin(); it2 != b.end(); it2 ++) {
            string s = it1->first + it2->first;
            sort(s.begin(), s.end());
            mp[s] += it1->second * it2->second;
            if (mp[s] == 0) {
                mp.erase(s);
            }
        }
    }
    return mp;
}


bool evaluate(char *s) {
    int len = strlen(s);
    s[len] = '#', s[len+1] = '\0';

    char op[256];
    map<string, int> stk[256];
    int otop, ttop;
    otop = ttop = 0;
    op[otop ++] = '#';

    int i = 0;
    while (i < len+1 && s[i] != '#') {
        //cout <<"·ûºÅ" << s[i] << endl;
        map<string, int> temp;
        if (isdigit(s[i])) {
         //  cout << "Êý×Ö" << endl;
            temp[""] = s[i]-'0';
            stk[ttop ++] = temp;
        }else if(isalpha(s[i])) {
           // cout << "×ÖÄ¸" << endl;
            temp[string(1, s[i])] = 1;
            stk[ttop ++] = temp;
        }else if(s[i] == '(') {
            op[otop ++] = '(';
        }else if(s[i] == ')') {
            while (op[otop-1] != '(') {
                char ch = op[otop-1];
               // cout << "ch" << ch << " À¨ºÅÀï " << otop << endl;
                if (ch == '+' || ch == '-') {
                    temp = add(stk[ttop-2], stk[ttop-1], ch);
                    ttop -= 2;
                    stk[ttop ++] = temp;
                }else if (ch == '*') {
                    temp = mul(stk[ttop-2], stk[ttop-1]);
                    ttop -= 2;
                    stk[ttop ++] = temp;
                }
                otop --;

//               for (int l = 0; l < ttop; l ++) {
//                   for (map<string, int>::iterator it = stk[l].begin(); it != stk[l].end(); it ++) {
//                       cout << it->second << " data " << it->first << " ";
//                   }
//                   cout << endl;
//                }
            }
            otop --;
        }else if(s[i] == '+' || s[i] == '-' || s[i] == '*') {
            //cout << i << " op " << s[i] << endl;
            if (val(s[i]) <= val(op[otop-1])) {
                 //  cout << op[otop-1] << " ÔËËã " << endl;
                char ch = op[--otop];
                if (ch == '+' || ch == '-') {
                    temp = add(stk[ttop-2], stk[ttop-1], ch);
                    ttop -= 2;
                    stk[ttop ++] = temp;
                }else if (ch == '*') {
                    temp = mul(stk[ttop-2], stk[ttop-1]);
                    ttop -= 2;
                    stk[ttop ++] = temp;
                }
            }
            op[otop ++] = s[i];
//            for (int l = 0; l < ttop; l ++) {
//                for (map<string, int>::iterator it = stk[l].begin(); it != stk[l].end(); it ++) {
//                   cout << it->second << " data " << it->first << " ";
//               }
//               cout << endl;
//            }
        }
        i ++;
    }

   // cout << otop << " ji " << endl;
    while (op[otop -1] != '#') {
        char ch = op[otop-1];
        map<string, int> temp;
        if (ch == '+' || ch == '-') {
            temp = add(stk[ttop-2], stk[ttop-1], ch);
            ttop -= 2;
            stk[ttop ++] = temp;
        }else if (ch == '*') {
            temp = mul(stk[ttop-2], stk[ttop-1]);
            ttop -= 2;
            stk[ttop ++] = temp;
        }
        otop --;
    }
    //cout << otop << " ji " << endl;
    bool flag = 1;
    for (map<string, int>::iterator it = stk[0].begin(); it != stk[0].end(); it ++) {
       // cout << it->second << " " << it->first << endl;
        flag = 0;
   }
    return flag;
}

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        gets(exp1);
        gets(exp2);
        //printf("%s\n%s\n", exp1, exp2);
        remove_space(exp1);
        remove_space(exp2);
        //printf("%s\n%s\n", exp1, exp2);
        merge_exp(exp1, exp2, exp);
       // printf("%s\n", exp);
        if(evaluate(exp)) {
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
