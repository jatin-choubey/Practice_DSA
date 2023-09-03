/*
Link : https://www.codingninjas.com/studio/problems/allocate-books_1090540?leftPanelTab=0

You are given an array of integers books[], where books[i] represents the number of pages in the i-th book,
and an integer 'm' representing the number of students. The task is to find the minimum possible maximum number
of pages allocated to any student while distributing the books among the students. Each student must be
assigned consecutive books, and each book should be assigned to exactly one student. Write a function or algorithm
to solve this problem efficiently.

Example:
Consider the following example:

books = [12, 34, 67, 90]
m = 2
In this example, you have an array of books with page counts [12, 34, 67, 90] and 'm' equals 2, which means you need to distribute the books among 2 students.

Question 1: What is the minimum possible maximum number of pages that can be allocated to any student while ensuring each student gets a consecutive set of books?

Example Explanation:

In this case, the optimal distribution would be:

Student 1 gets books [12, 34, 67], totaling 113 pages.
Student 2 gets book [90], totaling 90 pages.
The maximum number of pages allocated to any student is 113. Therefore, the answer for this example is 113.

Your task is to write a program or algorithm to find this minimum maximum page allocation for any given set of books and the number of students ('m').

*/

bool canGive(vector<int> &books, int maxPages, int m)
{
    int students = 1;    // Variable to store the number of students required to hold 'n' books if each student could have at max 'maxPages' pages.
    int currHolding = 0; // Variable to store current number of pages that the student is holding.
    for (int i = 0; i < books.size(); i++)
    {
        if (currHolding + books[i] <= maxPages) // If the sum of current number of pages the student is holding and the pages in the current book is less than or equal
                                                // to the given 'maxPages' limit, we can give the current student all the pages from the current book (ie books[i])
        {
            currHolding += books[i];
        }
        else // if we can not give books[i] pages to the current students as its number of pages exceeds the maxPages value, we add another
             // student to hold the current book. Hence we do students++ and currHolding resets to hold only the current pages, it books[i]
        {
            currHolding = books[i];
            students++;
        }

        if (students > m) // If the number of 'students' required to hold all the books exceeds the the avaiable number of students 'm', return false.
            return false;
    }
    return true; // Else return true.
}
int findPages(vector<int> &books, int n, int m)
{
    // It is impossible to allocate books if the number of students exceeds the number of books, hence return -1
    if (m > n)
        return -1;

    /*The minimum number of pages you can assign to any student is atleast the number of pages
   in the book with mast pages. (If the number of books and number of students are equal,
   each student gets one book, and one with the thickest book will be having the most number of pages). */
    int left = INT_MIN;

    /*And the maximum number of pages you can assign to a student is sum of pages of all the books.
    (If there is only one stundent, all books will be assigned to him.)*/
    int right = 0;

    // Hence the left is the book with Max pages and right will be sum of pages of all the books.
    for (int i = 0; i < n; i++)
    {
        left = max(left, books[i]);
        right += books[i];
    }

    int ans = 0; // Variable to store the answer

    // Looping till the left and right pointer cross each other
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (canGive(books, mid, m)) // If we can give 'mid' number of pages to 'm' students,  such that all the books get distributed to exactly 'm' students
        {
            ans = mid;       // It could be our possible answer.
            right = mid - 1; // But we get even smaller possible answser if we search in the left sub booksay.
        }
        else
        {
            left = mid + 1; // If we can not give 'mid' number of pages to 'm' students, such that all the books get distributed to exactly 'm' students, we can be assure that the number of pages we are giving is too less.
        }
    }

    return ans; // Return latest answer.
}