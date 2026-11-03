/*
Problem: 1814A - Coins (Codeforces Rating 800)

In Berland, coins have denominations of 2 and k burles.
Determine whether it is possible to represent n burles using these coins:
2*x + k*y = n for non-negative integers x, y >= 0.

Input:
The first line contains a single integer t (1 <= t <= 10^4) — number of test cases.
Each test case contains two integers n and k (1 <= k <= n <= 10^18; k != 2).

Output:
For each test case, print YES if possible, and NO otherwise.

Example:
Input:
4
5 3
6 1
7 4
8 8

Output:
YES
YES
NO
YES

Note:
- Test 1 (n=5, k=3): 2(1) + 3(1) = 5 -> YES.
- Test 2 (n=6, k=1): 2(3) + 1(0) = 6 -> YES.
- Test 3 (n=7, k=4): 2x + 4y is always even, cannot equal 7 -> NO.
- Test 4 (n=8, k=8): 2(0) + 8(1) = 8 -> YES.

Intuition:
- We need 2x + ky = n for x, y >= 0.
- Since 2x is always even:
  1. If n is even: We can pick y = 0, giving 2x = n => x = n / 2. Always YES.
  2. If n is odd: ky must be odd (Even + Odd = Odd).
     - This requires k to be odd.
     - If k is odd, we can pick y = 1, giving 2x = n - k => x = (n - k) / 2.
     - Since k <= n, n - k >= 0 and is even (Odd - Odd = Even). Always YES.
     - If k is even, ky is always even, so 2x + ky is always even != odd n. Impossible -> NO.
- Therefore, the answer is YES if and only if n is even OR (n - k) is even.

Time Complexity: O(1) per testcase
Auxiliary Space Complexity: O(1)
*/

#include <iostream>

using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // Check if n can be formed with y = 0 (n is even) or y = 1 ((n - k) is even)
        if (n % 2 == 0 || (n - k) % 2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}