#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Compare{
    public:
    bool operator() (const TreeNode *a, const TreeNode *b) {
        return a->val > b->val ;
    }
};

void build(TreeNode* &root, priority_queue<TreeNode*, vector<TreeNode*>, Compare> p) {
    TreeNode* a, *b, *c;
    while(!p.empty()) {
        a = p.top(); p.pop();
        if(p.empty()) {
            root = a;
            break;
        }
        b = p.top(); p.pop();
        c = new TreeNode(a->val+b->val);
        c->left = a; c->right = b;
        p.push(c);
    }
}

void calculate(TreeNode* root, int depth, int &ans) {
    if(root->left == NULL && root->right == NULL) {
        ans += depth*root->val;
    }else{
        if(root->left) calculate(root->left, depth+1, ans);
        if(root->right) calculate(root->right, depth+1, ans);
    }
}

int main() {
    int n, x;
    priority_queue<TreeNode*, vector<TreeNode*>, Compare> p;
    while(scanf("%d", &n) != EOF) {
        TreeNode* temp, *root;
        root = temp = NULL;
        for (int i = 0; i < n; i ++) {
            scanf("%d", &x);
            temp = new TreeNode(x);
            p.push(temp);
        }
        build(root, p);
        int ans = 0;
        calculate(root, 0, ans);
        cout << ans << endl;
    }
    return 0;
}
