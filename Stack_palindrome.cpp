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
    
    char str[50];
    int i;
    Stack s;
    cout<<"Enter a String : ";
    cin>>str;
    for(i=0; str[i]!='\0'; i++)
    {
        s.push(str[i]);
    }
    for(i=0; str[i]!='\0';i++)
    {
        if(str[i] != s.pop())
        {
            cout<<"Not a Palindrome"<<endl;
            break;
        }
    }
    if(str[i] == '\0')
    cout<<"String is a Palindrome";
    return 0;
}












