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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* tail = dummy_head;
        
        tail->next = head;
        while(tail->next && tail->next->next) {
            if(tail->next->val == tail->next->next->val) {
                while(tail->next && tail->next->next && tail->next->val == tail->next->next->val) {
                    tail->next->next = tail->next->next->next;
                }
                tail->next = tail->next->next;
            }
            else {
                tail = tail->next;
            }
        }
        return dummy_head->next;
    }
};