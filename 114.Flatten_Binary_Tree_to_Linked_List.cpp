struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//submission, cleaner & faster
TreeNode* prev = nullptr;
void flatten(TreeNode* root)
{
    if (root == nullptr) 
        return;

    flatten(root->right);
    flatten(root->left);

    root->right = prev;
    root->left = nullptr;
    prev = root;
}

//pass
void flatten_recursive(TreeNode* root, TreeNode*& end)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        end = root;
        return;
    }

    flatten_recursive(root->left, end);

    if (root->left)
    {
        TreeNode* root_right = root->right;
        root->right = root->left;
        root->left = nullptr;
        end->right = root_right;
    }

    flatten_recursive(root->right, end);


}

void flatten_v1(TreeNode* root) 
{
    if (!root)
        return;

    TreeNode* end;
    flatten_recursive(root, end);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    //root->left->left->left = new TreeNode(7);
    //root->left->left->right = new TreeNode(2);
    //root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(6);
    //root->right->right->left = new TreeNode(5);
    //root->right->right->right = new TreeNode(1);

    flatten(root);

    return 0;
}