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

//beats 100%

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

    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        if (head->next->next == NULL)
        {
            if (head->val == head->next->val)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if (head->next->next->next == NULL)
        {
            if (head->val == head->next->next->val)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next == NULL)
        {
            fast = reverseList(slow->next);
        }
        else if (fast->next->next == NULL)
        {
            slow = slow->next;
            fast = reverseList(slow);
        }
        ListNode *temp = head;
        while (fast != nullptr && temp != slow)
        {
            if (fast->val != temp->val)
            {
                return false;
            }
            fast = fast->next;
            temp = temp->next;
        }
        return true;
    }
};