class Solution {
public:
    bool isUgly(int n) {
              if(n==0)
            return false;
        if(n==1)
            return true;
        
        int i=2;
        while(i<=5){
            while(n%i==0){
                n/=i;
            }
            i++;
        }
        if(n==1)
            return true;
        else return false;
    
    }
};