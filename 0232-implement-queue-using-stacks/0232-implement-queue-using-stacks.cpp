class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    MyQueue() {
        
    }
    
    void push(int x) {
       input.push(x); 
    }
    
    int pop() {
       if(output.empty()){
           while(!input.empty()){
             int y=  input.top();
             output.push(y);
             input.pop();
           }
           int z=output.top();
           output.pop();
           return z;
       }
       else{
           int z=output.top();
           output.pop();
           return z;
       } 
    }
    
    int peek() {
        if(output.empty()){
           while(!input.empty()){
             int y=  input.top();
             output.push(y);
             input.pop();
           }
          int z=output.top();
           //output.pop();
           return z;
       }
       else{
          int z=output.top();
          // output.pop();
           return z;
       } 
    }
    
    bool empty() {
       if(input.empty() && output.empty()){return true;} 
       else{ return false;}  
    }
};
