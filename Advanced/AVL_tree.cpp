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

AVLTreeNode* get_successor(AVLTreeNode* root) {
    AVLTreeNode* successor = root;

    while(root->left) {
        root = root->left;
        successor = root;
    }

    return successor;
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

AVLTreeNode* delete_node(AVLTreeNode* root, int val) {
    if(!root)
        return nullptr;

    if(val < root->val) {
        root->left = delete_node(root->left, val);
    }
    else if(val > root->val) {
        root->right = delete_node(root->right, val);
    }
    else {
        if(root->left == nullptr) {
            AVLTreeNode* tmp = root->right;
            delete root;
            return tmp;
        }

        if(root->right == nullptr) {
            AVLTreeNode* tmp = root->left;
            delete root;
            return tmp;
        }

        AVLTreeNode* successor = get_successor(root->right);
        root->val = successor->val;
        root->right = delete_node(root->right, successor->val);
    }

    int bf = balanceFactor(root);

    if(bf > 1 && balanceFactor(root->left) >= 0) {
        return rightRotate(root);
    }
    else if(bf > 1 && balanceFactor(root->left) == -1) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if(bf < -1 && balanceFactor(root->right) <= 0) {
        return leftRotate(root);
    }
    else if(bf < -1 && balanceFactor(root->right) == 1) {
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

    root = delete_node(root, 30);
    std::cout<<root->val<<std::endl;
    std::cout<<root->right->val<<std::endl;


    root = delete_node(root, 60);
    std::cout<<root->val<<std::endl;
    std::cout<<root->left->val<<std::endl;
}