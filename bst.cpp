#include<iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int val, TreeNode* prev)
    {
        this->val = val;
        left = NULL;
        right = NULL;
        parent = prev;
    }
};

TreeNode* InsertwithParent(TreeNode** root, int val)
{
    if(!(*root))
    {
        *root = new TreeNode(val, NULL);
        return *root;
    }

    if(val < (*root)->val)
    {
        TreeNode* leftChild = InsertwithParent(&((*root)->left), val);
        leftChild->parent = *root;
    }
    else
    {
        TreeNode* rightChild = InsertwithParent(&((*root)->right), val);
        rightChild->parent = *root;
    }

    return *root;
}

TreeNode* FindElement(TreeNode* root, int val)
{
    if(!root)
        return NULL;

    if(val == root->val)
        return root;

    if(val < root->val)
    {
        return FindElement(root->left, val);
    }
    else
    {
        return FindElement(root->right, val);
    }
}

void InOrderTraversal(TreeNode* root)
{
    if(root)
    {
        InOrderTraversal(root->left);
        cout<<root->val<<" ";
        InOrderTraversal(root->right);
    }
}

TreeNode* MinimumElement(TreeNode* root)
{
    if(!root)
        return NULL;

    if(!root->left)
        return root;

    return MinimumElement(root->left);
}

TreeNode* MaximumElement(TreeNode* root)
{
    if(!root)
        return NULL;

    if(!root->right)
        return root;

    return MaximumElement(root->right);
}

TreeNode* NextElement(TreeNode* root)
{
    if(!root)
        return NULL;

    if(root->right)
        return MinimumElement(root->right);

    TreeNode* parent = root->parent;
    while(parent != NULL && root == parent->right)
    {
        root = parent;
        parent = parent->parent;
    }

    return parent;
}

TreeNode* PrevElement(TreeNode* root)
{
    if(!root)
        return NULL;

    if(root->left)
        return MaximumElement(root->left);

    TreeNode* parent = root->parent;
    while(parent != NULL && root == parent->left)
    {
        root = parent;
        parent = parent->parent;
    }

    return parent;
}

int MinDepth(TreeNode* root)
{
    if(!root)
        return 0;

    if(!root->left)
        return MinDepth(root->right) + 1;

    if(!root->right)
        return MinDepth(root->left) + 1;

    int leftDepth = MinDepth(root->left);
    int rightDepth = MinDepth(root->right);

    return min(leftDepth, rightDepth) + 1;
}

int MaxDepth(TreeNode* root)
{
    if(!root)
        return 0;

    return max(MaxDepth(root->left), MaxDepth(root->right)) + 1;
}

int SumofLeftLeaves(TreeNode* root)
{
    if(!root)
        return 0;

    if(root->left && !root->left->left && !root->left->right)
    {
        return root->left->val + SumofLeftLeaves(root->right);
    }

    return SumofLeftLeaves(root->left) + SumofLeftLeaves(root->right);
}

int SumofRightLeaves(TreeNode* root)
{
    if(!root)
        return 0;

    if(root->right && !root->right->left && !root->right->right)
    {
        return root->right->val + SumofRightLeaves(root->left);
    }

    return SumofRightLeaves(root->left) + SumofRightLeaves(root->right);
}

int main()
{
    TreeNode* tree = NULL;
    InsertwithParent(&tree, 9);
    InsertwithParent(&tree, 4);
    InsertwithParent(&tree, 16);
    InsertwithParent(&tree, 2);
    InsertwithParent(&tree, 8);
    InsertwithParent(&tree, 12);
    InsertwithParent(&tree, 20);

    InOrderTraversal(tree);
    cout<<endl;

    if(FindElement(tree, 13))
    {
        cout<<"Exists"<<endl;
    }
    else
    {
        cout<<"Does not exist"<<endl;
    }

    cout<<"Minimum element is the node with the value of "<<MinimumElement(tree)->val<<endl;
    cout<<"Maximum element is the node with the value of "<<MaximumElement(tree)->val<<endl;

    cout<<NextElement(FindElement(tree, 12))->val<<endl;
    cout<<PrevElement(FindElement(tree, 12))->val<<endl;

    cout<<"Minimum Depth: "<<MinDepth(tree)<<endl;
    cout<<"Maximum Depth: "<<MaxDepth(tree)<<endl;

    cout<<"Sum of left leaves: "<<SumofLeftLeaves(tree)<<endl;
    cout<<"Sum of right leaves: "<<SumofRightLeaves(tree)<<endl;


}