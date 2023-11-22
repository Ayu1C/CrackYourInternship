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
    int lenOfLL(ListNode* head)
    {
        int c=0;
        while(head != NULL)
        {
            head=head->next;
            c++;
        }
        return c;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int leng = lenOfLL(head);
        
        if(leng < k || head==NULL || head->next==NULL) return head;
        
        ListNode *curr, *nxt, *prev = NULL;
        curr = head; nxt = curr->next;
        
        for(int i=1; i<=k; i++)
        {
            curr->next=prev;
            prev = curr;
            curr = nxt;
            if(nxt!=NULL) nxt = nxt->next;
        }
         
        head->next = reverseKGroup(curr, k);
        
        return prev;
        
    }
};