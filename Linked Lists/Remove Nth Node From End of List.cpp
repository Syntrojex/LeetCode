class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        if (fast == NULL)
        {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }
        else
        {
            while (fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }

            ListNode* toDelete = slow->next;
            slow->next = toDelete->next;
            delete toDelete;

            return head;
        }
    }
};

/*
Approach:
1. Slow aur fast dono pointers ko head se start karte hain.
2. Fast ko n steps aage le jaate hain, taake dono pointers ke darmiyan n nodes ka gap ban jaye.
3. Agar fast NULL ho jaye, toh iska matlab end se nth node head hai.
   Is case mein head ko aglay node par shift karke purane head ko delete kar dete hain.
4. Agar fast NULL nahi hota, toh slow aur fast ko ek-ek step saath aage chalate hain.
5. Jab fast last node par pohanchta hai, slow delete hone wali node se ek pehle hota hai.
6. Slow ke next pointer ko delete hone wali node ke next se connect kar dete hain.
7. Delete hone wali node ki memory free karke updated head return kar dete hain.

Time Complexity: O(n) — list ko maximum ek baar traverse karte hain.
Space Complexity: O(1) — sirf pointers use hote hain, extra data structure nahi.
*/
