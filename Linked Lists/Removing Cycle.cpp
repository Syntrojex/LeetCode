class Solution {
public:
    ListNode* detectCycle(ListNode* head)
{
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        // Phase 1: Detect if a cycle exists
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) 
            {
                isCycle = true;
                break;
            }
        }

        // If no cycle is found
        if (!isCycle)
        {
            return NULL;
        }

        slow = head;
        // Phase 2: Find the starting node of the cycle
        ListNode* prev = NULL;
        while (slow != fast) 
        {
            slow = slow->next;
            prev = fast;    // ye humesha FAST ki purani value ko store rkhe ga 
            fast = fast->next;
        }

        // agar hum yhna prev-> next ko NULL kr den to cycle break ho jay gi
        prev->next = NULL;

        return slow;
    }
};
