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
        int len = 1;
        ListNode* curr = head;

        if (head->next == nullptr)
            return nullptr;

        while (curr->next) {
            ++len;
            curr = curr->next;
        }

        int mid = floor((double)len / 2.0);

        curr = head;
        while (--mid) { // pre-decrement to get to the node before the mid one
            curr = curr->next;
        }

        ListNode* del = curr->next;
        if (del->next)
            curr->next = curr->next->next;
        else
            curr->next = nullptr;

        return head;
    }
};