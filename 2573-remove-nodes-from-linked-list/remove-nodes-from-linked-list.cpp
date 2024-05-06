class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr=head;
        stack<ListNode*> Stack;

        while(curr != nullptr)
        {
            while(!Stack.empty() && Stack.top()->val < curr->val)
            {
                Stack.pop();
            }
            Stack.push(curr);
            curr=curr->next;
        }
        ListNode* ptr=nullptr;
        while(!Stack.empty())
        {
            curr=Stack.top();
            Stack.pop();
            curr->next=ptr;
            ptr=curr;
        }
        return curr;

    }
};