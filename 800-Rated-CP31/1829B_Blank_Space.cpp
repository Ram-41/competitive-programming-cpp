/*
Problem: 1829B - Blank Space (Codeforces Rating 800)

You are given a binary array a of n elements (consisting only of 0s and 1s).
A blank space is a segment of consecutive elements consisting only of 0s.
Find the length of the longest blank space.

Input:
The first line contains a single integer t (1 <= t <= 1000) — number of test cases.
Each testcase consists of:
1. An integer n (1 <= n <= 100) — length of the array.
2. n space-separated integers a1, a2, ..., an (0 <= ai <= 1).

Output:
For each test case, output a single integer — length of the longest blank space.

Example:
Input:
5
5
1 0 0 1 0
4
0 1 1 1
1
0
3
1 1 1
9
1 0 0 0 1 0 0 0 1

Output:
2
1
1
0
3

Intuition:
- We track the current streak of consecutive zeroes using a running counter.
- As we iterate through the array:
  - If the element is 0: increment current_zeros, and update max_zeros.
  - If the element is 1: the streak of zeroes is broken, so reset current_zeros = 0.
- Since we only care about the maximum length, this can be computed on the fly in a 
  single pass with O(1) extra space.

Time Complexity: O(n) per testcase
Auxiliary Space Complexity: O(1) (evaluated on the fly without storing the array)
*/

#include <iostream>
#include <algorithm>

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

        int current_zeros = 0;
        int max_zeros = 0;

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;

            if (val == 0) {
                current_zeros++;
                max_zeros = max(max_zeros, current_zeros);
            } else {
                current_zeros = 0;
            }
        }

        cout << max_zeros << "\n";
    }
    return 0;
}