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

        // Last node ko Head se connect karke circular list banayi
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
  to list mein koi rotation nahi karni, is liye head return kar do.

- Pehle poori linked list traverse karke uski size find karte hain.

- k = k % size karte hain kyun ke agar k size ke barabar ho,
  to list apni original position par hi aa jati hai.

  Example:
  [1,2,3,4,5], k = 7

  7 % 5 = 2

  Yani asal mein sirf 2 positions rotate karni hain.

- Agar k % size = 0 ho, to list change nahi hogi,
  is liye original head return kar do.

- Last node ko head se connect kar dete hain.
  Is se linked list temporarily circular ban jati hai.

- New tail tak pohanchne ke liye size - k steps move karte hain.

- New tail ka next node hi new head hota hai.

- New tail->next ko NULL karke circular list ko dobara
  normal linked list bana dete hain.

Example:

[1,2,3,4,5], k = 2

size = 5
stepsToNewTail = 5 - 2 = 3

New Tail = 3
New Head = 4

Result:
[4,5,1,2,3]

Time Complexity: O(n)
Space Complexity: O(1)
*/
