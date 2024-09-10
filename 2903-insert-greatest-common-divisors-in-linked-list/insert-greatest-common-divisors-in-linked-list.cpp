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
    bool gcd_number(ListNode* prev,ListNode* temp,int &num)
    {
        if(prev == nullptr || temp == nullptr) return false;

        int num1 = prev->val;
        int num2 = temp->val;
        num = gcd(num1,num2);
        return true;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp != nullptr)
        {
            int num=0;
            if(gcd_number(prev,temp,num))
            {
                ListNode* newNode = new ListNode(num);
                ListNode* temp2=prev->next;
                prev->next=newNode;
                newNode->next = temp2;
                
            }
            prev=temp;
            temp= temp->next;
        }
        return head;
    }
};