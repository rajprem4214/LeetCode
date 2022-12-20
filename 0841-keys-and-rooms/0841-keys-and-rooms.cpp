class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int n = rooms.size();
    queue<int> q;
    set<int> s;
    s.insert(0);
    for (auto it : rooms[0])
    {
        q.push(it);
        s.insert(it);
    }
    while (!q.empty())
    {
        for (auto it : rooms[q.front()])
        {
            if (s.find(it) == s.end())
            {
                q.push(it);
                s.insert(it);
            }
        }
        q.pop();
    }
    if (s.size() == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
};