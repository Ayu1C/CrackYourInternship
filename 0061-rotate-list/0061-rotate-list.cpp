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
    ListNode* rotateRight(ListNode* head, int k) {
        
       if(!head || k==0) return head;
        ListNode* p1 = head, *p2 = head;
        for(int i=0;i<k;i++){ // move the faster pointer for k steps first
            if(p1->next) p1 = p1->next;
            else{
                k = k%(i+1);//if k is greater than the length of the list, make k = k%length
                i = -1; // and count from the beginning again
                p1 = head; // move p1 to head and count again
            }
        }
        while(p1->next!=NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = head;
        head = p2->next;
        p2->next = NULL;
        return head;
    }
};