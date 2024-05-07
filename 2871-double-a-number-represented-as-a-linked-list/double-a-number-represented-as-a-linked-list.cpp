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
    /*ListNode* doubleIt(ListNode* head) {
        int sum = 0;

        // Calculating the sum of the linked list values
        while (head != nullptr) {
            sum = sum * 10 + head->val;
            head = head->next;
        }

        sum *= 2;

        // Converting the sum to a string
        string strSum = to_string(sum);

        // Reversing the string
       

        ListNode* result = nullptr;
        ListNode* prev = nullptr;

        // Creating a new linked list from the reversed string
        for (char digit : strSum) {
            ListNode* newNode = new ListNode(digit - '0');
            if (prev == nullptr) {
                result = newNode;
            } else {
                prev->next = newNode;
            }
            prev = newNode;
        }

        return result;
    }*/
     ListNode* doubleIt(ListNode* head) {
        // Initialize a stack to store the values of the linked list
        stack<int> values;
        int val = 0;

        // Traverse the linked list and push its values onto the stack
        while (head != nullptr) {
            values.push(head->val);
            head = head->next;
        }

        ListNode* newTail = nullptr;

        // Iterate over the stack of values and the carryover
        while (!values.empty() || val != 0) {
            // Create a new ListNode with value 0 and the previous tail as its next node
            newTail = new ListNode(0, newTail);
            
            // Calculate the new value for the current node
            // by doubling the last digit, adding carry, and getting the remainder
            if (!values.empty()) {
                val += values.top() * 2;
                values.pop();
            }
            newTail->val = val % 10;
            val /= 10;
        }

        // Return the tail of the new linked list
        return newTail;
     }

};
