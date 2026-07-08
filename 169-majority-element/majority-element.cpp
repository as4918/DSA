class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,int> mp;


        // count frequency of every number
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }


        // find element whose count > n/2
        for(auto it : mp)
        {
            if(it.second > n/2)
            {
                return it.first;
            }
        }


        return -1;
    }
};