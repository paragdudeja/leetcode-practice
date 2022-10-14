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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next){
            delete head;
            return NULL;
        }
        ListNode *slow = head, *fast = head, *pre = NULL;
        while(fast and fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *temp = pre->next;
        pre->next = pre->next->next;
        delete temp;
        return head;
    }
};