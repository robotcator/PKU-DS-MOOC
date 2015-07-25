#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->val);
        print(root->left);
        print(root->right);
    }
}

/*
// 指针的引用实现
void Insert(TreeNode* &root, int val) {
    if (root == NULL) {
        root = new TreeNode(val);
    }else {
        TreeNode *p = root;
        TreeNode *q = NULL;
        int flag = 1;
        while (p != NULL) {
            q = p;
            if (p->val > val) {
                p = p->left;
            }else if(p->val == val){
                flag = 0;
                break;
            }else{
                p = p->right;
            }
        }
        if (flag == 1) {
            if(q->val > val) {
                q->left = new TreeNode(val);
            }else{
                q->right = new TreeNode(val);
            }
        }
    }
}

void build(TreeNode* &root, char *data) {
    int len = strlen(data);
    int i, j;
    i = j = 0;
    while(i < len) {
        char temp[10];
        j = 0;
        while( i < len && data[i] != ' ') {
            temp[j++] = data[i];
            i ++;
        }
        temp[j++] = '\0';
        i ++;
        int val = atoi(temp);
        Insert(root, val);
    }
    print(root);
    printf("\n");
}
*/

/*
// 返回局部指针
TreeNode* Insert(TreeNode* root, int val) {
    if (root == NULL) {
        root = new TreeNode(val);
    }else {
        TreeNode *p = root;
        TreeNode *q = NULL;
        int flag = 1;
        while (p != NULL) {
            q = p;
            if (p->val > val) {
                p = p->left;
            }else if(p->val == val){
                flag = 0;
                break;
            }else{
                p = p->right;
            }
        }
        if (flag == 1) {
            if(q->val > val) {
                q->left = new TreeNode(val);
            }else{
                q->right = new TreeNode(val);
            }
        }
    }
    return root;
}

TreeNode* build(char *data) {
    TreeNode *root = NULL;
    int len = strlen(data);
    int i, j;
    i = j = 0;
    while(i < len) {
        char temp[10];
        j = 0;
        while( i < len && data[i] != ' ') {
            temp[j++] = data[i];
            i ++;
        }
        temp[j++] = '\0';
        i ++;
        int val = atoi(temp);
        root = Insert(root, val);
    }
    return root;
    print(root);
    printf("\n");
}
*/

void Insert(TreeNode** root, int val) {
    if ((*root) == NULL) {
        TreeNode* temp = new TreeNode(val);
        *root = temp;

    }else {
        TreeNode *p = *root;
        TreeNode *q = NULL;
        int flag = 1;
        while (p != NULL) {
            q = p;
            if (p->val > val) {
                p = p->left;
            }else if(p->val == val){
                flag = 0;
                break;
            }else{
                p = p->right;
            }
        }
        if (flag == 1) {
            if(q->val > val) {
                q->left = new TreeNode(val);
            }else{
                q->right = new TreeNode(val);
            }
        }
    }
}

void build(TreeNode** root, char *data) {
    int len = strlen(data);
    int i, j;
    i = j = 0;
    while(i < len) {
        char temp[10];
        j = 0;
        while( i < len && data[i] != ' ') {
            temp[j++] = data[i];
            i ++;
        }
        temp[j++] = '\0';
        i ++;
        int val = atoi(temp);
        Insert(root, val);
    }
    print(*root);
    printf("\n");
}

int main() {
    TreeNode* root = NULL;
    char data[1000];
    while(gets(data)) {
        if(strcmp(data, "") == 0) break;
        build(&root, data);
       // print(root);
    }
    return 0;
}
