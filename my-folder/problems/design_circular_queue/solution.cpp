class MyCircularQueue {
public: 
    int* arr;
    int size;
    int front;
    int rear;
    MyCircularQueue(int k) {
        size=k;
        arr=new int[size];
        front=-1;
        rear=-1;
    }
    
    bool enQueue(int data) {
        // cout<<"enq  "<<isFull()<<"  data is  "<<data<<endl;
        // cout<<"f "<<front<<endl;
        // cout<<"r "<<rear<<endl;
        // cout<<endl;
        if(isFull()){
            return false;
        }
        else if(front==-1)   //1st ele
        {
            front=rear=0;
            arr[rear]=data;
        }
        else if(front !=0 && rear==size-1)
        {
            rear=0;
            arr[rear]=data;
        }
        else
        {
            rear++;
            arr[rear]=data;
        }
        return true;

    }
    
    bool deQueue() {
        // cout<<"d"<<endl;
        // cout<<"f "<<front<<endl;
        // cout<<"r "<<rear<<endl;
        // cout<<endl;
        if(isEmpty())
            return false;
        
        if(front==rear)
        {
            front=rear=-1;
        }
        else if(front==size-1)
        {
            front=0;
        }
        else
        {
            front++;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        else
            return arr[front];
    }
    
    int Rear() {
        // cout<<"rear "<<isEmpty()<<"  "<<arr[rear]<<endl;
        if(isEmpty())
            return -1;
        else
            return arr[rear];
    }
    
    bool isEmpty() {
        if(front==-1)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if(size==2)
        {
            if(abs(front-rear)==1)
            return true;
            else
            return false;
        }
        if (size==1)
        {
            if(front==0 && rear==0)
            return true;
            else 
            return false;
        }
        if((front==0 && rear==size-1) || rear==(front-1)%(size-1))
            return true;
        else
            return false;

    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */