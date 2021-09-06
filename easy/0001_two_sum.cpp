#include <catch2/catch_test_macros.hpp>

#include <vector>
#include <unordered_map>

namespace {

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, int> map;
    for (size_t i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (map.contains(complement)) {
            return { map[complement], static_cast<int>(i) };
        }
        map[nums[i]] = static_cast<int>(i);
    }
    return {-1, -1};
}

} // end of namespace

TEST_CASE( "Problem 1: Two sum", "[easy]" ) {
    {
        // Input: nums = [2,7,11,15], target = 9
        // Output: [0,1]
        vector<int> nums = {2, 7, 11, 15};
        vector<int> exp = {0, 1};
        auto sum = twoSum(nums, 9);
        REQUIRE( sum == exp );
    }
    {
        // Input: nums = [3,2,4], target = 6
        // Output: [1,2]
        vector<int> nums = {3, 2, 4};
        vector<int> exp = {1, 2};
        auto sum = twoSum(nums, 6);
        REQUIRE( sum == exp );
    }
    {
        // Input: nums = [3,3], target = 6
        // Output: [0,1]
        vector<int> nums = {3, 3};
        vector<int> exp = {0, 1};
        auto sum = twoSum(nums, 6);
        REQUIRE( sum == exp );
    }
}
