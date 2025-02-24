#include <iostream>

class AVLTreeNode {
public:
    int val;
    AVLTreeNode* left;
    AVLTreeNode* right;

    AVLTreeNode(int val)
    {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

int height(AVLTreeNode* root) {
    if(!root)
        return 0;
    
    int leftTreeHeight = height(root->left);
    int rightTreeHeight = height(root->right);

    return std::max(leftTreeHeight, rightTreeHeight) + 1;
}

int balanceFactor(AVLTreeNode* root) {
    if(!root)
        return 0;

    return height(root->left) - height(root->right);
}

AVLTreeNode* rightRotate(AVLTreeNode* root) {
    AVLTreeNode* x = root->left;
    AVLTreeNode* T2 = x->right;

    x->right = root;
    root->left = T2;

    return x; 
}

AVLTreeNode* leftRotate(AVLTreeNode* root) {
    AVLTreeNode* x = root->right;
    AVLTreeNode* T2 = x->left;

    x->left = root;
    root->right = T2;

    return x;
}

AVLTreeNode* insert(AVLTreeNode* root, int val) {
    if(!root) {
        return new AVLTreeNode(val);
    }

    if(val < root->val)
        root->left = insert(root->left, val);
    else if(val > root->val)
        root->right = insert(root->right, val);
    else {
        std::cout<<"No duplicates are allowed!"<<std::endl;
        return root;
    }

    int bf = balanceFactor(root);
    if(bf > 1 && val < root->left->val) {
        return rightRotate(root);
    }
    if(bf < -1 && val > root->right->val) {
        return leftRotate(root);
    }
    if(bf > 1 && val > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(bf < -1 && val < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main() {
    AVLTreeNode* root = new AVLTreeNode(30);
    root = insert(root, 40);
    root = insert(root, 35);
    root = insert(root, 60);
    root = insert(root, 80);
    std::cout<<root->right->left->val<<std::endl;

}