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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        

        int count=0;
        ListNode * temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        count-=n;
        ListNode * curr = head;
        ListNode * prev = NULL;

if(count==0){
            // dellelte first node 
             temp = head;
             head = head->next;
             delete temp;
             return head;
 
        }
        while(count--){
            prev = curr;
            curr= curr->next;
        }
        
        
        // delte the node 
        prev->next = curr->next;
        delete curr;
        return head;
    }
};