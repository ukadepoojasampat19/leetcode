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
       ListNode* prev=nullptr;
       ListNode* temp=head;
       int count=0;
        while(temp != nullptr)
        {
            count++;
            temp=temp->next;
        }
        int lengt_list=count - n + 1;
        temp=head;
        for(int i=1;i<lengt_list;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        if( prev == nullptr)
        {
            head=head->next;
        }
        else
        {
            prev->next=temp->next;
        }
        
          return head;
    }
   
};