/*
Problem: 1805A - We Need the Zero (Codeforces Rating 800)

There is an array a of non-negative integers. You can choose an integer x 
and denote b_i = a_i ^ x for all 1 <= i <= n.
Determine if there exists an integer x (0 <= x < 2^8) such that:
b_1 ^ b_2 ^ ... ^ b_n = 0.
If valid x exists, output it; otherwise, output -1.

Input:
The first line contains t (1 <= t <= 1000) — number of test cases.
Each test case consists of:
1. An integer n (1 <= n <= 1000) — length of the array a.
2. n integers a1, a2, ..., an (0 <= ai < 2^8).
Sum of n over all test cases <= 1000.

Output:
For each test case, output x (0 <= x < 2^8) or -1 if impossible.

Example:
Input:
5
3
1 2 5
3
1 2 3
4
0 1 2 3
4
1 2 2 3
1
1

Output:
6
0
3
-1
1

Note:
In test 1, x = 6 gives [7, 4, 3], and 7 ^ 4 ^ 3 = 0.
In test 4, total XOR is 0, but no x can make it 0.

Intuition:
- Expanding the XOR expression:
  (a1 ^ x) ^ (a2 ^ x) ^ ... ^ (an ^ x) = (a1 ^ a2 ^ ... ^ an) ^ (x ^ x ^ ... ^ x [n times]).
- Let S = a1 ^ a2 ^ ... ^ an.
- If n is odd:
  x ^ x ^ ... ^ x (n times) = x.
  Therefore: S ^ x = 0 => x = S.
  Thus, x = S always satisfies the condition!
- If n is even:
  x ^ x ^ ... ^ x (n times) = 0.
  Therefore: S ^ 0 = S.
  The total XOR is always S regardless of what x we choose!
  - If S == 0: any x works, so we can output 0.
  - If S != 0: it is impossible to make it 0 -> output -1.

Time Complexity: O(n) per testcase (single pass to compute total XOR)
Auxiliary Space Complexity: O(1) (computed on the fly without storing an array)
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
        int n;
        cin >> n;

        int total_xor = 0;
        for (int i = 0; i < n; i++) {
            int a_i;
            cin >> a_i;
            total_xor ^= a_i;
        }

        // If n is odd, x = total_xor always works
        if (n % 2 == 1) {
            cout << total_xor << "\n";
        } 
        // If n is even, x's cancel out; works only if total_xor is already 0
        else {
            if (total_xor == 0) {
                cout << 0 << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}