#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int value) {
        this->val = value;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

TreeNode* Insert(TreeNode** root, int value) {
    if(*root == nullptr) {
        *root = new TreeNode(value);
        return *root;
    }

    if(value < (*root)->val) {
        TreeNode* leftChild = Insert(&(*root)->left, value);
        leftChild->parent = *root;
    }
    else {
        TreeNode* rightChild = Insert(&(*root)->right, value);
        rightChild->parent = *root;
    }

    return *root;
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
    
    int left = MinimumDepth(root->left);
    int right = MinimumDepth(root->right);

    return min(left, right) + 1;
}

TreeNode* NextElement(TreeNode* root) {
    if(!root)
        return nullptr;

    if(root->right) {
        return FindMinimum(root->right);
    }

    TreeNode* p = root->parent;
    while(p != nullptr && root != p->left) {
        root = p;
        p = root->parent;
    }

    return p;
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

    cout<<NextElement(Find(root, 4))->val<<endl;
}