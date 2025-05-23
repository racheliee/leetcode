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
        if(head == nullptr)
            return nullptr;

        ListNode* dummy = new ListNode(0); // dummy가 있어야 floor를 가져감!!
        dummy->next = head;
        
        ListNode* slow = dummy;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;

        return dummy->next;
    }
};