#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

struct TreeNode {
    char val;
    TreeNode *left, *right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

int ValToDigit[30];

int find_pos(char* ch, int l, int r) {
    int bracket, pos, flag;
    bracket = pos = flag = 0;
    for (int i = l; i <= r; i ++) {
        if (ch[i] == '(') bracket ++;
        if (ch[i] == ')') bracket --;
        if ((ch[i] == '+' || ch[i] == '-') && bracket == 0) {
            pos = i;
            flag = 1;
        }
        if ((ch[i] == '*' || ch[i] == '/') && bracket == 0) {
            if(flag == 0) {
                pos = i;
            }
        }
    }
    return pos;
}

void remove_bracket(char* ch, int &l, int &r) {
    int flag = 1;
    if(ch[l] != '(') return ;
    for (int i = l+1; i < r; i ++) {
        if(ch[i] == ')') {
            flag = 0;
            break;
        }
    }
    if(flag) { l ++; r --; }
}

void build(TreeNode* &root, char *ch, int l, int r) {
    //cout << l << " left " << r << endl;
    if (l == r) {
        //cout << ch[l] << endl;
        TreeNode* temp = new TreeNode(ch[l]);
        root = temp;
    }else{
        remove_bracket(ch, l, r);
        int pos = find_pos(ch, l, r);
      //  cout << pos << endl;
        root = new TreeNode(ch[pos]);
        if(l < pos) build(root->left, ch, l, pos-1);
        if(r > pos) build(root->right, ch, pos+1, r);
    }
}

struct Node{
   TreeNode* Tnode;
    int depth;
    int num;
};

void print_space(int n) {
    for (int i = 0; i < n; i ++) {
        printf(" ");
    }
}

void print(TreeNode* root, int dep) {
    queue<Node> q, p;
    int dnum[100];
    memset(dnum, 0, sizeof(dnum));
    int depth = 0;
    Node temp;
    temp.Tnode = root; temp.depth = 1; temp.num = 1;
    q.push(temp);
    while (!q.empty()) {
        Node cur = q.front();
        if(cur.depth > depth) depth = cur.depth;
        dnum[cur.depth] ++;
        q.pop();
        p.push(cur);
       // printf("%c %d %d\n", cur.Tnode->val, cur.depth, cur.num);
        if (cur.Tnode->left != NULL) {
            temp.Tnode = cur.Tnode->left; temp.depth = cur.depth+1; temp.num = cur.num*2;
            q.push(temp);
        }
        if(cur.Tnode->right != NULL) {
            temp.Tnode = cur.Tnode->right; temp.depth = cur.depth+1; temp.num = cur.num*2 + 1;
            q.push(temp);
        }
    }
    int total = (1 << depth)-1;
    int top = (1+total)/2;
   // cout << depth << endl;
    //cout << total << endl;
    //cout << top << endl;
    //cout << "begin" << endl;
    int flag = 0;
    queue<int> rec;
    int wd = 1;
    while(!p.empty()){
        Node cur = p.front(); p.pop();
        int d = cur.depth;
        dnum[d] --;
        int seq = cur.num- (1<<(d-1));
       // cout << d << " " << seq << endl;
        int temp = (top >> (d-1)) + seq * (top >> ((d-2) < 0 ? 0 : d-2));
       //cout << "temp" << temp << endl;
       // cout << (top >> (d-1)) + seq * (top >> ((d-2) < 0 ? 0 : d-2))  << endl;
        print_space(temp-flag-1);
        if(cur.Tnode->left != NULL || cur.Tnode->right != NULL) {
                rec.push(temp);
        }

        flag = temp;

        printf("%c", cur.Tnode->val);

        if(dnum[d] == 0 && d != depth) {
            printf("\n");
            int inflag = 0;
            wd ++;
            while(!rec.empty()) {
                print_space(rec.front()-inflag-1-1);
                printf("/ \\");
                inflag = rec.front()+1;
                rec.pop();
            }
            printf("\n");
            flag = 0;
        }
    }
    printf("\n");
}

int val(int l, int r, char ch) {
    if(ch == '+') return l+r;
    if(ch == '-') return l-r;
    if(ch == '*') return l*r;
    if(ch == '/') return l/r;
}

int evalute(TreeNode* root){
    if(root->left == NULL && root->right == NULL) {
        return ValToDigit[root->val-'a'];
    }else{
        int lval = evalute(root->left);
        int rval = evalute(root->right);
        //cout << lval << " " << rval << endl;
        return val(lval, rval, root->val);
    }
}

void traverse(TreeNode* root) {
    if(root != NULL) {
        traverse(root->left);
        traverse(root->right);
        printf("%c", root->val);
    }
}

int main() {
    char exp[1000];
    while(scanf("%s", exp) != EOF){
        int n, x;
        char ch;
        TreeNode* root = NULL;
        scanf("%d", &n);
        getchar();
        memset(ValToDigit, 0, sizeof(ValToDigit));
        for (int i = 0; i < n; i ++) {
            scanf("%c%d", &ch, &x);
            getchar();
            ValToDigit[ch-'a'] = x;
        }
       // cout << "input" << endl;
        build(root, exp, 0, strlen(exp)-1);
       // cout << "build" << endl;
        traverse(root);
        cout << endl;
        print(root, 0);
        int ans = evalute(root);
        cout << ans << endl;
    }
    return 0;
}
/*
注意如何构建表达式树，括号如何处理
分析二叉树的性质
*/
