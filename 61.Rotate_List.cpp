struct ListNode 
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) 
{
    if (!head)
        return head;

    ListNode* slow = head;
    ListNode* fast = head;
    int length = 1;

    while (fast->next != nullptr)
    {
        if (length > k)
            slow = slow->next;

        fast = fast->next;

        ++length;
    }
    
    if (k >= length)
    {    
        if (k % length == 0)
        {
            return head;
        }
        else
        {
            for (int i = k % length; i < length - 1; ++i)
                slow = slow->next;
        }
    }

    fast->next = head;
    head = slow->next;
    slow->next = nullptr;

    return head;
}

int main()
{
    ListNode a(0);
    ListNode b(1);
    ListNode c(2);
    a.next = &b;
    b.next = &c;
    auto ans = rotateRight(&a, 5);
 
    return 0;
}