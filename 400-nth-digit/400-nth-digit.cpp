class Solution {
public:
    int noOfDigits(int x)
    {
        int count = 0;
        while(x)
        {
            count += 1;
            x /= 10;
        }
        return max(1, count);
    }
    long long int totalDigits(int n)
    {
        if(n == 0)
            return 0;
        int digNum = noOfDigits(n);
        long long int i = 1, count = 0;
        
        while(i < digNum)
        {
            count += i * (pow(10, i) - pow(10, i - 1));
            i += 1;
        }
        count += (n - pow(10, i-1) + 1) * i;
        return count;
    }
    
    int findNthDigit(int n) {
        
        long long int i, r, d, x, low = 0, mid, high = n;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            d = noOfDigits(mid);
            x = totalDigits(mid-1);
            
            if(x >= n)
                high = mid - 1;
            else if(n > x && n <= x + d)
            {
                n = n - x;
                break;
            }
            else
                low = mid + 1;
        }
        for(i=0;i<=d-n;i++)
        {
            r = mid % 10;
            mid /= 10;
        }
        return r;
    }
};