#include <vector>
#include <unordered_map>

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

TreeNode* buildTree_recursive(vector<int>& postorder, int& post_index, unordered_map<int, int>& inorder_map, int left, int right)
{
    if (left > right)
        return nullptr;

    int val = postorder[post_index];
    int root_index = inorder_map[val];
    TreeNode* root = new TreeNode(val);
    --post_index;
    
    root->left = buildTree_recursive(postorder, post_index, inorder_map, left, root_index - 1);
    root->right = buildTree_recursive(postorder, post_index, inorder_map, root_index + 1, right);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
    unordered_map<int, int> inorder_map;
    int post_index = postorder.size() - 1;

    for (int i = 0; i < inorder.size(); ++i)
    {
        inorder_map[inorder[i]] = i;
    }

    return buildTree_recursive(postorder, post_index, inorder_map, 0, postorder.size() - 1);
}

int main()
{
    vector<int> postorder = { 9, 15, 7, 20, 3 };
    vector<int> inorder = { 9, 3, 15, 20, 7 };

    auto ans = buildTree(inorder, postorder);

    return 0;
}