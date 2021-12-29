#include <vector>
#include <queue>

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

TreeNode* BST_recursive(vector<int>& nums, int left, int right)
{
    if (left > right)
        return nullptr;

    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = BST_recursive(nums, left, mid - 1);
    root->right = BST_recursive(nums, mid + 1, right);

    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) 
{    
    return BST_recursive(nums, 0, nums.size() - 1);
}


int main()
{
    vector<int> nums = { -10, -3, 0, 5, 9 };
    auto ans = sortedArrayToBST(nums);

    return 0;
}