class MyCircularQueue {
private:
    int size;
    int capacity;
    int front;
    int rear;
    int *arr;
public:
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
        front = rear = -1;
        arr = new int[k];
    }
    
    bool enQueue(int value) {
        if(size == capacity)
            return false;
        if(size == 0)
            front = 0;
        rear = (rear+1)%capacity;
        arr[rear] = value;
        // cout<<rear<<" "<<size<<endl;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size == 0)
            return false;
        if(size == 1)
            front = rear = -1;
        else
            front = (front+1)%capacity;
        // cout<<front<<" "<<size<<endl;
        size--;
        return true;
    }
    
    int Front() {
        if(size == 0)
            return -1;
        return arr[front];
    }
    
    int Rear() {
        if(size == 0)
            return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
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