class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> arr;
        
        for(int i=0;i<speed.size();i++)
            arr.push_back({efficiency[i],speed[i]});
        
        sort(arr.begin(),arr.end());  //sort array krdo on the basis of efficiency
        priority_queue<int,vector<int>,greater<int>> pq;  //pq me hum speed store krege and k size ke baad hum min speed wala remove krdege
        
        long long maxPerformance=0; 
        long long sum=0;
        for(int i=n-1;i>=0;i--)
        {
             //IMPORTANT --> as ye sorted hai aur hum piche se shuru kr rhe hai to iska mtlb jis index p hum khde hai vo hi minEfficiency hai 
            int minEfficiency=arr[i][0]; 
            
            sum+=arr[i][1]; // speed sum till now
            pq.push(arr[i][1]); //push speed into priority queue
            
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
             maxPerformance=max(maxPerformance,sum*minEfficiency);
        }
        return maxPerformance%1000000007;
    }
};