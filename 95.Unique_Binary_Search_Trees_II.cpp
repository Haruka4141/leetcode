#include <vector>

using namespace std;

/*
Every insert val should search from root, so [2, 3, 1] == [2, 1, 3]

   1                     2             3
    \                   / \           /
 ¢z   2      3   ¢{      1   3   ¢z     2     1     ¢{
 ¢x    \    /    ¢x              ¢x    /       \    ¢x
 ¢|     3  2     ¢}              ¢|   1         2   ¢}
*/

//https://www.programcreek.com/2014/05/leetcode-unique-binary-search-trees-ii-java/
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<TreeNode*> generateTrees_recursive(int start, int end)
{
    vector<TreeNode*> subtree;
    
    if (start > end)
    {
        subtree.push_back(nullptr);
    }
    else
    {
        for (int i = start; i <= end; ++i)
        {
            //***
            vector<TreeNode*> left = generateTrees_recursive(start, i - 1);
            vector<TreeNode*> right = generateTrees_recursive(i + 1, end);
            //***

            for (auto& left_element : left)
            {
                for (auto& right_element : right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_element;
                    root->right = right_element;
                    subtree.push_back(root);
                }
            }
        }
    }
    return subtree;
}

vector<TreeNode*> generateTrees(int n) 
{
    return generateTrees_recursive(1, n);
}

int main()
{
    generateTrees(3);
    return 0;
}