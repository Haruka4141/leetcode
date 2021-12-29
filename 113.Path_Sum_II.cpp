#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void path_sum_recursive(TreeNode* root, int targetSum, vector<vector<int>>& ret, vector<int>& path)
{
    path.push_back(root->val);
    if (!root->left && !root->right && targetSum == root->val)
    {
        ret.push_back(path);
        path.pop_back();        //remember to pop!
        return;
    }

    if (root->left)             //I think this can reduce 1 recursive
        path_sum_recursive(root->left, targetSum - root->val, ret, path);
    if (root->right)
        path_sum_recursive(root->right, targetSum - root->val, ret, path);
    path.pop_back();

}
vector<vector<int>> pathSum(TreeNode* root, int targetSum)
{
    vector<vector<int>> ret;
    if (root == nullptr)
        return ret;
    vector<int> path;

    path_sum_recursive(root, targetSum, ret, path);

    return ret;
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    auto ans = pathSum(root, 22);

    return 0;
}