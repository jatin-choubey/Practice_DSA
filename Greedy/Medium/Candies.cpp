/*
Write a program to find the MINIMUM NUMBER OF CANDIES required to distribute
among the students such that each student has AT LEAST ONE candy
and a STUDENTS WITH HIGHER RATINGS GET MORE CANDIES than their neighbor.

Students with same marks standing next to each other "MAY" have same number of candies.

Example:
Students Marks = 1 5 3 2 6
MIN. Candies   = 1 3 2 1 2    ie = 1 + 3 + 2 + 1 + 2 = 9 candies
*/

int requiredCandies(vector<int> &students)
{
    // Get the number of students
    int n = students.size();

    // Create two vectors to store the number of candies required for each student
    // when only considering their left or right neighbor
    vector<int> left(n, 1);
    vector<int> right(n, 1);

    // Update the left vector such that if a student has a higher rating than their left neighbor,
    // they get as many candies as their left neighbor plus one
    for (int i = 1; i < n; i++)
    {
        if (students[i] > students[i - 1])
            left[i] = left[i - 1] + 1;
    }

    // Update the right vector such that if a student has a higher rating than their right neighbor,
    // they get as many candies as their right neighbor plus one
    for (int i = n - 2; i >= 0; i--)
    {
        if (students[i] > students[i + 1])
            right[i] = right[i + 1] + 1;
    }

    // Create a vector to store the final number of candies required for each student
    vector<int> ans(n, 0);

    // Update the ans vector such that each element is equal to the maximum value between
    // the corresponding elements in the left and right vectors
    for (int i = 0; i < n; i++)
    {
        ans[i] = max(left[i], right[i]);
    }

    // Calculate the sum of all elements in the ans vector
    int sum = 0;
    for (auto I : ans)
        sum += I;

    // Return the sum as the minimum number of candies required
    return sum;
}
