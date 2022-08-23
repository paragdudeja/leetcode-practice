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
    ListNode *find_middle(ListNode *head) {
        ListNode *fast = head;
        while(fast->next && fast->next->next){
            head = head->next;
            fast = fast->next->next;
        }
        return head;
    }
    
    ListNode *reverse(ListNode *head) {
        ListNode *pre = nullptr, *curr = head, *next;
        while(curr) {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *middle = find_middle(head);
        ListNode *next_list = middle->next;
        middle->next = nullptr;
        next_list = reverse(next_list);
        while(head && next_list) {
            if(head->val != next_list->val) return false;
            head = head->next;
            next_list = next_list->next;
        }
        return true;
        
    }
};