/*
Problem: 1837A - Grasshopper on a Line (Codeforces Rating 800)

You are given two integers x and k. Grasshopper starts at point 0 on the OX axis. 
In one move, it can jump an integer distance that is NOT divisible by k (to the left or right).
Find the minimum number of moves to reach point x, and print any valid sequence of moves.

Input:
The first line contains a single integer t (1 <= t <= 1000) — number of testcases.
The only line of each testcase contains two integers x and k (1 <= x <= 100; 2 <= k <= 100).

Output:
For each testcase:
- Line 1: An integer n — the minimum number of moves.
- Line 2: n integers — the jump sequence (each not divisible by k) summing to x.

Example:
Input:
3
10 2
10 3
3 4

Output:
2
1 9
1
10
1
3

Intuition:
- If x is not divisible by k (x % k != 0):
  We can reach x in exactly 1 move of length x.
- If x is divisible by k (x % k == 0):
  We cannot do it in 1 move. We can always split x into two moves: 1 and (x - 1).
  1. Since k >= 2, 1 % k == 1 != 0 (1 is never divisible by k).
  2. Since x % k == 0, (x - 1) % k == k - 1 != 0 (x - 1 is never divisible by k).
  3. 1 + (x - 1) = x.
  Thus, 2 moves are always sufficient and optimal.

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
        long long x, k;
        cin >> x >> k;

        // If x is not divisible by k, 1 move is enough
        if (x % k != 0) {
            cout << 1 << "\n";
            cout << x << "\n";
        } 
        // If x is divisible by k, split into 1 and (x - 1)
        else {
            cout << 2 << "\n";
            cout << 1 << " " << x - 1 << "\n";
        }
    }
    return 0;
}