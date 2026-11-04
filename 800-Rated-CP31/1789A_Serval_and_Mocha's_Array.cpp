/*
Problem: 1789A - Serval and Mocha's Array (Codeforces Rating 800)

An array a of positive integers is good iff gcd of all its elements <= its length.
An array is beautiful iff all its prefixes of length >= 2 are good.
Determine whether array a can become beautiful after reordering its elements.

Input:
The first line contains t (1 <= t <= 500) — number of test cases.
Each test case consists of:
1. An integer n (2 <= n <= 100) — length of array.
2. n integers a1, a2, ..., an (1 <= ai <= 10^6).

Output:
For each test case, print "Yes" if possible to reorder, and "No" otherwise.

Example:
Input:
6
2
3 6
3
1 2 4
3
3 6 1
3
15 35 21
4
35 10 35 14
5
1261 227821 143 4171 1941

Output:
No
Yes
Yes
No
Yes
Yes

Intuition:
- The GCD of a sequence is monotonically non-increasing as more elements are added:
  gcd(a1, a2, ..., ak) <= gcd(a1, a2).
- If we can find ANY two elements (ai, aj) such that gcd(ai, aj) <= 2, we can simply 
  place them at the beginning (a1 = ai, a2 = aj):
  - Length 2: gcd(a1, a2) <= 2 <= 2 (good)
  - Length k >= 3: gcd(a1, ..., ak) <= gcd(a1, a2) <= 2 < k (always good!)
- Conversely, if EVERY pair has gcd(ai, aj) >= 3, then no matter what we place at 
  indices 1 and 2, gcd(a1, a2) >= 3 > 2, which makes the length-2 prefix impossible.
- Thus, the array can be made beautiful if and only if there exists at least one pair 
  with gcd(ai, aj) <= 2.

Time Complexity: O(n^2 * log(min(ai, aj))) per testcase (checking all pairs with n <= 100)
Auxiliary Space Complexity: O(n) to store the array elements
*/

#include <iostream>
#include <vector>
#include <numeric>

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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool possible = false;
        // Check all pairs to see if any has gcd <= 2
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (std::gcd(a[i], a[j]) <= 2) {
                    possible = true;
                    break;
                }
            }
            if (possible) break;
        }

        if (possible) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}