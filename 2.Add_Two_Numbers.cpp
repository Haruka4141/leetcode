#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(0), next(next) {}
};

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* output = new ListNode();
        ListNode* head = output;
        int carry = 0;
        while (l1 || l2)
        {
            if (!output)
            {
                output = new ListNode();

            }
            if (l1)
            {
                output->val += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                output->val += l2->val;
                l2 = l2->next;
            }

            output->val += carry;

            if (output->val >= 10)
            {
                carry = 1;
                output->val -= 10;
            }
            output = output->next;

        }
        return head;
    }
};

int main()
{
    ListNode l1 = ListNode(2);
    l1.next = new ListNode(4);
    (l1.next)->next = new ListNode(3);
    ListNode l2 = ListNode(5);
    l2.next = new ListNode(6);
    (l2.next)->next = new ListNode(4);

    Solution a;
    ListNode* output = a.addTwoNumbers(&l1, &l2);
    
    return 0;
}