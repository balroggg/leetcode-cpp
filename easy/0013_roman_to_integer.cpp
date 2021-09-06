#include <catch2/catch_test_macros.hpp>

#include <unordered_map>
#include <string>

namespace {

using namespace std;

int romanToInt(string s) {
    std::unordered_map<char, int> map = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    int sum = 0;
    for (size_t i = 0; i < s.size() -1; i++) {
        int left = map[s[i]];
        int right = map[s[i+1]];
        if (left < right) {
            sum -= left;
        } else {
            sum += left;
        }
    }
    sum += map[s[s.size() - 1]];
    return sum;
}

} // end of namespace

TEST_CASE( "Problem 13: Roman to integer", "[easy]" ) {
    {
        // Input: s = "III"
        // Output: 3
        REQUIRE(romanToInt("III") == 3);
    }
    {
        // Input: s = "IV"
        // Output: 4
        REQUIRE(romanToInt("IV") == 4);
    }
    {
        // Input: s = "IX"
        // Output: 9
        REQUIRE(romanToInt("IX") == 9);
    }
    {
        // Input: s = "LVIII"
        // Output: 58
        REQUIRE(romanToInt("LVIII") == 58);
    }
    {
        // Input: s = "MCMXCIV"
        // Output: 1994
        REQUIRE(romanToInt("MCMXCIV") == 1994);
    }
}
