/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents
its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode.
If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

+VE moving Right.
-VE moving Left.

Input : asteroids = [5, 2, -1, -5, 3, -4, 2, -1, 3]
output : [-4,2,3]

0. [5]
1. [5, 2]
2. [5, 2]  Since absolute value of -1 is less than stack top (ie 2). -1 will explode.
3. [5]   Since absolute value of -5 is greater than 2, 2 will explode. Hence pop 2.
4. []   Since absolute value of -5 is equal to top element 5, both will explode. So 5 popped.
5. [3]
6. []     Since absolute value of -4 is greater than 3, 3 is popped.
7. [-4]     Since stack was empty, push -4
8. [-4, 2]  No collision if +ve value comes after the -ve value in the stack.
9. [4, 2]  Since absolute value of -1 is less than tack top (ie 2). -1 will explode.
10. [-4, 2, 3]

Store the final stack elements in the vector and return the vector.

*/

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> stack; // Create a stack to simulate asteroid collisions
        for (int i = 0; i < asteroids.size(); i++)
        {
            if (stack.empty() || asteroids[i] > 0)
            {
                // If the stack is empty or the current asteroid is moving right (positive value),
                // simply push the asteroid onto the stack as it won't collide with anything.
                stack.push(asteroids[i]);
            }
            else
            {
                // If the current asteroid is moving left (negative value), we need to handle collisions.
                while (!stack.empty() && stack.top() > 0 && stack.top() < abs(asteroids[i]))
                {
                    // Keep popping asteroids from the stack that will be destroyed due to collision. (Make sure that we do not pop any negative asteroids)
                    stack.pop();
                }
                if (!stack.empty() && stack.top() == abs(asteroids[i]))
                {
                    // If there is an asteroid with the same absolute value, both asteroids will be destroyed.
                    stack.pop();
                }
                else
                {
                    // If the current asteroid survives the collision, push it onto the stack.
                    if (stack.empty() || stack.top() < 0)
                    {
                        stack.push(asteroids[i]);
                    }
                }
            }
        }

        // Create a vector to store the state of the remaining asteroids in the correct order.
        vector<int> ans(stack.size());
        for (int i = stack.size() - 1; i >= 0; i--)
        {
            ans[i] = stack.top();
            stack.pop();
        }

        return ans; // Return the state of the asteroids after all collisions.
    }
};
