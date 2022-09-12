class Solution {
public:
    int bagOfTokensScore(vector<int>& tok, int p) {
        int n=tok.size();
        sort(tok.begin(),tok.end());
        //two pointer with greedy approch
        int i=0,j=n-1;
        int score=0;
        int ans=0;
        while(i<=j){
            if(tok[i]<=p){
                p-=tok[i];
                i++;
                score++;
                ans=max(ans,score);
            }
            else if(score>0){
                p+=tok[j];
                j--;
                score--;
            }
            else{
                break;
            }
        }
         return ans;
    }
};