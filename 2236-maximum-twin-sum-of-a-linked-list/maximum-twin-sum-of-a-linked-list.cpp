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
    int pairSum(ListNode* head) {
        vector<int> result;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            result.push_back(temp->val);
            temp = temp->next;
        }

        int l =0;
        int r = result.size()-1;
        int max_num = 0;
        while(l < r)
        {
            int num = result[l] + result[r];
            max_num = max(max_num,num);
            l++;
            r--;
        }
        return max_num;
    }
};