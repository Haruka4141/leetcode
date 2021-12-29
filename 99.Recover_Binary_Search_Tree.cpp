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

//Pass, O(1)
void inorder(TreeNode* root, TreeNode*& previous, TreeNode* front, TreeNode* back)
{
    if (root == nullptr)
        return;

    inorder(root->left, previous, front, back);

    if (previous != nullptr && root->val < previous->val)   //the saveing cond must at root
    {
        if (front == nullptr)
        {
            front = previous;
        }
        back = root;
    }

    previous = root;
    inorder(root->right, previous, front, back);

}

void recoverTree(TreeNode* root)
{
    TreeNode* previous = nullptr;
    TreeNode* front = nullptr;
    TreeNode* back = nullptr;

    inorder(root, previous, front, back);

    int temp = front->val;
    front->val = back->val;
    back->val = temp;

}

//pass, space O(N)
void inorder(TreeNode* root, vector<TreeNode*>& node_vec)
{
    if (root == nullptr)
        return;
    inorder(root->left, node_vec);
    node_vec.push_back(root);
    inorder(root->right, node_vec);   
}

void recoverTree_v1(TreeNode* root) 
{
    TreeNode* previous = nullptr;
    vector<TreeNode*> node_vec;
    
    inorder(root, node_vec);
    for (int i = 1; i < node_vec.size(); ++i)
    {   
        int temp = node_vec[i]->val;
        int j = i;
        while (j > 0 && node_vec[j - 1]->val > temp)
        {
            node_vec[j]->val = node_vec[j - 1]->val;
            --j;
        }
        node_vec[j]->val = temp;
    }
}