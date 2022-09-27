class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int>right(n,0),left(n,0);
        char prev='.'; //taking ->'.'in the begining in prev
        int count=1;
        for(int i=0;i<n;i++)
        {
// -> pushing into right array elements 
            if(dominoes[i]=='R')
            {
                prev='R';
                count=1;
                continue;
            }
            else if (dominoes[i]=='L')
            {
                prev='L';       
            }
            if(prev=='R'&&dominoes[i]=='.')
            {
                right[i]=count;
                count++;
            }
        }
// ->i=pushing into left array elements
        prev='.';
        count=1;
        for(int i=n-1;i>=0;i--)
        {
            if(dominoes[i]=='L')
            {
                prev='L';
                count=1;
                continue;
            }
            else if (dominoes[i]=='R')
            {
                prev='R';
            }
            if(prev=='L'&&dominoes[i]=='.'){
                left[i]=count;
                count++;
            }
        }
        
        // for the final output
        
        string res="";
        for(int i=0;i<n;i++)
        {
            if(left[i]==0&&right[i]==0)
            {
                res+=dominoes[i];
            } 
            else if(right[i]==0)
            {
                res+='L';
            }
            else if(left[i]==0)
            {
                res+='R';
            }
            else if(right[i]==left[i])
            {
                res+='.';    
            }
            else if(right[i]>left[i])
            {
                res+='L';
            }
            else{
                res+='R';
            }
        }
        return res;
    }
};