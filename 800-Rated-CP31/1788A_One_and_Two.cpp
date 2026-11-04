/*
Problem: 1788A - One and Two (Codeforces Rating 800)

Given a sequence a1, a2, ..., an where each element is 1 or 2.
Find the smallest integer k (1 <= k <= n - 1) such that:
a1 * a2 * ... * ak = a_{k+1} * ... * an.
If no such k exists, output -1.

Input:
The first line contains t (1 <= t <= 100) — number of test cases.
Each test case consists of:
1. An integer n (2 <= n <= 1000) — length of array.
2. n integers a1, a2, ..., an (1 <= ai <= 2).

Output:
For each test case, output the smallest valid k, or -1 if impossible.

Example:
Input:
3
6
2 2 1 2 1 2
3
1 2 1
4
1 1 1 1

Output:
2
-1
1

Note:
- Test 1: k = 2 gives 2*2 = 4 and 1*2*1*2 = 4 -> k = 2.
- Test 2: Only one 2 exists, impossible to balance -> -1.
- Test 3: No 2s exist (total count = 0). At k = 1: prefix prod = 1, suffix prod = 1 -> k = 1.

Intuition:
- The array only contains 1s and 2s.
- 1 does not affect multiplication. Therefore, the product of a segment is 2^(count of 2s).
- The condition holds if and only if:
  (count of 2s in prefix 1..k) == (count of 2s in suffix k+1..n).
- If the total count of 2s is odd, it can never be divided equally -> -1.
- If total 2s is even, we need the prefix to contain exactly (total_2s / 2) twos.
- We check 0 <= i < n - 1 (ensuring 1 <= k <= n - 1) and output the first index where 
  prefix_2s == suffix_2s.

Time Complexity: O(n) per testcase (single pass to count, single pass to find k)
Auxiliary Space Complexity: O(n) to store the array
*/

#include <iostream>
#include <vector>

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
        int total_twos = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 2) {
                total_twos++;
            }
        }

        // An odd number of 2s cannot be split equally
        if (total_twos % 2 != 0) {
            cout << -1 << "\n";
            continue;
        }

        int current_twos = 0;
        int ans = -1;

        // Check valid split points 0 <= i < n - 1 (1 <= k <= n - 1)
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == 2) {
                current_twos++;
            }

            if (current_twos == total_twos - current_twos) {
                ans = i + 1; // 1-based index
                break;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}