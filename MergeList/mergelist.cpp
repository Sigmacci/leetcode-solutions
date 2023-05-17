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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list2 == nullptr && list1 == nullptr)
    {
        return nullptr;
    }
    if ((list2 == nullptr && list1 != nullptr) || (list1 != nullptr && list2 != nullptr && list1->val < list2->val))
    {
        ListNode* newNode = new ListNode(list1->val);
        newNode->next = mergeTwoLists(list1->next, list2);
        return newNode;
    }
    else if ((list2 != nullptr && list1 == nullptr) || (list1 != nullptr && list2 != nullptr && list1->val >= list2->val))
    {
        ListNode* newNode = new ListNode(list2->val);
        newNode->next = mergeTwoLists(list1, list2->next);
        return newNode;
    }
    return nullptr;
}


int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    ListNode *merge = mergeTwoLists(list1, list2);
    while (merge != nullptr)
    {
        cout << merge->val << " ";
        merge = merge->next;
    }
}