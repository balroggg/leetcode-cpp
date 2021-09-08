#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <numeric>

namespace {

using namespace std;

// C++17
int findGCD(vector<int>& nums)
{
    const auto [min, max] = std::minmax_element(begin(nums), end(nums));
    return std::gcd(*min, *max);
}

// C++20
int findGCD_v2(vector<int>& nums)
{
    const auto [min, max] = std::ranges::minmax_element(nums);
    return std::gcd(*min, *max);
}

} // end of namespace

TEST_CASE("Problem 1979: Find gcd of array", "[easy]")
{
    {
        // Input: nums = [2,5,6,9,10]
        // Output: 2
        vector<int> nums = { 2, 5, 6, 9, 10 };
        REQUIRE(findGCD(nums) == 2);
        REQUIRE(findGCD_v2(nums) == 2);
    }
    {
        // Input: nums = [7,5,6,8,3]
        // Output: 1
        vector<int> nums = { 7, 5, 6, 8, 3 };
        REQUIRE(findGCD(nums) == 1);
        REQUIRE(findGCD_v2(nums) == 1);
    }
    {
        // Input: nums = [3,3]
        // Output: 3
        vector<int> nums = { 3, 3 };
        REQUIRE(findGCD(nums) == 3);
        REQUIRE(findGCD_v2(nums) == 3);
    }
}
