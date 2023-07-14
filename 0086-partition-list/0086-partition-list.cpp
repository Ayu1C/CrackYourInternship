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
    ListNode* partition(ListNode* head, int x) {
       
        ListNode *left = new ListNode();
        ListNode *right = new ListNode();
        
        ListNode *leftptr = left;
        ListNode *rightptr = right;
        
        while(head)
        {
            if(head->val < x)
            {
                leftptr->next = new ListNode(head->val);
                leftptr = leftptr -> next;
            }
            else 
            {
                rightptr->next = new ListNode(head->val);
                rightptr = rightptr -> next;
            }
             head = head->next;   
        }
        
        leftptr->next = right -> next;
        return left->next;
    }
};