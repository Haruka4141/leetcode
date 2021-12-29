#include <vector>
#include <queue>
#include <algorithm>

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

//submission
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int>> ret;

    if (root == nullptr)
        return ret;

    queue<TreeNode*> node_queue;
    node_queue.push(root);

    bool zig_switch = false;

    while (!node_queue.empty())
    {
        ret.push_back({});
        int level_len = node_queue.size();

        for (int i = 0; i < level_len; ++i)
        {
            TreeNode* curr = node_queue.front();
            ret.back().push_back(curr->val);
            node_queue.pop();

            if (curr->left)
                node_queue.push(curr->left);
            if (curr->right)
                node_queue.push(curr->right);
        }

        if (zig_switch)
        {
            reverse(ret.back().begin(), ret.back().end());
        }

        zig_switch = !zig_switch;        
    }
    return ret;
}

//pass, but you can reverse ret.back() only!
vector<vector<int>> zigzagLevelOrder_v1(TreeNode* root) 
{
    vector<vector<int>> ret;
    
    if (root == nullptr)
        return ret;

    queue<TreeNode*> node_queue;
    node_queue.push(root);

    bool zig_switch = false;

    while (!node_queue.empty())
    {
        vector<int> level;
        int level_len = node_queue.size();
         
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

        if (zig_switch)
        {
            for (int i = 0, j = level.size() - 1; j > i; ++i, --j)
            {
                int temp = level[i];
                level[i] = level[j];
                level[j] = temp;
            }
        }

        zig_switch = !zig_switch;
        ret.push_back(level);
    }

    return ret;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    auto ans = zigzagLevelOrder(root);

    return 0;
}