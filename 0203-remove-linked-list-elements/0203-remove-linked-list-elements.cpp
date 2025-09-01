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
    ListNode* removeElements(ListNode* head, int val) {
         if(!head)
         return head;
  
       ListNode * newH =NULL;
       ListNode * tail=NULL;
      ListNode * temp = head;
      while(temp){
         if(temp->val==val){
            temp=temp->next;
         }else{
            if(newH==NULL){
                newH = temp;
                temp=temp->next;
                tail=newH;
            }else
            {
                tail->next= temp;
                temp=temp->next;
                tail=tail->next;
            }
         }
         
      }

     if(tail)
     tail->next =NULL;
          return newH;
    }
};