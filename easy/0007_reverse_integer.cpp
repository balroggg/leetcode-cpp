#include <catch2/catch_test_macros.hpp>

#include <string>

namespace {

using namespace std;

long long reverse(int x) {
    auto s = std::to_string(x);
    auto pos = s.find_last_not_of('0');
    if (pos != std::string::npos)
        s.resize(pos+1);
    if (s[0] == '-') {
        s = s.substr(1);
        std::reverse(s.begin(), s.end());
        s.insert(s.begin(), '-');
    }
    else {
        std::reverse(s.begin(), s.end());
    }
    try {
        return stoi(s);
    } catch (...) {
        return 0;
    }
}

long long reverse2(int x) {
    long long num = 0;
    constexpr int MAX10 = std::numeric_limits<int>::max()/10;
    constexpr int MIN10 = std::numeric_limits<int>::min()/10;
    while(x) {
        auto pop = x%10;
        x /= 10;
        if (num > MAX10 || (num == MAX10 && pop >  7)) return 0;
        if (num < MIN10 || (num == MIN10 && pop < -8)) return 0;
        num = num * 10 + pop;
    }
    return num;
}

} // end of namespace

TEST_CASE( "Problem 7: Reverse integer", "[easy]" ) {
    {
        // Input: x = 123
        // Output: 321
        REQUIRE(reverse(123) == 321);
        REQUIRE(reverse2(123) == 321);
    }
    {
        // Input: x = -123
        // Output: -321
        REQUIRE(reverse(-123) == -321);
        REQUIRE(reverse2(-123) == -321);
    }
    {
        // Input: x = 120
        // Output: 21
        REQUIRE(reverse(120) == 21);
        REQUIRE(reverse2(120) == 21);
    }
    {
        // Input: x = 0
        // Output: 0
        REQUIRE(reverse(0) == 0);
        REQUIRE(reverse2(0) == 0);
    }
    {
        // Input: x = 1534236469
        // Output: 0
        REQUIRE(reverse(1534236469) == 0);
        REQUIRE(reverse2(1534236469) == 0);
    }
}
