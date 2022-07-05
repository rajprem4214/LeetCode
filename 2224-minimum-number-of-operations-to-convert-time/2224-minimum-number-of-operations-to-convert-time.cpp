class Solution
{
public:
    int convert(string &s)
    {
        return s[0] * 600 + s[1] * 60 + s[3] * 10 + s[4];
    }
    int convertTime(string current, string correct)
    {
        int d = convert(correct) - convert(current), k = 0;
        k += (d / 60) + ((d % 60) / 15) + ((d % 15) / 5) + (d % 5);
        return k;
    }
};