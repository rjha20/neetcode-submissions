class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        
        // Step 1: Count frequencies
        for (int num : nums) {
            count[num]++;
        }
        
        // Step 2: Create buckets where index = frequency
        vector<vector<int>> buckets(n + 1);
        for (auto& p : count) {
            int num = p.first;
            int freq = p.second;
            buckets[freq].push_back(num);
        }
        
        // Step 3: Collect the top k frequent elements
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        
        return result;
    }
};