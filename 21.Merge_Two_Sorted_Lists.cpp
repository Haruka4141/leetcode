struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists_v2(ListNode* l1, ListNode* l2)  //will corrupt l1, l2
{
    
    ListNode start;
    ListNode* p = &start;

    while (l1 || l2)
    {
        if (l1 && l2 && l1->val <= l2->val)
        {
            p->next = l1;
            l1 = l1->next;
            p = p->next;
        }
        else if (!l2)   //if l2 is NULL, else will error
        {
            p->next = l1;
            l1 = l1->next;
            p = p->next;
        }
        //you can combined into if(!l2 || l1 && l2 && l1->val <= l2->val)
        else
        {
            p->next = l2;
            l2 = l2->next;
            p = p->next;
        }
    }
    return start.next;
}

int main()
{
    ListNode a = ListNode(1);
    ListNode a2 = ListNode(2);
    ListNode a3 = ListNode(4);
    //ListNode a4 = ListNode(-4);
    a.next = &a2;
    a2.next = &a3;
    //a3.next = &a4;

    ListNode b = ListNode(1);
    ListNode b2 = ListNode(3);
    ListNode b3 = ListNode(4);
    b.next = &b2;
    b2.next = &b3;

    ListNode* ans = mergeTwoLists_v2(&a, &b);

    return 0;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (!l1 && !l2)         //for two empty lists
        return nullptr;

    ListNode* l3 = new ListNode;    //memory leak!
    ListNode* l3_head = l3;

    while (l1 || l2)
    {
        //if (!l3)                  //be care of nullptr, you cannot re-assign nullptr to new memory address!
        //    l3 = new ListNode;    //not work!

        if (l1 && l2)
        {
            if (l1->val >= l2->val)
            {
                l3->val = l2->val;
                l3->next = new ListNode;
                l3 = l3->next;
                l2 = l2->next;
                if (l2 && l1->val < l2->val)
                {
                    l3->val = l1->val;
                    l1 = l1->next;
                    l3->next = new ListNode;
                    l3 = l3->next;
                    continue;
                }
            }
            else // l1->val < l2->val
            {
                l3->val = l1->val;
                l3->next = new ListNode;
                l3 = l3->next;
                l1 = l1->next;
                if (l1 && l1->val > l2->val)
                {
                    l3->val = l2->val;
                    l2 = l2->next;
                    l3->next = new ListNode;
                    l3 = l3->next;
                    continue;
                }
            }
            continue;
        }

        if (!l2 && l1)
        {
            l3->val = l1->val;
            l1 = l1->next;
        }
        if (!l1 && l2)
        {
            l3->val = l2->val;
            l2 = l2->next;
        }
        if (l1 || l2)
        {
            l3->next = new ListNode;
            l3 = l3->next;
        }
    }
    return l3_head;
}


ListNode* mergeTwoLists_1(ListNode* l1, ListNode* l2)     //this will corrupt l1 & l2
{
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

ListNode* mergeTwoLists_2(ListNode* l1, ListNode* l2)
{
    ListNode start;
    ListNode* p = &start;
    while (l1 || l2)
    {
        if ((!l1) || l1 && l2 && l2->val < l1->val)
            p->next = l2, l2 = l2->next, p = p->next;
        else
            p->next = l1, l1 = l1->next, p = p->next;
    }
    return start.next;
}