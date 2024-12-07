// Implementation of Queue Using Circular Array
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
        if(front == 0 && rear == MAX-1 || front == rear + 1)
            cout<<"Overflow - Queue is Full"<<endl;
        else if(rear == -1)
        {
            front = rear = 0;
            data[rear]= val;
        }
        else
        {
            if(rear == MAX -1)
                rear = 0;
            else
                rear++;
            //rear++;
            //rear = rear % MAX;
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
            front = front % 10;
        }
        return d;
    }
    void display()
    {
        if(front == -1)
            cout<<"Queue is Empty "<<endl;
        else
        {
            int i;
            cout<<"Queue is "<<endl;
            if(front <=rear)
            {
            for(i = front; i<=rear; i++)
                cout<<data[i]<<endl;
            }
            else
            {
                for(i = front; i<MAX;i++)
                cout<<data[i]<<endl;
                for(i = 0; i<=rear;i++)
                cout<<data[i]<<endl;
            }
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
