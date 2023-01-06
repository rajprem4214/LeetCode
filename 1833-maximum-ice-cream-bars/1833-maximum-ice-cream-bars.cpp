class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
      sort(begin(costs),end(costs));
        int count=0;
        for(int i=0;i<costs.size();i++)
        {
            if(costs[i]<=coins)
            {count++;coins-=costs[i];}
        }
        return count;  
    }
};