class Solution {
 public:

    int minimumOperations(vector<int>& nums) {
 
		if(nums.size() == 1)return 0;

		int n = nums.size();
		unordered_map<int ,int> mp1 , mp2;
		for(int i=0;i<n;i++){
			(i&1) ? mp1[nums[i]]++ : mp2[nums[i]]++;
		}

		vector<pair<int ,int>> vp1 ,vp2;
		for(auto it : mp1)vp1.push_back({it.second , it.first});
		for(auto it : mp2)vp2.push_back({it.second , it.first});
		sort(vp1.begin() , vp1.end());sort(vp2.begin() , vp2.end());

		int num1  = vp1[vp1.size() - 1].second , freq1 = vp1[vp1.size() - 1].first; 
		int num2  = vp2[vp2.size() - 1].second , freq2 = vp2[vp2.size() - 1].first;

		if(num1 == num2){
			if(vp1.size() == 1 && vp2.size() == 1){
				  return n/2;
			} 
			else if(vp1.size() == 1){
				 int ans2 = vp2[vp2.size() - 2].first;
				 return n - freq1 - ans2;
			}
			else if(vp2.size() == 1){
				 int ans1 = vp1[vp1.size() - 2].first;
				 return n - freq2 - ans1;
			}
			else{
				 int ans1 = vp1[vp1.size() - 2].first;
				 int ans2 = vp2[vp2.size() - 2].first;         
				 return min( n - freq1 - ans2 , n - freq2 - ans1 ); 
			}
		}else{
			return n - freq1 - freq2;
		}
	}  
};