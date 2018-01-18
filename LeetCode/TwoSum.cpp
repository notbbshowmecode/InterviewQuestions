class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dict;
        dict[nums[0]] = 0;
        for (int i = 1; i < nums.size(); i++) {
            int x = target-nums[i];
            if (dict.find(x) != dict.end()) {
                return {dict[x], i};
            }
            dict[nums[i]] = i;
        }
    }
};