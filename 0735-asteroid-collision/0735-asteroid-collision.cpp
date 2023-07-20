class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;

        for(auto& i : asteroids) {

            if(!s.empty() && s.back() > 0 && i < 0) {
                int flag = 1;
                while(!s.empty() && s.back() > 0 && i < 0) {
                    if(abs(s.back()) < abs(i)) {
                        s.pop_back();
                    }
                    else if(abs(s.back()) == abs(i)) {
                        s.pop_back();
                        flag = 0;
                        break;
                    }
                    else {
                        flag = 0;
                        break;
                    }
                }

                if(flag) {
                    s.push_back(i);
                }

            }
            else {
                s.push_back(i);
            }
        }

        return s;
    }
};