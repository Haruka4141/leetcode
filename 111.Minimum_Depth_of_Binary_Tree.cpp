struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int minDepth(TreeNode* root) 
{
    if (!root->left && !root->right)
        return 1;
    
    if (!root->left)
        return minDepth(root->right) + 1;

    if (!root->right)
        return minDepth(root->left) + 1;
    
    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if (left < right)
        return left;
    else
        return right;
}

int main()
{

    return 0;
}