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

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        int size = 0;
        ListNode* temp1 = head;

        while (temp1 != NULL) {
            temp1 = temp1->next;
            size++;
        }

        k = k % size;

        if (k == 0) {
            return head;
        }

        ListNode* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = head;

        int stepsToNewTail = size - k;

        ListNode* newTail = head;

        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        head = newTail->next;
        newTail->next = NULL;

        return head;
    }
};

/*
Approach:

- Agar list empty ho, sirf aik node ho, ya k = 0 ho,
  to rotation ki zaroorat nahi, is liye head return kar do.

- Pehle linked list ki total size find karte hain.

- k = k % size karte hain kyun ke size positions rotate karne ke baad
  list dobara apni original position par aa jati hai.

  Example:
  [1,2,3,4,5], k = 7

  7 % 5 = 2

  Yani asal mein sirf 2 rotations karni hain.

- Agar k = 0 ho jaye, to list change nahi hogi,
  is liye head return kar do.

--------------------------------------------------

Circular List Ka Concept:

Example:

[1 -> 2 -> 3 -> 4 -> 5 -> NULL]

Agar k = 2 ho, humein last 2 nodes ko front par lana hai:

[4 -> 5 -> 1 -> 2 -> 3]

- Sabse pehle last node 5 ko head 1 se connect kar dete hain:

  temp->next = head;

  Ab list temporarily circular ban jati hai:

  1 -> 2 -> 3 -> 4 -> 5
  ^                   |
  |___________________|

  Yani 5 ka next ab 1 hai.

- Circular banane ka faida ye hai ke ab nodes ko individually
  move karne ki zaroorat nahi.
  Sirf correct jagah par connection todna hai.

--------------------------------------------------

New Tail Find Karna:

- Final answer mein 3 new tail hoga:

  4 -> 5 -> 1 -> 2 -> 3 -> NULL

- Isliye:

  stepsToNewTail = size - k
                  = 5 - 2
                  = 3

- Head se 3rd node tak move karte hain.

  newTail = 3

- New tail ka next hi new head hoga:

  head = newTail->next;

  3 ka next = 4

  Isliye new head = 4.

--------------------------------------------------

Circular Connection Todna:

- Ab:

  4 -> 5 -> 1 -> 2 -> 3 -> 4 ...

- Humein 3 ko last node banana hai.

- Isliye:

  newTail->next = NULL;

- Ab final list:

  4 -> 5 -> 1 -> 2 -> 3 -> NULL

- Aakhir mein new head return kar dete hain.

Time Complexity: O(n)
Space Complexity: O(1)
*/
