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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int total = 0;
        
        ListNode* temp = head;
        
        while(temp != NULL)
        {
            total++;
            temp = temp->next;
        }
        
        temp = head;
        
        int rem = total-n;
        
        if(rem==0 && total==1) return NULL;
        else if(rem == 0) return head->next;
        
        while(rem > 1)
        {
            temp = temp->next;
            rem--;
        }
        
        temp->next = temp->next->next;
        
        return head;
    }
};