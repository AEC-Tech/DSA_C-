// Implementing Queue using Linear Array
#include <iostream>
using namespace std;
#define MAX  10
class Queue
{
    private:
    int data[MAX];
    int front,rear;
    public:
    Queue()
    {
        front = rear = -1;
    }
    void enque(int val)
    {
        if(rear == MAX-1)
            cout<<"Overflow - Queue is Full"<<endl;
        else if(rear == -1)
        {
            front = rear = 0;
            data[rear]= val;
        }
        else
        {
            rear++;
            data[rear] = val;
        }
    }
    int deque()
    {
        int d =0;
        if(front == -1)
            cout<<"Underflow-Queue is Empty"<<endl;
        else if(front == rear)
        {
            d = data[front];
            front = rear = -1;
        }
        else
        {
            d = data[front];
            front++;
        }
        return d;
    }
    void display()
    {
        if(front == -1)
            cout<<"Queue is Empty "<<endl;
        else
        {
            cout<<"Queue is "<<endl;
            for(int i = front; i<=rear; i++)
                cout<<data[i]<<endl;
        }
    }
};
int main() {
    Queue q;
    int ch,num;
    do
    {
        cout<<"Press 1 - Add"<<endl;
        cout<<"Press 2 - Remove"<<endl;
        cout<<"Press 3 - Diaply"<<endl;
        cout<<"Press 4 - Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter a number : ";
                cin>>num;
                q.enque(num);
                break;
            case 2:
                num = q.deque();
                cout<<"Deleted Value is "<<num<<endl;
                break;
            case 3:
                q.display();
                break;
        }
    }while(ch!=4);
    return 0;
}
