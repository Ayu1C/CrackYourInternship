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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL || head->next==NULL || head->next->next==NULL) return head;
        
        ListNode *odd = head, *evenD = head->next, *even = evenD;
        
        while(odd != NULL)
        {
            if(even==NULL || even->next == NULL) break;
            
            odd->next = even->next;
            
            even->next = even->next->next;
            
            even = even->next;
            odd = odd->next;
        }
        
        odd->next = evenD;
        return head;
    }
};