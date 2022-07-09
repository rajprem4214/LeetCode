class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
          int n = bank.size(), m = bank[0].size() , ans=0;
    
    for(int i=0; i<n; i++){
        
        int p1 = 0, p2=0;
        
        for(int j=0; j<m; j++){
            
            if(bank[i][j] == '1') p1++;
            
        }
        
        for(int k=i+1; k<n; k++){
            
            for(int l=0; l<m; l++){
                
                if(bank[k][l] == '1') p2++;
                
            }
            
            if(p2 != 0){
                
                ans += p1*p2;
                i = k-1;
                break;
            }
            
        }
        
        
    }
    
    return ans;
    

    }
};