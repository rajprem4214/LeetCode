class MyCircularQueue {
public:
    int size;
    vector<int> vec;
    int f=0,r=0;
    MyCircularQueue(int k) {
        vec.resize(k+1);
        size=k+1;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        r=(r+1)%size;
        vec[r]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        f=(f+1)%size;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        int g=f;
        g=(g+1)%size;
        return vec[g];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return vec[r];
    }
    
    bool isEmpty() {
        if(r == f)
            return true;
        return false;
    }
    
    bool isFull() {
        if((r+1)%size == f)
            return true;
        return false;
    }
};