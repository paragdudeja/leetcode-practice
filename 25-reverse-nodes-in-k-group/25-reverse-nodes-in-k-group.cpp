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
    ListNode* reverseKGroup(ListNode* head, int k) {
         if(!head || k == 1) return head;
        
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        
        int nodeCount = 1;
        ListNode *temp = head;
        while(temp->next) {
            temp = temp->next;
            nodeCount++;
        }
        
        ListNode *pre = dummy_head, *curr, *nex;
        while(nodeCount >= k) {
            curr = pre->next;
            nex = curr->next;
            for(int i = 1; i < k; ++i) {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            nodeCount -= k;
        }
        
        return dummy_head->next;
        
    }
    /*
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        int nodeCount = 1;
        ListNode *temp = head;
        while(temp->next) {
            temp = temp->next;
            nodeCount++;
        }
        
        ListNode *prev = dummy_head;
        while(nodeCount >= k) {
            ListNode *pre = NULL, *curr = prev->next, *next;
            for(int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = pre;
                pre = curr;
                curr = next;
            }
            ListNode *tail = prev->next;
            prev->next = pre;
            tail->next = curr;
            prev = tail;
            nodeCount -= k;
        }
        return dummy_head->next;
    }
    */
};