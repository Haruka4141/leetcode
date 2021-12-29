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

//https://www.baeldung.com/cs/binary-tree-is-symmetric
bool isSymmetric(TreeNode* root)    //BFS
{
    if (!root)
        return true;

    queue<TreeNode*> queue;     //FIFO

    queue.push(root->left);
    queue.push(root->right);

    while (!queue.empty())
    {
        TreeNode* root1 = queue.front();
        queue.pop();
        TreeNode* root2 = queue.front();
        queue.pop();

        if (root1 == nullptr && root2 == nullptr)
        {
            continue;
        }
        else if (root1 != nullptr && root2 != nullptr)
        {
            if (root1->val != root2->val)
                return false;
        }
        else
        {
            return false;
        }
        //pair
        queue.push(root1->left);
        queue.push(root2->right);
        //pair
        queue.push(root1->right);
        queue.push(root2->left);
    }

    return true;

}

bool isMirror(TreeNode* left, TreeNode* right)
{
    if (left == nullptr && right == nullptr)
    {
        return true;
    }
    else if (left != nullptr && right != nullptr)
    {
        return (left->val == right->val) &&
                isMirror(left->left, right->right) &&
                isMirror(left->right, right->left);
    }
    else
    {
        return false;
    }
}

bool isSymmetric_recursive(TreeNode* root)  //DFS
{    
    if (!root)
        return true;
    return isMirror(root->left, root->right);
}
