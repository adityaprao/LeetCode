class Solution {
public:
    
//     int firstOccurence(vector<int> &nums, int target)
//     {
//         int l = 0, r = nums.size() - 1, pos = -1; 
        
//         while (l <= r)
//         {
//             int mid = l + (r-l)/2;
//             if (nums[mid] > target) r = mid-1;
//             else if (nums[mid] < target) l = mid+1;
//             else
//             {
                
//             }
//         }
//         return pos;
//     }
    
    int Occurence(vector<int> &nums, int target, int type)
    {
        int l = 0, r = nums.size() - 1, pos = -1; 
        
        while (l <= r)
        {
            int mid = l + (r-l)/2;
            if (nums[mid] > target) r = mid-1;
            else if (nums[mid] < target) l = mid+1;
            else
            {
                if (type == 1)
                {
                    pos = mid;
                    r = mid-1;                    
                }
                else
                {
                    pos = mid;
                    l = mid+1;                    
                }
                    
            }
        }
        return pos;        
    }
    
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> ans(2);
        ans[0] = Occurence(nums, target, 1), ans[1] = Occurence(nums, target, 2);
        return ans;        
        
    }
};