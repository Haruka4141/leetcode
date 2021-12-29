struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) 
{
    ListNode dummy;
    dummy.next = head;
    ListNode* curr = head;
    ListNode* begin = &dummy;

    while (curr)
    {
        curr = curr->next;
        if (curr && begin->next->val == curr->val)
        {
            while (curr && begin->next->val == curr->val)
            {
                curr = curr->next;
            }
            begin->next = curr;
        }
        else
            begin = begin->next;
    }

    return head;
}

int main()
{
    ListNode a(1);
    ListNode a1(2);
    ListNode a2(3);
    ListNode a3(3);
    ListNode a4(4);
    ListNode a5(4);
    ListNode a6(4);

    a.next = &a1;
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    a5.next = &a6;
    
    auto ans = deleteDuplicates(&a);



    return 0;
}