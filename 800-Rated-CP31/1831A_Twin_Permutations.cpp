/*
Problem: 1831A - Twin Permutations (Codeforces Rating 800)

You are given a permutation a of length n.
Find any permutation b of length n such that:
a1 + b1 <= a2 + b2 <= a3 + b3 <= ... <= an + bn.

A permutation of length n contains all integers from 1 to n in arbitrary order.

Input:
The first line contains t (1 <= t <= 2000) — number of test cases.
Each test case consists of:
1. An integer n (1 <= n <= 100) — length of permutations a and b.
2. n distinct integers a1, a2, ..., an (1 <= ai <= n).

Output:
For each test case, output any valid permutation b.

Example:
Input:
5
5
1 2 4 5 3
2
1 2
1
1
3
3 2 1
4
1 4 3 2

Output:
5 4 2 1 3
2 1
1
1 2 3
4 1 2 3

Note:
For a = [1, 2, 4, 5, 3], if b = [5, 4, 2, 1, 3], then:
1+5 = 6 <= 2+4 = 6 <= 4+2 = 6 <= 5+1 = 6 <= 3+3 = 6.
All sums are equal, so the condition holds!

Intuition:
- The inequality a1 + b1 <= a2 + b2 <= ... <= an + bn is trivially satisfied 
  if every sum is identically equal to a constant:
  a_i + b_i = C for all i.
- Since elements are from 1 to n, the minimum element is 1 and the maximum is n.
- We can pair each element with its complement:
  b_i = (n + 1) - a_i.
- Then:
  a_i + b_i = a_i + (n + 1 - a_i) = n + 1 for every single index i!
- Since a is a permutation of 1 to n, b is also guaranteed to be a valid permutation of 1 to n.

Time Complexity: O(n) per testcase
Auxiliary Space Complexity: O(1) (printed on the fly without storing an array)
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

        for (int i = 0; i < n; i++) {
            int a_i;
            cin >> a_i;
            // Every sum becomes identically equal to n + 1
            cout << (n + 1 - a_i) << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}