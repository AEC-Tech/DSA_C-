
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
    bool isEmpty()
    {
        if(top == -1)
        return true;
        else
        return false;
    }
};

int main() {
    Stack s;
    char exp[50],postfix[50];
    int i,j=0;
    cout<<"Enter the Infix Expression : ";
    cin>>exp;
    for(i=0; exp[i]!='\0';i++)
    {
        // Operand
        if(!(exp[i] == '+' || exp[i] == '*' || exp[i] == '/' || exp[i] == '-' || exp[i]=='(' || exp[i]==')'))
        {
            postfix[j++] = exp[i];
        }
        // Symbol is an operator
        else if(s.isEmpty() || s.peak() == '(') 
        {
            s.push(exp[i]);
        }
        else if(exp[i] == '(')
        {
            s.push(exp[i]);
        }
        else if(exp[i] == ')')
        {
            while(s.peak() != '(')
            {
                postfix[j++] = s.pop();
            }
            s.pop();
        }
        else if(exp[i] == '*' || exp[i] == '/')
        {
            if(s.peak() == '*' || s.peak() == '/')
            {
                postfix[j++] = s.pop();
            }
            s.push(exp[i]);
        }
        else if(exp[i] == '+' || exp[i] == '-')
        {
            while(!s.isEmpty() && s.peak()!='(')
            {
                postfix[j++] = s.pop();
            }
            s.push(exp[i]);
        }
    }
    while(!s.isEmpty())
    {
        postfix[j++] = s.pop();
    }
    postfix[j] = '\0';
    cout<<"\nPostfix Expression is " <<postfix<<endl;
    return 0;
}



















