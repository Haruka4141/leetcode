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

//submission, faster
int depth(TreeNode* root) 
{
    if (!root) 
        return 0;
    return max(depth(root->left), depth(root->right)) + 1;
}

void levelOrder(vector<vector<int>>& ans, TreeNode* node, int level) 
{
    if (!node) 
        return;
    ans[level].push_back(node->val);
    levelOrder(ans, node->left, level - 1);
    levelOrder(ans, node->right, level - 1);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) 
{
    int d = depth(root);                            //trace to generate the depth
    vector<vector<int>> ans(d, vector<int>{});      //allocate empty vector
    levelOrder(ans, root, d - 1);                   //traverse to generate the answer
    return ans;
}

//pass, Time: O(N)
vector<vector<int>> levelOrderBottom_v1(TreeNode* root) 
{
    vector<vector<int>> ret;

    if (root == nullptr)
        return ret;

    queue<TreeNode*> node_queue;                //need O(longest level) space
    node_queue.push(root);

    while (!node_queue.empty())
    {
        int level_len = node_queue.size();
        TreeNode* curr;
        vector<int> level;

        for (int i = 0; i < level_len; ++i)
        {
            curr = node_queue.front();

            node_queue.pop();
            if (curr->left) 
                node_queue.push(curr->left);
            if (curr->right)
                node_queue.push(curr->right);

            level.push_back(curr->val);
        }
        ret.insert(ret.begin(), level);
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

    auto ans = levelOrderBottom(root);

    return 0;
}