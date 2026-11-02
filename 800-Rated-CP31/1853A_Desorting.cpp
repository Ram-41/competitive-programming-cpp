/*
Problem: 1853A - Desorting (Codeforces Rating 800)

Call an array a of length n sorted if a1 <= a2 <= ... <= an.
You can perform the following operation zero or more times:
- Choose an index i (1 <= i <= n-1).
- Add 1 to a1, a2, ..., ai.
- Subtract 1 from ai+1, ai+2, ..., an.

Determine the minimum number of operations needed to make the array NOT sorted.

Input:
The first line contains t (1 <= t <= 100) — number of test cases.
Each test case consists of:
1. An integer n (2 <= n <= 500) — length of array.
2. n integers a1, a2, ..., an (1 <= ai <= 10^9).
Sum of n over all test cases <= 500.

Output:
Output the minimum number of operations needed to make the array not sorted.

Example:
Input:
4
2
1 1
4
1 8 10 13
3
1 3 2
3
1 9 14

Output:
1
2
0
3

Note:
In the first case, pick i=1: [1, 1] becomes [2, 0], which is not sorted (1 op).
In the second case, pick i=3 twice: [1, 8, 10, 13] -> [3, 10, 12, 11] (2 ops).
In the third case, already unsorted (0 ops).

Intuition:
- If the array is already not sorted, 0 operations are required.
- Each operation on index i increases a[i] by 1 and decreases a[i+1] by 1, 
  reducing the gap (a[i+1] - a[i]) by 2 per operation.
- To make a[i] > a[i+1], the gap must be reduced from diff to <= -1:
  diff - 2*k <= -1 => 2*k >= diff + 1 => k = (diff / 2) + 1.
- We greedily pick the adjacent pair with the minimum difference to minimize operations.

Time Complexity: O(n) per testcase
Auxiliary Space Complexity: O(n) to store the array elements
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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

        // If the array is already unsorted, 0 operations needed
        if (!is_sorted(a.begin(), a.end())) {
            cout << 0 << "\n";
            continue;
        }

        // Greedily find the adjacent pair with the smallest gap
        int min_operations = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            int diff = a[i + 1] - a[i];
            int req_ops = (diff / 2) + 1;
            min_operations = min(min_operations, req_ops);
        }

        cout << min_operations << "\n";
    }
    return 0;
}