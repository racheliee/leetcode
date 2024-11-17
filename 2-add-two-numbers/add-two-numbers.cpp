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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *n1 = l1;
        ListNode *n2 = l2;

        ListNode *ret = new ListNode(); // dummy head
        ListNode *currentNode = ret;

        int curr, val1, val2;
        int overflow = 0;

        while(n1 != nullptr || n2 != nullptr || overflow){
            val1 = (n1 == nullptr) ? 0 : n1->val;
            val2 = (n2 == nullptr) ? 0 : n2->val;
            
            curr = val1 + val2 + overflow;
            overflow = curr / 10;

            cout << curr << endl;

            currentNode->next = new ListNode(curr % 10);
            currentNode = currentNode->next;

            if (n1 != nullptr) n1 = n1->next;
            if (n2 != nullptr) n2 = n2->next;
        }

        return ret->next;
    }
};