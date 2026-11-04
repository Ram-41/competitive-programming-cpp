/*
Problem: 1777A - Everybody Likes Good Arrays! (Codeforces Rating 800)

An array a is good if for all adjacent elements, a_i and a_{i+1} have different parity.
In one operation, you can select any pair of adjacent elements with the SAME parity, 
delete them, and insert their product in their position.
Find the minimum number of operations to form a good array.

Input:
The first line contains t (1 <= t <= 500) — number of test cases.
Each test case consists of:
1. An integer n (1 <= n <= 100) — size of array.
2. n integers a1, a2, ..., an (1 <= ai <= 10^9).

Output:
For each test case, print the minimum operations required.

Example:
Input:
3
5
1 7 11 2 13
4
1 2 3 4
6
1 1 1 2 2 3

Output:
2
0
3

Note:
In test 1: [1, 7, 11, 2, 13] -> combine 7 and 11 (odd*odd = 77) -> [1, 77, 2, 13] 
-> combine 1 and 77 (odd*odd = 77) -> [77, 2, 13] (good in 2 ops).
In test 2: Already alternating in parity -> 0 ops.

Intuition:
- Multiplying two numbers of the same parity preserves their parity:
  Odd * Odd = Odd
  Even * Even = Even
- Therefore, each contiguous block of k elements of the same parity must be merged 
  into a single element, which takes exactly (k - 1) operations.
- This is equivalent to counting every adjacent pair (a[i], a[i+1]) that has the 
  same parity: a[i] % 2 == a[i+1] % 2.

Time Complexity: O(n) per testcase
Auxiliary Space Complexity: O(1) (evaluated on the fly without storing an array)
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

        int prev_val;
        cin >> prev_val;

        int operations = 0;
        for (int i = 1; i < n; i++) {
            int curr_val;
            cin >> curr_val;

            // If adjacent elements share the same parity, 1 operation is required to merge them
            if (prev_val % 2 == curr_val % 2) {
                operations++;
            }
            prev_val = curr_val;
        }

        cout << operations << "\n";
    }
    return 0;
}