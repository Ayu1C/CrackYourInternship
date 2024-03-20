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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode *list2End, *temp = list2, *cur;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        
        list2End = temp;
        
        temp = list1;
        
        for(int i=1; i<a; i++)
        {
           temp = temp->next;  
        }
        
        cur = temp;
        
        for(int i=0; i<=b-a; i++)
        {
            temp = temp->next;
        }
        
        ListNode* end = temp->next;
        
        cur->next = list2;
        list2End->next = end;
        
        return list1;
    }
};