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
    bool hasCycle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};

/*
Approach:
1. Yahan hum Slow aur Fast Pointer technique use karein ge,
   jise Floyd's Cycle Detection Algorithm bhi kehte hain.

2. Dono pointers head se start karein ge.

3. Slow pointer har baar 1 node aage move karega,
   jabke Fast pointer 2 nodes aage move karega.

4. Agar linked list mein cycle hui, toh kisi na kisi point par
   slow aur fast ek hi node par mil jayein ge aur hum true return karein ge.

5. Agar fast ya fast->next NULL ho gaya, toh iska matlab
   linked list mein cycle nahi hai aur hum false return karein ge.

Time Complexity: O(n)
Space Complexity: O(1)
*/
