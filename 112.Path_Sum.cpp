struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//submission, faster
bool hasPathSum(TreeNode* root, int targetSum) 
{
    if (root == nullptr)
        return false;

    if (!root->left && !root->right)
        return (targetSum == root->val);

    bool ans = 0;

    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

//pass
void pathsum_recursive(TreeNode* root, bool& ret, int& targetSum, int& currSum)
{
    if (!root)
        return;

    currSum += root->val;
    if (!root->left && !root->right && currSum == targetSum)
    {
        ret = true;
        return;
    }
        
    pathsum_recursive(root->right, ret, targetSum, currSum);
    pathsum_recursive(root->left, ret, targetSum, currSum);
    currSum -= root->val;

}

bool hasPathSum_v1(TreeNode* root, int targetSum) 
{
    bool ret = false;
    int currSum = 0;
    pathsum_recursive(root, ret, targetSum, currSum);
    return ret;
}