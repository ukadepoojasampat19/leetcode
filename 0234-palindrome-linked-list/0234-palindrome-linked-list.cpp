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
    bool isPalindrome(ListNode* head) {
       if (head == nullptr || head->next == nullptr) {
            return true; // An empty list or a list with a single element is a palindrome
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Reverse the first half of the linked list while finding the middle
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;

            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // If the linked list has an odd number of elements, skip the middle node
        if (fast != nullptr) {
            slow = slow->next;
        }

        // Compare the reversed first half with the second half
        while (prev != nullptr && slow != nullptr) {
            if (prev->val != slow->val) {
                return false;
            }
            prev = prev->next;
            slow = slow->next;
        }

        return true;
    }
};