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
    ListNode* partition(ListNode* head, int x) {
        ListNode *l1_head = new ListNode(), *l2_head = new ListNode();
        ListNode *l1 = l1_head, *l2 = l2_head;
        ListNode *curr = head;
        while(curr) {
            if(curr->val < x) {
                l1->next = curr;
                l1 = l1->next;
            }
            else {
                l2->next = curr;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        l1->next = l2_head->next;
        l2->next = nullptr;
        return l1_head->next;
    }
};