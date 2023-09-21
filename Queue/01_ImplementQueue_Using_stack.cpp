#include <bits/stdc++.h>
using namespace std;

// Using Two Stacks
void two_Stack_PUSH(int val, stack<int> &s1, stack<int> &s2)
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(val);
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}
int main()
{
    int choice;
    cout << "Press 1 for two Stack Approach OR else 2 for single stack approach\n";
    cin >> choice;
    if (choice == 1)
    {
        stack<int> s1;
        stack<int> s2;
        s1.push(1);
        s1.push(2);
        s1.push(3);
        while (!s1.empty())
        {
            cout << s1.top() << " ";
            s1.pop();
        }
        cout << endl;
        two_Stack_PUSH(1, s1, s2);
        two_Stack_PUSH(2, s1, s2);
        two_Stack_PUSH(3, s1, s2);
        while (!s1.empty())
        {
            cout << s1.top() << " ";
            s1.pop();
        }
        cout << endl;
    }
    else
    {
    }
    return 0;
}