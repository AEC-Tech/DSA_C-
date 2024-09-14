// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#define MAX 10

class Stack
{
    private:
        int st[MAX];
        int top;
    public:
    Stack()
    {
        top = -1;
    }
    void push(int value)
    {
        if(top == MAX-1)
        {
            cout<<"Overflow: No More Space"<<endl;
        }
        else
        {
            top++;
            st[top] = value;
            //cout<<"Data Inserted"<<endl;
        }
    }
    int pop()
    {
        int val = 0;
        if(top == -1)
        {
            cout<<"Underflow : Stack is Empty"<<endl;
        }
        else
        {
            val = st[top];
            top--;
        }
        return val;
    }
    void display()
    {
        if(top==-1)
        {
            cout<<"Stack is Empty"<<endl;
            
        }
        else
        {
            cout<<"Stack is "<<endl;
            for(int i = top; i>=0; i--)
            {
                cout<<st[i]<<endl;
            }
        }
    }
    int peak()
    {
        return st[top];
    }
};

int main() {
    
    char exp[50];
    int i, val1,val2,result;
    Stack s;
    cout<<"Enter the postfix expression : ";
    cin>>exp;
    for(i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '*' || exp[i] == '/' || exp[i] == '+' || exp[i] == '-')
        {
            val2 = s.pop();
            val1 = s.pop();
            if(exp[i] == '*')
                result = val1 * val2;
            if(exp[i] == '/')
                result = val1 / val2;
            if(exp[i] == '+')
                result = val1 + val2;
            if(exp[i] == '-')
                result = val1 - val2;
            s.push(result);
        }
        else
        {
            s.push(exp[i]-48);
        }
    }
    printf("\nResult is %d",s.pop());
    return 0;
}
