#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {  // Fix inner loop
                if(nums[i] + nums[j] == target) {
                    return {i, j};  // Return a vector of indices
                }
            }
        }
        return {};  // Return an empty vector if no solution is found
    }
};