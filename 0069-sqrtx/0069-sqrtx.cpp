class Solution {
public:
    int mySqrt(int x) 
    {
        long long l = 0, r = x + 1LL;
        while (l < r)
        {
            long long int m = l + (r-l)/2LL;
            if (m * m > x)
            {
                r = m;
            }
            else l = m + 1;
        }
        return l - 1;
        
        
    }
};