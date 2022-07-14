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
    // Iterative
    // TC : O(N)
    // SC : O(1)
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *curr = head, *next;
        while(curr) {
            next = curr->next;
            curr->next = pre;        
            pre = curr;
            curr = next;
        }
        return pre;
    }
};