class BrowserHistory {
private:
    int cur = 0;
    int forward_max = 0;
    vector<string> history;
public:
    BrowserHistory(string homepage) {
        this->history = vector<string>(5000);
        this->history[0] = homepage;
    }
    
    void visit(string url) {
        this->cur++;
        this->history[this->cur] = url;
        this->forward_max = this->cur;
    }
    
    string back(int steps) {
        this->cur = max(0, this->cur - steps);
        return history[this->cur];
    }
    
    string forward(int steps) {
        this->cur = min(this->forward_max, this->cur + steps);
        return history[this->cur];
    }
};