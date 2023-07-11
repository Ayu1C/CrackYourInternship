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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head->next==NULL)return head;
        
        ListNode* l = head;
        ListNode* r = head;
        
        stack<int> s;
        
        int count = 1;
        while(count < left)
        {
            l = l->next;
            r = r->next;
            count++;
        }
        while(count < right)
        {
            s.push(r->val);
            r = r-> next;
            count ++;
        }
        s.push(r->val);
        
        while(l != r->next)
        {
            l->val = s.top();
            s.pop();
            l = l->next;
        }
        
        return head;
    }
};