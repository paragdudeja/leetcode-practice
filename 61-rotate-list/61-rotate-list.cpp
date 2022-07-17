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
        if(!head || !head->next) return head;
        ListNode *tail = head;
        int len = 1;
        while(tail->next) {
            tail = tail->next;
            ++len;
        }
        
        tail->next = head;
        
        if(k = k % len) {
            for(int i = 0; i < len - k; i++) {
                tail = tail->next;
            }
        }
        
        head = tail->next;
        tail->next = nullptr;
        
        return head;
    }
    /*
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode *temp = head;
        int len = 0;
        while(temp) {
            temp = temp->next;
            ++len;
        }
        
        k = k % len;
        if(k == 0) return head;
        
        ListNode *fast = head, *slow = head;
        for(int i = 0; i < k; ++i) {
            fast = fast->next;
        }
        
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
        
        return head;
    }
    */
};