/*
Problem: 1766A - Extremely Round (Codeforces Rating 800)

A positive integer is called extremely round if it has only one non-zero digit.
Given an integer n (1 <= n <= 999999), calculate the number of extremely round 
integers x such that 1 <= x <= n.

Input:
The first line contains t (1 <= t <= 10^4) — number of test cases.
Each test case contains one integer n (1 <= n <= 999999).

Output:
For each test case, print the number of extremely round integers <= n.

Example:
Input:
5
9
42
13
100
111

Output:
9
13
10
19
19

Intuition:
- An extremely round number has the form d * 10^k where 1 <= d <= 9.
- For every digit length, there are exactly 9 extremely round numbers:
  1-digit: 1, 2, ..., 9 (9 numbers)
  2-digit: 10, 20, ..., 90 (9 numbers)
  3-digit: 100, 200, ..., 900 (9 numbers)
- If n has length L and its first digit is F (e.g. for 42: L = 2, F = 4):
  1. All numbers with strictly fewer digits contribute: 9 * (L - 1).
  2. Numbers with length L <= n are: 10^(L-1), 2*10^(L-1), ..., F*10^(L-1), contributing F.
- Total count = 9 * (L - 1) + F.

Time Complexity: O(1) per testcase (reading as string and computing formula)
Auxiliary Space Complexity: O(1)
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int len = s.length();
        int first_digit = s[0] - '0';

        // 9 numbers for each previous digit length + first_digit for the current length
        int ans = 9 * (len - 1) + first_digit;
        cout << ans << "\n";
    }
    return 0;
}