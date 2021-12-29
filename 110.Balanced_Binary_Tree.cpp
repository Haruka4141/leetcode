struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


//max_depth transform, adding bool reference as cond
//https://leetcode.com/problems/balanced-binary-tree/discuss/774578/C%2B%2B-Bottom-up-solution-O(N)-solution
int check_balance(TreeNode* root, bool& cond)
{
    if (root == nullptr || !cond)
        return 0;
    
    int left = check_balance(root->left);
    int right = check_balance(root->right);
    int dis = left - right;
    
    if (dis > 1 || dis < -1)
        cond = false;

    if (left > right)
        return left + 1;
    else
        return right + 1;
}

bool isBalanced(TreeNode* root)
{

    bool ret = true;

    if (root == nullptr)
        return ret;

    check_balance(root, ret);
    
    return ret;
}

bool isBalanced(TreeNode* root) 
{
    





}