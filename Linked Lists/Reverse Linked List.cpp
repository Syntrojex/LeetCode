class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next1 = NULL;

        while (current != NULL)
        {
            next1 = current->next;

            current->next = prev;

            prev = current;
            current = next1;
        }

        head = prev;

        return head;
    }
};

// Teen pointers banenge:
// current, prev aur next1.
//
// prev NULL se start hoga.
// current head se start hoga.
// next1 bhi NULL se start hoga.
//
// Loop mein enter hote hi:
// Sabse pehle current ke next node ko next1 mein save karenge,
// taake original list ka connection lose na ho.
//
// Phir current ke next ko prev se connect karenge.
// Isse current node ka arrow reverse ho jayega.
//
// Uske baad:
// prev ko current par move karenge,
// aur current ko next1 par move karenge.
//
// Ye process tab tak repeat hoga jab tak current NULL nahi ho jata.
//
// Jab current NULL ho jayega,
// prev linked list ke last node par hoga.
//
// Ab prev hi reversed linked list ka new head hai,
// isliye head ko prev ke equal karenge.
//
// Finally reversed linked list ka head return kar denge.
