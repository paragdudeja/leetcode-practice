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
    // Recursive : Method 2
    // TC : O(N)
    // SC : O(1) / O(N) rec. stack
    ListNode* reverseList(ListNode* head, ListNode *prev = nullptr) {
        if(!head) return prev;
        
        ListNode *next = head->next;
        head->next = prev;
        return reverseList(next, head);
    }
    
    /*
    // Recursive : Method 1
    // TC : O(N)
    // SC : O(1) / O(N) rec. stack
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *rest_head = reverseList(head->next);
        ListNode *rest_tail = head->next;
        
        rest_tail->next = head;
        head->next = nullptr
            ;
        return rest_head;
    }
    */
    
    /*
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
    */
};