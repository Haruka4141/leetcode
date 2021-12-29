struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//https://cheonhyangzhang.gitbooks.io/leetcode-solutions/content/92_reverse_linked_list_ii__medium.html
ListNode* reverseBetween(ListNode* head, int m, int n) 
{
    if (head == nullptr) 
    {
        return head;
    }
    ListNode fakeHead;
    fakeHead.next = head;
    ListNode* mp = &fakeHead;
    for (int i = 0; i < m - 1; i++)     //index
    {
        mp = mp->next;
    }
    //mp.next is the first element to be reversed
    ListNode* rhead = mp;                           //rhead->next is used to store previous node
    mp = mp->next;
    ListNode* rtail = mp;                           //store reverse-end
    ListNode* next = nullptr;
    for (int i = 0; i <= n - m; i++)
    {
        next = mp->next;
        mp->next = rhead->next;                     //reverse point
        rhead->next = mp;                           //store curr
        mp = next;                                  //curr = next
    }
    rtail->next = mp;
    return fakeHead.next;
}

int main()
{
    ListNode a(1);
    ListNode a1(2);
    ListNode a2(3);
    ListNode a3(4);
    ListNode a4(5);
    ListNode a5(6);
    ListNode a6(7);

    a.next = &a1;
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    a5.next = &a6;

    auto ans = reverseBetween(&a, 2, 4);

    return 0;
}

//weird
ListNode* reverseBetween_v1(ListNode* head, int left, int right)
{
    ListNode* start_node = head;
    ListNode* reverse_end = head;
    ListNode* curr = head;
    ListNode* last = head;
    ListNode* next = head;

    int index = 0;

    while (index < right)
    {
        if (index == left - 2)
        {
            start_node = curr;
            curr = curr->next;
        }

        if (index == left - 1)
        {
            reverse_end = curr;
            last = curr;
            curr = curr->next;
        }
        else if (index > left - 1)
        {
            next = curr->next;
            curr->next = last;
            last = curr;
            curr = next;
        }
        ++index;
    }

    start_node->next = last;
    reverse_end->next = curr;

    return head;
}