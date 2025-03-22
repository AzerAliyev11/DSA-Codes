#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        this->val = value;
        left = nullptr;
        right = nullptr;
    }
};

void Insert(TreeNode** root, int value) {
    if(*root == nullptr) {
        *root = new TreeNode(value);
        return;
    }

    if(value < (*root)->val) {
        Insert(&(*root)->left, value);
    }
    else {
        Insert(&(*root)->right, value);
    }
}

void PrintInOrder(TreeNode* root) {
    if(root != nullptr) {
        PrintInOrder(root->left);
        cout<<root->val<<" ";
        PrintInOrder(root->right);
    }
}

TreeNode* Find(TreeNode* root, int value) {
    if(!root)
        return nullptr;

    if(value < root->val) {
        return Find(root->left, value);
    }
    else if(value > root->val) {
        return Find(root->right, value);
    }
    else
        return root;
}

TreeNode* FindMinimum(TreeNode* root) {
    if(!root)
        return nullptr;
    
    while(root->left) {
        root = root->left;
    }

    return root;
}

TreeNode* FindMaximum(TreeNode* root) {
    if(!root)
        return nullptr;

    while(root->right) {
        root = root->right;
    }

    return root;
}

int MinimumDepth(TreeNode* root) {
    if(!root)
        return 0;

    if(!root->left) {
        return MinimumDepth(root->right) + 1;
    }

    if(!root->right) {
        return MinimumDepth(root->left) + 1;
    }
    
    int leftVal = MinimumDepth(root->left);
    int rightVal = MinimumDepth(root->right);

    return min(leftVal, rightVal) + 1;
}

int main() {
    TreeNode* root = nullptr;
    Insert(&root, 12);
    Insert(&root, 8);
    Insert(&root, 4);
    Insert(&root, 16);

    PrintInOrder(root);
    cout<<endl;

    if(Find(root, 13)) {
        cout<<"Value exists inside the tree"<<endl;
    }
    else {
        cout<<"Value does not exist"<<endl;
    }

    cout<<MinimumDepth(root)<<endl;
}