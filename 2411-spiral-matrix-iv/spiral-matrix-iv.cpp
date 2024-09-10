class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m, vector<int>(n, -1));  // Initialize matrix with -1
        vector<int> res;

        // Traverse the linked list and store values in res
        ListNode* temp = head;
        while (temp != nullptr) {
            res.push_back(temp->val);
            temp = temp->next;
        }

        int sn = res.size();  // Size of the linked list
        int k = 0;            // Pointer for res

        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        // Spiral traversal of the matrix
        while (top <= bottom && left <= right && k < sn) {
            // Traverse from left to right on the top row
            for (int i = left; i <= right && k < sn; ++i) {
                result[top][i] = res[k++];
            }
            top++;  // Move the top boundary down

            // Traverse from top to bottom on the right column
            for (int i = top; i <= bottom && k < sn; ++i) {
                result[i][right] = res[k++];
            }
            right--;  // Move the right boundary left

            // Traverse from right to left on the bottom row
            if (top <= bottom) {
                for (int i = right; i >= left && k < sn; --i) {
                    result[bottom][i] = res[k++];
                }
                bottom--;  // Move the bottom boundary up
            }

            // Traverse from bottom to top on the left column
            if (left <= right) {
                for (int i = bottom; i >= top && k < sn; --i) {
                    result[i][left] = res[k++];
                }
                left++;  // Move the left boundary right
            }
        }

        return result;  // Return the filled matrix
    }
};
