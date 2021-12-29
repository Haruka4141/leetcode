#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x)      //submission
{
    queue<int> lower;
    queue<int> higher;
    ListNode* temp = head;
    ListNode* ans = head;
    while (temp)        //search twice, but still faster than search once
    {
        int cur = temp->val;
        if (cur < x) lower.push(cur);
        else higher.push(cur);

        temp = temp->next;
    }

    while (head)        //function is passing value, so we can modify it
    {
        int cur = 0;
        if (!lower.empty())
        {
            cur = lower.front();
            lower.pop();
        }
        else
        {
            cur = higher.front();
            higher.pop();
        }
        head->val = cur;
        head = head->next;
    }

    return ans;
}

//pass
ListNode* partition(ListNode* head, int x) 
{
    ListNode small_list;
    ListNode* small_end = &small_list;
    ListNode large_list;
    ListNode* large_end = &large_list;

    while (head)
    {
        if (head->val < x)
        {
            small_end->next = head;
            small_end = small_end->next;
        }
        else
        {
            large_end->next = head;
            large_end = large_end->next;
        }

        head = head->next;
    }

    small_end->next = large_list.next;
    large_end->next = nullptr;

    return small_list.next;
        
}


int main()
{

    ListNode a(1);
    ListNode a1(4);
    ListNode a2(3);
    ListNode a3(2);
    ListNode a4(5);
    ListNode a5(2);
    //ListNode a6(4);

    a.next = &a1;
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    //a5.next = &a6;

    auto ans = partition(&a, 3);

    return 0;
}