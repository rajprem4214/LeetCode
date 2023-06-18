class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans=0;
        while(mainTank>=5){
            ans+=5;
            mainTank-=5;
            if(additionalTank>0){
                mainTank+=1;
                additionalTank-=1;
            }
            
        }
        ans+=mainTank;
        return ans*10;
    }
};