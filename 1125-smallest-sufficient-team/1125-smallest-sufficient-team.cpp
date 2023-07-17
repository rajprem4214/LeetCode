class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills,
            vector<vector<string>>& people) {
        int skills = req_skills.size();
        int no_people = people.size();
        int possible = pow(2, skills);
        
        unordered_map<string, int> mapping;
        for(int i = 0; i<skills; i++){
            mapping[req_skills[i]] = i;
        }


        unordered_map<int, vector<int>> dp;
        dp.reserve(1 << skills);
        dp[0] = {};

        for(int i = 0; i<no_people; i++){
            int size = people[i].size();
            int val = 0;
            // calculating the skill value of each person
            for(int j = 0; j<size; j++){
                int index = mapping[people[i][j]];
                val = val | (1<<index);
            }

            // Iterating over the all possible combinations possible 
            // and checking if after including this person, we can 
            // get to a skill value that has a higher person count 
            // than that if we include this person
            // Or if we can get a new value that has no person 
            for (auto it = dp.begin(); it != dp.end(); ++it) {
                int comb = it->first | val;
                if (dp.find(comb) == dp.end() || 
                    dp[comb].size() > 1 + dp[it->first].size()){
                        dp[comb] = it->second;
                        dp[comb].push_back(i);
                }
            }

            // this can also be used 
            // for (auto it: dp) {
            //     int comb = it.first | val;
            //     if (dp.find(comb) == dp.end() || 
            //         dp[comb].size() > 1 + dp[it.first].size()){
            //             dp[comb] = it.second;
            //             dp[comb].push_back(i);
            //     }
            // }
            
        }

        // returning the people including at the last position 
        // i.e. when all the skill bits are set
        return dp[possible-1];
    }
};