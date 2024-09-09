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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int link_size = 0;
        vector<ListNode*> result(k,nullptr);
        ListNode* temp = head;

        while(temp != nullptr)
        {
            link_size++;
            temp=temp->next;
        }
        temp = head;
        int partSize = link_size / k;
        int rem = link_size % k;

        for(int i=0;i<k;i++)
        {
            result[i] = temp;
            int current_ct = partSize + (i < rem ? 1:0);
            ListNode* prev = nullptr;

            for(int j=0;j<current_ct;j++)
            {
                prev = temp;
                temp= temp->next;
            }
            if(prev)
            {
                prev->next=nullptr;
            }
        }



        return result;
    }
};