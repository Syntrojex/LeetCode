class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* newlist = new ListNode(0);
        ListNode* temp3 = newlist;

        int carry = 0;

        while (temp1 != NULL || temp2 != NULL || carry != 0)
        {
            int x = 0;
            if (temp1 != NULL)
            {
                x = temp1->val;
            }

            int y = 0;
            if (temp2 != NULL)
            {
                y = temp2->val;
            }

            int sum = carry + x + y;
            carry = sum / 10;
            int digit = sum % 10;

            temp3->next = new ListNode(digit);
            temp3 = temp3->next;

            if (temp1 != NULL)
            {
                temp1 = temp1->next;
            }

            if (temp2 != NULL)
            {
                temp2 = temp2->next;
            }
        }

        return newlist->next;
    }
};

/*
Approach:
1. temp1 aur temp2 pointers dono linked lists ko traverse karte hain.
2. newlist ka dummy node result linked list banane ke liye bana liya sabse phele to
3. temp3 result linked list ko chalane k liye bana liya 
4. carry previous addition ka carry store kre ga agar carry aya 
5. Loop tab tak chalta hai jab tak kisi list mein digit ya carry baqi ho yani agar aik b list non empty ha to us ak digit phele wale k us jagah pr 0 consider kre ga or add kre ga
6. x aur y mein dono lists k current digits store krte hain
   Agar koi list khatam ho jaye, to uska digit 0 consider hoga taake agar dosri list abhi khali nhi hoi us me add kr pay as 0
7. sum = carry + x + y 
8. carry = sum / 10 se next position ka carry milta hai
9. digit = sum % 10 se current result digit milta hai
10. temp3->next = new ListNode(digit) result list me newNode banate sath attach krta ha
11. temp3 = temp3->next resultList koa ge le jata ha 
12. temp1 aur temp2 ko NULL check karne ke baad next node par move karte hai
13. return newlist->next next isi liye kio k phele hum ne aik dummy node banayi thi top pr us se age sum store kia tah isi liye aika ge se bheja neeche wapis

*/
