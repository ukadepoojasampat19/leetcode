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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
       
        if(l1 == nullptr)
        {
            return l2;
        }
        else if( l2 == nullptr)
        {
            return l1;
        }
        int sum;
        int carry=0;
        ListNode* temp1=nullptr;
        ListNode* head=nullptr;
        while(l1 != nullptr || l2 != nullptr)
        {
            int x=(l1 != nullptr) ? l1->val : 0;
            int y=(l2 != nullptr) ? l2->val : 0;
            sum=x + y + carry;
            ListNode* temp=new ListNode(sum % 10 );
            if(head == nullptr)
            {
                head=temp;
               
                temp1=head;
                
            }
            else
            {
                temp1->next=temp;
                temp1=temp1->next;
            }
            if( l1 != nullptr)
            {
                l1=l1->next;
            }
            if(l2 != nullptr)
            {
                l2=l2->next;
            }
           carry=sum / 10;
        }
        if(carry != 0)
        {
             ListNode* temp=new ListNode(carry);
            temp1->next=temp;
        }
        return head;
    }
};