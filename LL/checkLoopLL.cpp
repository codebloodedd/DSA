/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }
        unordered_map<ListNode *, int> addressCount;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            if (addressCount[temp] > 0)
            {
                return true;
            }
            addressCount[temp]++;
            temp = temp->next;
        }
        return false;

        // Tortoise and Hare Algorithm
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true; // Cycle detected
        }
        return false;
    }
};