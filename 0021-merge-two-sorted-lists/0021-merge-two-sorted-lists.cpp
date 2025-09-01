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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode * head3=NULL;
        ListNode * tail=NULL;
        ListNode * h1 = list1;
        ListNode * h2 = list2;
        if(!h1 && !h2)
        return NULL;

        if(h1 && h2){
             while(h1!=NULL &&  h2!=NULL){

            if(h1->val<=h2->val){
                // h1 data is smaller
              // add to the next node 
              ListNode * temp = new ListNode(h1->val);
              if(head3==NULL){
                head3=temp;
                tail=head3;
            }
            else{
tail->next=temp;
tail=tail->next;
            }
            
            h1=h1->next;
            }
            else{
                // h2 wala chota hai
                 ListNode * temp = new ListNode(h2->val);
              if(head3==NULL){
                head3=temp;
                tail=head3;
            }
            else{
tail->next=temp;
tail= tail->next;
            }
            
        
            h2=h2->next;
            }
        }

        }
        
        if(h1!=NULL){
            while(h1){
                ListNode * temp = new ListNode(h1->val);
                if(head3==NULL){
                    head3 = temp;
                    tail=head3;
                }
                else{
tail->next = temp;
tail=tail->next;
                }
                

                h1 = h1->next;
            }
        }
        if(h2!=NULL){
             while(h2){
                ListNode * temp = new ListNode(h2->val);
                if(head3==NULL){
                    head3 = temp;
                    tail=head3;
                }
                else{
 tail->next = temp;
 tail=tail->next;
                }
               
                
                h2 = h2->next;
            } 
        }

        return head3;
    }
};