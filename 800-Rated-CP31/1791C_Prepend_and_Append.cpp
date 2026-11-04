/*
Problem: 1791C - Prepend and Append (Codeforces Rating 800)

Timur initially had a binary string s (possibly of length 0). 
He performed the following operation zero or more times:
- Add '0' to one end of the string and '1' to the other end (either 0...1 or 1...0).

Given Timur's final string of length n, find the length of the shortest possible 
original string he could have started with.

Input:
The first line contains an integer t (1 <= t <= 100) — number of test cases.
Each test case consists of:
1. An integer n (1 <= n <= 2000) — length of the final string.
2. A binary string s of length n.

Output:
For each test case, output a single non-negative integer — shortest possible original length.

Example:
Input:
9
3
100
4
0111
5
10101
6
101010
7
1010110
1
1
2
10
2
11
10
1011011010

Output:
1
2
5
0
3
1
0
2
4

Note:
- Test 1: "100" -> outer chars are '1' and '0' (different), peel them off -> original was "0" (length 1).
- Test 4: "101010" -> can be completely peeled off to empty string (length 0).
- Test 7: "11" -> outer chars are both '1' (same), cannot be peeled -> original was "11" (length 2).

Intuition:
- In each operation, Timur prepends and appends opposite characters (one '0', one '1').
- We can reverse the process using two pointers starting from both ends:
  - If s[left] != s[right]: These two characters could have been added by an operation.
    We peel them off (left++, right--) and decrease remaining length by 2.
  - If s[left] == s[right]: These two characters could NEVER have been added by an operation 
    (since the operation always adds opposite bits). We must stop immediately.
- The remaining length (right - left + 1) is the minimum original length.

Time Complexity: O(n) per testcase (each character inspected at most once)
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
        int n;
        cin >> n;
        string s;
        cin >> s;

        int left = 0;
        int right = n - 1;
        int ans = n;

        // Peel off matching opposite endpoints from outside inward
        while (left < right) {
            if (s[left] != s[right]) {
                ans -= 2;
                left++;
                right--;
            } else {
                break; // Same characters cannot be peeled
            }
        }

        cout << ans << "\n";
    }
    return 0;
}