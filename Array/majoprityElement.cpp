class Solution
{
public:
    // Brute force
    // int majorityElement(vector<int>& nums) {
    //     int n = nums.size();
    //     int lim;
    //     if (n%2 == 0) {
    //         lim = n/2;
    //     }else{
    //         lim = n/2 + 1;
    //     }
    //     map<int, int> mp;
    //     for (int i = 0; i<n;i++){
    //         mp[nums[i]]++;
    //         if(mp[nums[i]]>=lim){
    //             return nums[i];
    //         }
    //     }
    //     return -1;
    // }

    // in O(1) space complexity
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int r = nums[0];
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (r == nums[i])
            {
                count++;
            }
            else
            {
                if (count == 0)
                {
                    r = nums[i];
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }
        return r;
    }
};