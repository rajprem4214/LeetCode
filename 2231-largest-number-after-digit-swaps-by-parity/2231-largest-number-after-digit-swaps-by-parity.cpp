class Solution {
public:
    int largestInteger(int num) {
      string s = to_string(num);
      priority_queue<char> pq1,pq2;
      
      
      for(int i=0;i<s.length();i++){
          if((s[i]-'0') % 2==0)
              pq1.push(s[i]);
          else
              pq2.push(s[i]);
      }   
        
      
        for(int i=0;i<s.length();i++){
            if((s[i]-'0') % 2 == 0)
            {
                s[i] = pq1.top();
                pq1.pop();
            }
            else{
                s[i] = pq2.top();
                 pq2.pop();                
            }
            
        }
        
        return stoi(s);
    
        
        
    }
};