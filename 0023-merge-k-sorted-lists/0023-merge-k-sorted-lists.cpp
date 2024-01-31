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
class Compare {
public:
    bool operator()(ListNode* temp1, ListNode* temp2)
    {
        if (temp1->val > temp2->val) {
            return true;
        }
        
        return false;
    }
};

class Solution {

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue <ListNode*, vector<ListNode*>, Compare> pq;
        
        for(int i=0; i<lists.size(); i++)
        {
            ListNode* temp = lists[i];
            while(temp != NULL)
            {
                pq.push(temp);
                temp = temp->next;
            }
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        
        while(!pq.empty())
        {
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
        }
        
        cur->next = NULL;
        
        return dummy->next;

    }
};