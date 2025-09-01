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
ListNode * reverse(ListNode * curr , ListNode * prev){
     if(curr==NULL)
     return prev;

     // make reference for the future Node 
     ListNode * future = curr->next;
     // reverse the pointerws 
     curr->next = prev;
     // move on with next pointers
     return reverse(future,curr);
}
    ListNode* reverseList(ListNode* head) {
        ListNode * prev = NULL;
        return reverse(head,prev);
    }
};