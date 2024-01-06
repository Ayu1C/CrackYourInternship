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
    int getDecimalValue(ListNode* head) {
        
        int n = 0;
        ListNode* temp = head;
        
        while(temp != NULL)
        {
            temp = temp->next;
            n++;
        }
        n-=1;
        
        int ans = 0;
        temp = head;
        
        while(temp)
        {
            ans += temp->val*pow(2,n--);
            temp = temp->next;
        }
        
        return ans;
    }
};