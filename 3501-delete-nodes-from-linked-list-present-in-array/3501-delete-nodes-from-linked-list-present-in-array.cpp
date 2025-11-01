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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        // â Use unordered_set instead of unordered_map since we only need existence check
        unordered_set<int> m(nums.begin(), nums.end());

        // dummy Node 
        ListNode *dummy = new ListNode(0);
        ListNode *tail  = dummy;
        ListNode *temp = head;

        while (temp != nullptr) {
            // if the value should NOT be included in new list
            if (m.find(temp->val) == m.end()) {
                // include the current node in the new list
                tail->next = new ListNode(temp->val);
                tail = tail->next;
            }
            // move to next node
            temp = temp->next;
        }

        // â store new head, delete dummy to prevent memory leak
        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
