/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//  iterative

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *temp1;
        if (head->next->next == NULL)
        {
            temp1 = head->next;
            temp1->next = head;
            head->next = nullptr;
            return temp1;
        }

        temp1 = head;
        ListNode *temp2 = temp1->next;
        ListNode *temp3 = temp2->next;
        head->next = nullptr;
        while (temp3->next != NULL)
        {
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp3->next;
        }
        temp2->next = temp1;
        temp3->next = temp2;
        return temp3;
    }
};

// Recursive (not optimal but interesting)

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *newHead = reverseList(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }
};