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

//submission. using map to reduce root search time in inorder vector space  (Space: O(N)
TreeNode* do_build(vector<int>& preorder, int& index, unordered_map<int, int>& mp, int left, int right) 
{
    if (left > right) 
    {
        return NULL;
    }
    int val = preorder[index];
    int mid = mp[val];
    TreeNode* root = new TreeNode(val);
    index++;

    root->left = do_build(preorder, index, mp, left, mid - 1);
    root->right = do_build(preorder, index, mp, mid + 1, right);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    unordered_map<int, int> mp;
    int index = 0;
    for (int i = 0; i < inorder.size(); i++) 
    {
        mp[inorder[i]] = i;
    }
    return do_build(preorder, index, mp, 0, preorder.size() - 1);
}

//Time: O(N)?
//https://medium.com/@harycane/construct-binary-tree-from-preorder-and-inorder-traversal-2b6797cd209d
TreeNode* buildTree_recursive(vector<int>& preorder, vector<int>& inorder, int pre_start, int in_start, int in_end)
{
    if (pre_start > preorder.size() - 1 || in_start > in_end)
        return nullptr;

    TreeNode* root = new TreeNode(preorder[pre_start]);

    int in_index = 0;

    for (int i = in_start; i <= in_end; ++i)        //need searching
    {
        if (inorder[i] == root->val)
            in_index = i;
    }

    root->left = buildTree_recursive(preorder, inorder, pre_start + 1, in_start, in_index - 1);
    root->right = buildTree_recursive(preorder, inorder, pre_start + (in_index - in_start + 1), in_index + 1, in_end);
                                                                    //    ^
                                                                    //    3 9 20 15 7
                                                                    //  9 3 15 20 7
                                                                    //  pre_start(20) = 0 + (1 - 0 + 1)
    return root;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    return buildTree_recursive(preorder, inorder, 0, 0, inorder.size() - 1);
}

int main()
{
    vector<int> preorder = { 3, 9, 20, 15, 7 };
    vector<int> inorder = { 9, 3, 15, 20, 7 };

    auto ans = buildTree(preorder, inorder);

    return 0;
}

//[1,2] fail
TreeNode* buildTree_v1(vector<int>& preorder, vector<int>& inorder)
{
    if (preorder.empty())
        return nullptr;

    auto iter = inorder.begin();
    while (iter != inorder.end())
    {
        if (*iter == preorder.front())
            break;
        ++iter;
    }

    bool is_inorder_head = false;

    if (iter == inorder.begin())
        is_inorder_head = true;

    TreeNode* root = new TreeNode(preorder.front());
    preorder.erase(preorder.begin());
    inorder.erase(iter);

    if (!is_inorder_head)
    {
        root->left = buildTree(preorder, inorder);
        root->right = buildTree(preorder, inorder);
    }

    return root;
}