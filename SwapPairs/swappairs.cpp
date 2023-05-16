#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *head)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
        return head;
    ListNode *temp1 = head;
    head = head->next;
    ListNode *temp2 = head->next;
    head->next = temp1;
    head->next->next = swapPairs(temp2);
    return head;
}

int main()
{
    ListNode *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list = swapPairs(list);
    while (list != nullptr)
    {
        cout << list->val << " ";
        list = list->next;
    }
}