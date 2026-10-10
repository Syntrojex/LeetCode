class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* list3 = new ListNode(0);
        ListNode* temp3 = list3;

        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->val < temp2->val)
            {
                temp3->next = new ListNode(temp1->val);
                temp3 = temp3->next;

                temp1 = temp1->next;
            }
            else
            {
                temp3->next = new ListNode(temp2->val);
                temp3 = temp3->next;

                temp2 = temp2->next;
            }
        }

        while (temp1 != NULL)
        {
            temp3->next = new ListNode(temp1->val);
            temp3 = temp3->next;

            temp1 = temp1->next;
        }

        while (temp2 != NULL)
        {
            temp3->next = new ListNode(temp2->val);
            temp3 = temp3->next;

            temp2 = temp2->next;
        }

        return list3->next;
    }
};

/*
Approach:
1. temp1 and temp2 point to the current nodes of list1 and list2
2. list3 is a dummy node used to build the merged linked list.
3. temp3 keeps track of the last node in the merged list
4. The first while loop runs while both lists still have elements
5. Since both lists are sorted, compare the current values of both lists
   and place the smaller value into the merged list or sirf jis list ka element list3 me place howa ha use ka temp move kro like list1 ka howa to temp1->next pr le jao
6. When one list becomes empty, the first while loop stops or neeche sirf wohi while loop chale ga jis ki list me elemnet ho ge or wo as it is copy ho jain ge 
   yaha autmatic wo while loop nhi chale ga jo list already empty ha yani jis ka temp NULL pr ha 
7. The remaining elements of the other list are already sorted, so
   they can be directly copied using the remaining while loop.
8. list3 is a dummy node, so return list3->next to skip the dummy node.

Time Complexity: O(m + n)
Space Complexity: O(m + n)
*/
