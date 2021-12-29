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

//https://dev.to/seanpgallivan/solution-binary-tree-level-order-traversal-36cg
vector<vector<int>> levelOrder(TreeNode* root) 
{
    vector<vector<int>> ret;
    if (root == nullptr)
        return ret;

    queue<TreeNode*> node_queue;
    node_queue.push(root);

    while (!node_queue.empty())
    {
        vector<int> level;
        int level_len = node_queue.size();       //<-***  save current level size
        for (int i = 0; i < level_len; ++i)
        {
            TreeNode* curr = node_queue.front();
            level.push_back(curr->val);
            node_queue.pop();

            if (curr->left)
                node_queue.push(curr->left);
            if (curr->right)
                node_queue.push(curr->right);
        }      
        ret.push_back(level);
    }
    return ret;
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    auto ans = levelOrder(root);

    return 0;
}