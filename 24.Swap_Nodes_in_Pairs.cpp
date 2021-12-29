
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs_v2(ListNode* head)      //simpler (leetcode submission)
{
    ListNode dummy;             //<-***important
    dummy.next = head;
    ListNode* parent = &dummy;

    while (head && head->next)              //head will trace to size()-1
    {
        auto pt1 = head;
        auto pt2 = head->next;

        pt1->next = pt2->next;
        pt2->next = pt1;
        parent->next = pt2;
        parent = pt1;           
        head = parent->next;        //<-*** head += 2
    }

    return dummy.next;
}

/*
       0        1       2       3
1.   left    
2.   head -> right
3.   right    left
4.           right   left    curr
5.              |_____________¡ô
6.                           right  curr
7.                   right   left

*/
ListNode* swapPairs_v1(ListNode* head)      //use less memory, but more complex
{
    ListNode* curr = head;
    ListNode* left = nullptr;
    ListNode* right = nullptr;

    while (curr)
    {
        if (left)
        {
            if(right)
                right->next = curr;
            right = curr;
            curr = curr->next;

            if (left == head)
                head = right;

            left->next = right->next;
            right->next = left;
            right = left;
            left = nullptr;
        }
        else
        {
            left = curr;
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    a.next = &b;
    b.next = &c;
    c.next = &d;

    auto ans = swapPairs_v2(&a);

    return 0;
}