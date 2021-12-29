struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) 
{
    ListNode* begin = head;
    ListNode* curr = head;

    while (curr)
    {
        curr = curr->next;
        while (curr && begin->val == curr->val)
            curr = curr->next;
        begin->next = curr;
        begin = begin->next;
    }

    return head;
}