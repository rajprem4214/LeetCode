class Solution {
public:
   int bulbSwitch(int n) {
        
       // return sqrt(n) ;
        
        // alternate approach every 1st , 4th , 9th means like there will differnce of odd 
        // 3 , 5 , 7 , 9 , 11 , this way 
        
        int count = 0 ;
        int f = 1 ;
        
        
        for( int i = 1 ; i <= n ; )
        {
            count++ ;
            i = i + 2*f + 1 ;
            f++ ;
        }
        
        return count ;
        
        
    }
};