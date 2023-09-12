#include <bits/stdc++.h>
using namespace std;
#define MAX 100
class Stack
{
    int top;

public:
    int a[MAX];
    Stack()
    {
        top = -1;
    }
    bool push(int x);
    bool pop();
    int peek();
    bool empty();
};

bool Stack::push(int x)
{
    if (top > (MAX + 1))
    {
        cout << "Stack OverFlow\n";
        return false;
    }
    else
    {
        top++;
        a[top] = x;
        cout << x << " pushed inside the stack\n";
        return true;
    }
}
bool Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack UnderFlow\n";
        return false;
    }
    else
    {
        // cout << "Popping" << a[top] << endl;
        top--;
        return true;
    }
}

int Stack::peek()
{
    if (top < 0)
    {
        cout << "Stack is EMPTY\n";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}

bool Stack::empty()
{
    if (top < 0)
    {
        cout << "EMPTY\n";
        return true;
    }
    else
    {
        cout << "NOT EMPTY\n";
        return false;
    }
}

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    st.pop();
    st.push(100);
    st.peek();

    while (!st.empty())
    {
        int x = st.peek();
        cout << x << " ";
        st.pop();
    }

    return 0;
}