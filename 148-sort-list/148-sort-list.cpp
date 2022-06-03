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
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
            tail->next = NULL;
        }
        
        if(l1)
            tail->next = l1;
        else
            tail->next = l2;
        
        return dummy->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next)
            return head;

        ListNode* slow = head;
        ListNode* fast = slow->next;
            
        while(fast){
            fast = fast->next;
            if(fast){
                fast = fast->next;
                slow = slow->next;
            }
        }
            
        ListNode* second = slow->next;
        slow->next = NULL;
            
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(second);
        return merge(l1, l2);
    }
};