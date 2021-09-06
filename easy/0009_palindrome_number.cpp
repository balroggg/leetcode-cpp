#include <catch2/catch_test_macros.hpp>

namespace {

using namespace std;

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    int rev = 0;
    while (x > rev) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return x == rev || x == rev / 10;
}

} // end of namespace

TEST_CASE( "Problem 9: Palindrome number", "[easy]" ) {
    {
        // Input: x = 121
        // Output: true
        REQUIRE(isPalindrome(121) == true);
    }
    {
        // Input: x = -121
        // Output: false
        REQUIRE( isPalindrome(-121) == false);
    }
    {
        // Input: x = 10
        // Output: false
        REQUIRE( isPalindrome(10) == false);
    }
    {
        // Input: x = -101
        // Output: false
        REQUIRE(isPalindrome(-101) == false);
    }
}
