// Time O(n) & Space O(1)

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> answer;
        int product = 1;
        int numZero = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0 && numZero <= 1)
            {
                product = product * nums[i];
            }
            else if (numZero == 0 && nums[i] == 0)
            {
                numZero++;
            }
            else
            {
                vector<int> allZero(n, 0);
                return allZero;
            }
        }
        if (numZero == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == 0)
                {
                    answer.push_back(product);
                }
                else
                {
                    answer.push_back(0);
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                answer.push_back(product / nums[i]);
            }
        }

        return answer;
    }
};