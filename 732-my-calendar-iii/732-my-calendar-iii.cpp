class MyCalendarThree {
private:
    int ans = 1;
    map<int,int> u;
public:
    MyCalendarThree() {
    }
    int book(int start, int end) {
        u[start]++,u[end]--;
        int eventCount = 0;
        for(auto it: u){
            eventCount += it.second;
            ans = max(ans, eventCount);
        }
        return ans;
    }
};