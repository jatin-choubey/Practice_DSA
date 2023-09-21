#include <bits/stdc++.h>
using namespace std;
#define MAX 10

// Using Two Queues
void two_Queue_Push(int val, queue<int> &q1, queue<int> &q2)
{
    if (q1.size() == MAX)
    {
        cout << "OverFlown and hence can not push " << val << endl;
        return;
    }
    q2.push(val);
    while (!q1.empty())
    {
        int top = q1.front();
        q2.push(top);
        q1.pop();
    }
    swap(q1, q2);
}

// Using One Queue
void single_Queue_Push(int val, queue<int> &q)
{
    if (q.size() == MAX)
    {
        cout << "OverFlown and hence can not push " << val << endl;
        return;
    }
    int Qsize = q.size();
    q.push(val);
    for (int i = 1; i <= Qsize; i++)
    {
        int top = q.front();
        q.pop();
        q.push(top);
    }
}

int main()
{
    int choice;
    cout << "PRESS 1 FOR TWO QUEUES APPROACH, AND 2 FOR SINGLE QUEUE APPROACH\n";
    cin >> choice;
    if (choice == 1)
    {
        queue<int> q1;
        queue<int> q2;
        q2.push(1);
        q2.push(2);
        q2.push(3);
        q2.push(4);
        while (!q2.empty())
        {
            cout << q2.front() << " ";
            q2.pop();
        }
        cout << endl;
        two_Queue_Push(1, q1, q2);
        two_Queue_Push(2, q1, q2);
        two_Queue_Push(3, q1, q2);
        two_Queue_Push(4, q1, q2);
        two_Queue_Push(5, q1, q2);
        two_Queue_Push(6, q1, q2);
        two_Queue_Push(7, q1, q2);
        two_Queue_Push(8, q1, q2);
        two_Queue_Push(9, q1, q2);
        two_Queue_Push(10, q1, q2);
        two_Queue_Push(11, q1, q2);

        while (!q1.empty())
        {
            cout << q1.front() << " ";
            q1.pop();
        }
    }
    else
    {
        queue<int> q;
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);

        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }

        cout << endl;

        single_Queue_Push(1, q);
        single_Queue_Push(2, q);
        single_Queue_Push(3, q);
        single_Queue_Push(4, q);

        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
    }

    return 0;
}