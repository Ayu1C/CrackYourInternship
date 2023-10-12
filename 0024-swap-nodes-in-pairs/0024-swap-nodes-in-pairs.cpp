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
    ListNode* swapPairs(ListNode* head) {
        
        if(!head) return head;
        
        ListNode *prev = head, *curr = head->next;
        
        while(prev && prev->next != NULL)
        {
            swap(prev->val, curr->val);
            
            prev = curr->next;
            
            if(curr->next != NULL)
            {
                curr = curr->next->next;
            }
            
        }
        
        return head;
    }
};