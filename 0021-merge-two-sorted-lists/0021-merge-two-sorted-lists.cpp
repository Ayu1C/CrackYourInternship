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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *temp1 = list1, *temp2 = list2;
        ListNode* dummy = new ListNode(-1), *cur=dummy;
        
        while(temp1 != NULL && temp2!=NULL)
        {
           if(temp1->val <= temp2->val)
           {
               cur->next = temp1;
               temp1 = temp1->next;
           } else{
               cur->next = temp2;
               temp2 = temp2->next;
           }
            cur = cur->next;
        }
        if(temp1 != NULL)
        {
           cur->next = temp1;
        } else if(temp2 != NULL)
        {
           cur->next = temp2;
        }
        
        return dummy->next;
    }
};