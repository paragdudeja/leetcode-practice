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
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode *start_prev = dummy;
        for(int i = 1; i < left; i++) 
            start_prev = start_prev->next;
        
        ListNode *prev = nullptr, *curr = start_prev->next, *next;
        for(int i = left; i <= right; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        start_prev->next->next = next;
        start_prev->next = prev;
        return dummy->next;
    }
};