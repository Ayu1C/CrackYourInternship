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
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector<int> ans;
        
        ListNode *cur = head, *nxt = head;
        
        while(cur != NULL)
        {
            int maxn = cur->val;
            
            nxt = cur->next;
            
            while(nxt != NULL)
            {
                if(maxn < nxt->val) 
                {
                    maxn = nxt->val;
                    break;
                }
                nxt = nxt->next;
            }
            
            if(maxn != cur->val) ans.push_back(maxn);
            else ans.push_back(0);
            
            cur = cur->next;
        }
        
        return ans;
    }
};