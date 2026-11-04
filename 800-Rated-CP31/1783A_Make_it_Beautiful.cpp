/*
Problem: 1783A - Make it Beautiful (Codeforces Rating 800)

An array a is ugly if it contains at least one element equal to the sum of all elements before it.
Otherwise, it is beautiful.
You are given an array a (1 <= a1 <= a2 <= ... <= an <= 100).
Reorder its elements to make it beautiful, or determine if it is impossible.

Input:
The first line contains t (1 <= t <= 2000) — number of test cases.
Each test case consists of:
1. An integer n (2 <= n <= 50) — length of array.
2. n integers a1, a2, ..., an (1 <= ai <= 100).

Output:
For each test case:
- If impossible, output "NO".
- Otherwise, output "YES", followed by any beautiful permutation of the array.

Example:
Input:
4
4
3 3 6 6
2
10 10
5
1 2 3 4 5
3
1 4 4

Output:
YES
6 3 3 6
NO
YES
5 1 2 3 4
YES
4 1 4

Intuition:
- If all elements are equal (a[0] == a[n-1]), then no matter the order, a[1] == a[0], 
  which makes the array ugly. Thus, impossible -> "NO".
- If a[0] != a[n-1], we place the maximum element a[n-1] first, followed by the rest:
  [a[n-1], a[0], a[1], ..., a[n-2]].
  1. For element 2 (a[0]): Sum before it is a[n-1]. Since a[n-1] > a[0], a[0] != a[n-1].
  2. For any element i >= 3: The sum before it is >= a[n-1] + a[0] > a[n-1] >= a[i].
     Since the prefix sum strictly exceeds the maximum element in the array, no element 
     can ever equal the prefix sum!
  Therefore, this greedy construction is ALWAYS beautiful -> "YES".

Time Complexity: O(n log n) per testcase (sorting and printing)
Auxiliary Space Complexity: O(n) to store the array
*/

#include <iostream>
#include <vector>
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        // If all elements are identical, it is impossible to make it beautiful
        if (a[0] == a[n - 1]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            // Print maximum element first, then the remaining elements in non-decreasing order
            cout << a[n - 1] << " ";
            for (int i = 0; i < n - 1; i++) {
                cout << a[i] << (i == n - 2 ? "" : " ");
            }
            cout << "\n";
        }
    }
    return 0;
}