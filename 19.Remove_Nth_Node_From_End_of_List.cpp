
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd_v2(ListNode* head, int n)   //same logic, simpler & cleaner (leetcode submission)
{
    ListNode* curr = head, * fast = head, * slow = head;

    for (int i = 0; i < n; i++)     
        fast = fast->next;
    

    if (fast == nullptr)
        return curr->next;

    while (fast->next != nullptr)   //fast will stop at end node
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;

    return curr;
}

ListNode* removeNthFromEnd_v1(ListNode* head, int n)    //pass, but complex
{
    ListNode* p = head;
    ListNode* curr = head;
    int count = 0;
    if (!head->next)
        return nullptr;

    while (curr)
    {
        curr = curr->next;
        ++count;
        
        if (count > n + 1)
            p = p->next;
    }
    if (count == n)
        head = head->next;

    ListNode* temp = (p->next)->next;
    p->next = temp;
    
    return head;
}


int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    auto ans = removeNthFromEnd_v2(&a, 1);
    return 0;
}