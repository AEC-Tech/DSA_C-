
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
            cout<<"Data Inserted"<<endl;
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
    Stack s;
    int ch,val;
    do
    {
        cout<<"Press 1 - Push"<<endl;
        cout<<"Press 2 - Pop"<<endl;
        cout<<"Press 3 - Peak"<<endl;
        cout<<"Press 4 - Display"<<endl;
        cout<<"Press 5 - Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter the number to be inserted : ";
                cin>>val;
                s.push(val);
                break;
            case 2:
                val = s.pop();
                cout<<"Deleted element is "<<val<<endl;
                break;
            case 3:
                val = s.peak();
                cout<<"Top Most element of stack is "<<val<<endl;
                break;
            case 4:
            s.display();
            
                
        }
    }while(ch!=5);
    return 0;
}

