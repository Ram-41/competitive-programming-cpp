/*
Problem: 1878A - How Much Does Daytona Cost? (Codeforces Rating 800)

We define an integer to be the most common on a subsegment, if its number of occurrences 
on that subsegment is larger than the number of occurrences of any other integer in that subsegment. 
A subsegment of an array is a consecutive segment of elements in the array a.

Given an array a of size n, and an integer k, determine if there exists a non-empty 
subsegment of a where k is the most common element.

Input:
The first line contains t (1 <= t <= 1000) — number of test cases.
Each test case consists of:
1. Two integers n and k (1 <= n <= 100, 1 <= k <= 100).
2. n integers a1, a2, ..., an (1 <= ai <= 100).

Output:
For each test case, output "YES" if such a subsegment exists, and "NO" otherwise.

Example:
Input:
7
5 4
1 4 3 4 1
4 1
2 3 4 4
5 6
43 5 60 4 2
2 5
1 5
4 1
5 3 3 1
1 3
3
5 3
3 4 1 5 5

Output:
YES
NO
NO
YES
YES
YES
YES

Intuition:
- A subsegment can consist of just a single element: [k].
- In the subsegment [k], the count of k is 1, and the count of any other element is 0.
- Since 1 > 0, k is strictly the most common element in this single-element subsegment!
- Therefore, if k appears at least once anywhere in the array, the answer is ALWAYS "YES".
- If k never appears in the array, its count can never exceed 0 -> "NO".

Time Complexity: O(n) per testcase (single pass to check if k exists)
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
        int n, k;
        cin >> n >> k;

        bool k_found = false;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            if (val == k) {
                k_found = true;
            }
        }

        if (k_found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}