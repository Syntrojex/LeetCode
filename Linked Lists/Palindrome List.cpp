class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        stack<int> s;

        ListNode* temp = head;

        while (temp != NULL)
        {
            s.push(temp->val);
            temp = temp->next;
        }

        ListNode* temp1 = head;

        while (temp1 != NULL)
        {
            int check = s.top();
            s.pop();

            if (temp1->val != check)
            {
                return false;
            }

            temp1 = temp1->next;
        }

        return true;
    }
};

/*
Approach:

1. Pehle poori linked list ko traverse karke har node ki value stack mein push karte hain.

2. Stack LIFO hota hai, isliye top se values reverse order mein milti hain.

3. Phir linked list ko dobara head se traverse karte hain.

4. Har node ki value ko stack ke top ke saath compare karte hain.

5. Match hone par stack se top element pop kar dete hain.

6. Agar kisi bhi point par values different hon, to palindrome nahi hai,
   isliye false return kar dete hain.

7. Agar poori list successfully compare ho jaye, to true return karte hain.

Time Complexity: O(n)
Space Complexity: O(n)
*/
