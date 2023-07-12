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
        
        ListNode* tem = head;
        int count = 0;
        
        while(tem != NULL)
        {
            tem = tem->next;
            count++;
        }
         
        if(count==1) return NULL;
        if(count == n)return head->next;
        
        int pos = count - n;
        
        int start = 1;
        
        ListNode *cur = head, *temp = head->next;
        
        while(start != pos)
        {
            cur = temp;
            temp = temp->next;
            start++;
        }
        
        cur->next = temp->next;
        return head;
        
    }
};