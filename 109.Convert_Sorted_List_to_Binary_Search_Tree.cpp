struct ListNode 
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
Floyd's Cycle Detection Algorithm: using slow & fast pointer to find loop.
we also can use this to find midpoint: slow(1 step) and fast(2 steps)
*/

//submission
TreeNode* sortedListToBST(ListNode* head) 
{
    if (!head)
        return nullptr;
    else {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev;

        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;          //1 step
            fast = fast->next->next;    //2 steps
        }

        prev->next = nullptr;           //truncate the link-list, divide & conquer
        TreeNode* root = new TreeNode(slow->val);
        if (head == slow)               //single element list
            return root;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
}

//https://dev.to/seanpgallivan/solution-convert-sorted-list-to-binary-search-tree-2i0e
//inorder traverse

ListNode* curr;

TreeNode* treeify(int i, int j) 
{
    if (j < i) 
        return nullptr;
    int mid = (i + j) >> 1;
    TreeNode* node = new TreeNode();
    node->left = treeify(i, mid - 1);
    node->val = curr->val;
    curr = curr->next;
    node->right = treeify(mid + 1, j);
    return node;
}

TreeNode* sortedListToBST_v1(ListNode* head) 
{
    int count = 0;
    curr = head;
    while (curr) 
    {
        curr = curr->next;
        count++;
    }
    curr = head;
    return treeify(1, count);
}