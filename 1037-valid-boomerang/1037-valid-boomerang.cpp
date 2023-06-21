class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if (points[0] != points[1] and points[2] != points[1] and points[0] != points[2])
        {
            int s1y, s1x, s2y, s2x;
            s1y = points[1][1] - points[0][1];
            s1x = points[1][0] - points[0][0];
            s2y = points[2][1] - points[1][1];
            s2x = points[2][0] - points[1][0];
            
            if (s1y * s2x == s2y * s1x) return false;
            return true;            
        }
        else return false;
        
    }
};