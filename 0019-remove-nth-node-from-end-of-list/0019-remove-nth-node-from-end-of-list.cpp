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
        // ListNode* dummy = new ListNode(-1);
        // dummy->next = head;
        // ListNode* firstptr = dummy;   
        // ListNode* secondptr = dummy;  

        // // Move second pointer n+1 steps ahead
        // for(int i = 0; i <= n; i++) {
        //     secondptr = secondptr->next;
        // }

        // // Move both pointers until second reaches end
        // while(secondptr != nullptr) {
        //     secondptr = secondptr->next;
        //     firstptr = firstptr->next;
        // }

        // // Remove the target node
        // firstptr->next = firstptr->next->next;

        // return dummy->next;

        int size = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            size++;
            temp = temp->next;  
        }
        if(size==n){
          temp = head;
          head = head->next;
          delete temp;
          return head;
        }
        temp = head;
        size = size-n;
        while(size>1){
          size--;
          temp = temp->next;
        }
        ListNode* f = temp->next;
        temp->next = temp->next->next;
        delete f;
        return head;
    }
};