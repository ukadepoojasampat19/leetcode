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
        if(head == nullptr || head->next==nullptr)
        {
            return nullptr;
        }
        ListNode* temp=head;
        int count=0;
        while(temp != nullptr)
        {
            count++;
            temp=temp->next;
        }
        int mid = floor(count/2);
        ListNode* prev = nullptr;
        temp=head;
        for(int i=0;i<mid;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        /*if(prev == nullptr)
        {
            head=head->next;
        }*/
      //  else
        //{
             prev->next=temp->next;
       // }
       
        return head;
        
    }
};