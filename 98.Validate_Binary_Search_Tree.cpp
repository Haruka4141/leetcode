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
/*
          5
(-inf,5) / \ (5, inf)
        4   6
    (5, 6) / \ (6, inf)
          3   7

*/
//submission
bool isValidBST(TreeNode* root) 
{
    return aux(root, LONG_MIN, LONG_MAX);
}

bool aux(TreeNode* root, long minVal, long maxVal)
{
    if (root == NULL)
        return true;
    if (root->val >= maxVal || root->val <= minVal)
        return false;
                                
    return aux(root->left, minVal, root->val) && aux(root->right, root->val, maxVal);
}

//Inorder traversal: left - root - right, next node always > previous node
//https://ttzztt.gitbooks.io/lc/content/validate-binary-search-tree.html
bool isValidBST(TreeNode* root) 
{
    TreeNode* prev = NULL;
    return isValidBST(root, prev);
}

// !!important to add "&" since the prev will be changed
bool isValidBST(TreeNode* root, TreeNode*& prev) 
{
    // as traversing down the BST  
    if (root == NULL) 
        return true;
    if (!isValidBST(root->left, prev)) 
        return false;
    if (prev != nullptr && prev->val >= root->val) 
        return false;

    prev = root;

    return isValidBST(root->right, prev);
}





//fail, [ 5,4,6,null,null,3,7 ]
void isValidBST_recursive(TreeNode* node, bool& ret, vector<int> root_val, int direction)
{
    if (!node || !ret)
        return;

    if (direction == 0)
    {
        for (auto& element: root_val)
            if (node->val >= element)
            {
                ret = false;
            }
    }
    else if (direction == 1)
    {
        for (int i = 0; i < root_val.size(); ++i)
            if (node->val <= root_val[i])
            {
                ret = false;
            }
    }

    root_val.push_back(node->val);

    isValidBST_recursive(node->left, ret, root_val, 0);
    isValidBST_recursive(node->right, ret, root_val, 1);
    root_val.pop_back();
}

bool isValidBST_v1(TreeNode* root)  
{
    bool ret = true;
    vector<int> root_val;
    isValidBST_recursive(root, ret, root_val, 3);
    return ret;
}