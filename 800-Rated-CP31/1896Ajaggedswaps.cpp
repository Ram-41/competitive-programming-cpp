/*
You are given a permutation a of size n. You can do the following operation:
Select an index i from 2 to n-1 such that a_{i-1} < a_i and a_i > a_{i+1}. 
Swap a_i and a_{i+1}.

Determine whether it is possible to sort the permutation after a finite number of operations.

A permutation is an array consisting of n distinct integers from 1 to n in arbitrary order.

Input:
The first line contains t (1 <= t <= 5000) — the number of test cases.
Each test case consists of two lines:
1. An integer n (3 <= n <= 10) — size of the permutation.
2. n integers a1, a2, ..., an (1 <= a_i <= n) — elements of the permutation.

Output:
For each test case, print "YES" if it is possible to sort the permutation, and "NO" otherwise.

Example:
Input:
6
3
1 2 3
5
1 3 2 5 4
5
5 4 3 2 1
3
3 1 2
4
2 3 1 4
5
5 1 2 3 4

Output:
YES
YES
NO
NO
NO
NO

Intuition:
- The operation allows swapping a_i and a_{i+1} only for indices i from 2 to n-1.
- This means the very first element a[0] (in 0-based indexing) can NEVER be moved or swapped!
- A sorted permutation of 1 to n MUST start with 1.
- Therefore, if a[0] != 1, 1 can never reach the front, making it impossible -> "NO".
- If a[0] == 1, it acts as a permanent anchor smaller than all other elements, 
  allowing us to bubble-swap the remaining elements into sorted order -> "YES".

Time Complexity: O(n) per testcase (reading the array of size n <= 10)
Auxiliary Space Complexity: O(1)
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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // The first element can never move. If it's not 1, we can never sort it.
        if (a[0] == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}