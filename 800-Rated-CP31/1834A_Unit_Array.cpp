/*
Problem: 1834A - Unit Array (Codeforces Rating 800)
Link: https://codeforces.com/problemset/problem/1834/A

Given an array a of length n, whose elements are only -1 and 1. 
An array is good if:
1. a1 + a2 + ... + an >= 0
2. a1 * a2 * ... * an = 1

In one operation, you can change any element to its opposite (-1 -> 1 or 1 -> -1).
Determine the minimum operations needed to make the array good.

Input:
The first line contains t (1 <= t <= 500) — number of test cases.
Each testcase consists of:
1. An integer n (1 <= n <= 100) — length of array.
2. n integers a1, a2, ..., an (ai = +/- 1).

Output:
For each test case, output a single integer — the minimum operations needed.

Example:
Input:
7
4
-1 -1 1 -1
5
-1 -1 -1 1 1
4
-1 1 -1 1
3
-1 -1 -1
5
1 1 1 1 1
1
-1
2
-1 -1

Output:
1
1
0
3
0
1
2

Note:
In the first test case, change a1 := 1. Sum = 1 + (-1) + 1 + (-1) = 0 >= 0, product = 1. (1 op).
In the second test case, change a1 := 1. Sum = 1 >= 0, product = 1. (1 op).
In the third test case, already good (0 ops).

Intuition:
- Condition 1 (Sum >= 0): Requires count(+1) >= count(-1).
- Condition 2 (Product == 1): Requires count(-1) to be an EVEN number.
- To minimize operations, we should only ever change -1 to 1 (changing 1 to -1 would only 
  decrease the sum and waste moves).
- We can greedily flip one -1 to +1 at a time (incrementing positive_count and decrementing 
  negative_count) until both conditions are simultaneously satisfied:
  positive_count >= negative_count AND negative_count % 2 == 0.

Time Complexity: O(n) per testcase (reading input + at most n greedy flips)
Auxiliary Space Complexity: O(1) (counted on the fly without storing an array)
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

        int positive_count = 0;
        int negative_count = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 1) {
                positive_count++;
            } else {
                negative_count++;
            }
        }

        int operations = 0;
        // Greedily flip -1 to +1 until sum >= 0 and product == 1
        while (positive_count < negative_count || negative_count % 2 != 0) {
            operations++;
            positive_count++;
            negative_count--;
        }

        cout << operations << "\n";
    }
    return 0;
}