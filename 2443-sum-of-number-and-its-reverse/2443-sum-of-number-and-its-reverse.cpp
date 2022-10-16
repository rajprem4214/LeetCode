class Solution {
public:
    int check(int num)
    {
        int rev_num=0;
        while (num > 0) {
		rev_num = rev_num * 10 + num % 10;
		num = num / 10;
	}
	return rev_num;
    }
    
    bool sumOfNumberAndReverse(int nums) {
        for(int i=0;i<=nums;i++)
        {
            int x = check(i);
            // string a=to_string(x);
            // string b=to_string(nums-i);
            // if(a.size()<b.size())
            // {
            //     a="0"+a;
            // }
            // else if(b.size()<a.size())
            //     b="0"+b;
            
            if(x==nums-i)
            {
                return true;
                break;
            }
        }
        return false;
    }
};