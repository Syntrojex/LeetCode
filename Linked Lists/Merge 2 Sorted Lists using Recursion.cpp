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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (head1 == NULL || head2 == NULL) {
            if(head1==NULL)
            {
                return head2;
            }
            else
            {
                return head1;
            }
        }

        if (head1->val <= head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }

        else {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};

/*
Approach:

- Agar kisi bhi linked list ka head NULL ho, to doosri list return kar do,
  kyun ke uske tamam remaining nodes merged list ka hissa ban jayenge.
- Agar head1 ki value head2 ki value se chhoti ya equal ho, to head1
  ko merged list ka current node banao.
- head1->next ko recursive call se merge karo, taake baqi nodes sorted
  order mein jud jayein.
- Agar head2 ki value chhoti ho, to head2 ko current node banao aur
  uske next ko recursive call se merge karo.
- Har recursive call chhoti values ko pehle jorti hai aur phir current
  node return karti hai.
- Aakhir mein dono sorted linked lists aik sorted linked list ban jati hain.

Time Complexity: O(m + n)
Space Complexity: O(m + n), recursive call stack ki wajah se.
*/
