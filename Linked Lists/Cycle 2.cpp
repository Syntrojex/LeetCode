class Solution
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        // Floyd's Cycle 1: Cycle Detect Karna
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                slow = head;
                break;
            }
        }

        // Agar Cycle 1 mein meeting nahi hui, toh cycle nahi hai
        if (fast == NULL || fast->next == NULL)
        {
            return NULL;
        }

        // Floyd's Cycle 2: Cycle Ka Starting Node Find Karna
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

/*
Floyd's Cycle 1: Cycle Detect Karna
1. Slow aur fast dono ko head se start karte hain.
2. Slow ko 1 step aur fast ko 2 steps aage chalate hain.
3. Agar slow == fast ho jaye, toh cycle exist karti hai.
4. Agar fast ya fast->next NULL ho jaye, toh cycle exist nahi karti.

Floyd's Cycle 2: Cycle Ka Starting Node Find Karna
1. Cycle detect hone ke baad slow ko wapas head par le aate hain.
2. Fast ko meeting point par hi rehne dete hain.
3. Ab slow aur fast dono ko 1-1 step aage chalate hain.
4. Jis node par dono dobara milte hain, wahi cycle ka starting node hota hai.

Time Complexity: O(n)
Space Complexity: O(1)
*/
