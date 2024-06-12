class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        stack<int> stack_ast;

        for (auto &n : asteroids) {
            bool exploded = false;
            
            // Process current asteroid n
            while (!stack_ast.empty() && stack_ast.top() > 0 && n < 0) {
                int top = stack_ast.top();
                
                // If the absolute values are equal, both asteroids explode
                if (abs(top) == abs(n)) {
                    stack_ast.pop();
                    exploded = true;
                    break;
                }
                // If the top asteroid is larger, current asteroid explodes
                else if (abs(top) > abs(n)) {
                    exploded = true;
                    break;
                }
                // If the current asteroid is larger, the top asteroid explodes
                else {
                    stack_ast.pop();
                }
            }
            
            // If the current asteroid didn't explode, push it to the stack
            if (!exploded) {
                stack_ast.push(n);
            }
        }

        // Convert the stack to a vector in the correct order
        while (!stack_ast.empty()) {
            result.push_back(stack_ast.top());
            stack_ast.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
