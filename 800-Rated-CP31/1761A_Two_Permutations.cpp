/*
Problem: 1761A - Two Permutations (Codeforces Rating 800)

Given integers n, a, and b. Determine if there exist two permutations p and q 
of length n such that:
1. The length of the longest common prefix of p and q is a.
2. The length of the longest common suffix of p and q is b.

Input:
The first line contains t (1 <= t <= 10^4) — number of test cases.
Each test case contains three integers n, a, and b (1 <= a, b <= n <= 100).

Output:
For each test case, output "Yes" if such permutations exist, and "No" otherwise.

Example:
Input:
4
1 1 1
2 1 2
3 1 1
4 1 1

Output:
Yes
No
No
Yes

Note:
- Test 1 (1 1 1): [1] and [1] -> Yes.
- Test 2 (2 1 2): a + b = 3 > n, impossible -> No.
- Test 3 (3 1 1): a + b = 2 = n - 1. Only 1 middle element left, forcing it to match -> No.
- Test 4 (4 1 1): [1, 2, 3, 4] and [1, 3, 2, 4] -> Yes.

Intuition:
- Case 1: a == n and b == n
  Both permutations are completely identical. LCP = n, LCS = n -> "Yes".
- Case 2: a + b >= n (when not a = b = n)
  Prefix and suffix overlap or cover the whole array, forcing all elements to match -> "No".
- Case 3: a + b == n - 1
  There is exactly 1 unassigned element in the middle. Since permutations contain 
  the same multiset {1..n}, that single leftover number must be identical in both p and q, 
  unintentionally extending the prefix/suffix -> "No".
- Case 4: a + b <= n - 2 (a + b + 2 <= n)
  There are at least 2 unassigned elements in the middle. We can place [x, y] in p 
  and [y, x] in q. Since x != y, they mismatch, strictly stopping the prefix at a 
  and suffix at b -> "Yes".

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
        long long n, a, b;
        cin >> n >> a >> b;

        // Either both are identical (a == b == n) or at least 2 elements separate the prefix and suffix
        if ((a == b && a == n) || (a + b + 2 <= n)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}