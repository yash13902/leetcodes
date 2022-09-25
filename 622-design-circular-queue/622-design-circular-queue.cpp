class MyCircularQueue {
public:
    // vector<int> v; 
    unordered_map<int,int> v;
    int size,front=-1,rear=-1;
    MyCircularQueue(int k) {
        size = k;
        // v(size) {};
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        //insert
        if(isEmpty()){
            front = 0;
            rear = 0;
        }
        else{
            rear++;
            if(rear == size){
                rear = 0;  
            }
        }
        v[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        //delete
        front++;
        if(front == rear+1){
            front = -1;
            rear = -1;
        } else if(front == size){
            front = 0;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return v[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return v[rear];
    }
    
    bool isEmpty() {
        if(rear == -1) return true;
        return false;
    }
    
    bool isFull() {
        if(rear == size-1 && front == 0) return true;
        if(front == rear+1) return true;
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