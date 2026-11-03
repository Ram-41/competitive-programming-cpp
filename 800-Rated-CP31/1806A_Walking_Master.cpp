/*
Problem: 1806A - Walking Master (Codeforces Rating 800)

YunQian is on an infinite 2D plane at point (a, b) and wants to reach (c, d).
In one move, she can move:
1. To the top-right diagonal: (x + 1, y + 1)
2. To the left: (x - 1, y)

Find the minimum number of moves to reach (c, d), or output -1 if impossible.

Input:
The first line contains a single integer t (1 <= t <= 10^4) — number of test cases.
Each testcase contains four integers a, b, c, d (-10^8 <= a, b, c, d <= 10^8).

Output:
For each test case, output the minimum moves or -1 if impossible.

Example:
Input:
6
-1 0 -1 2
0 0 4 5
-2 -1 1 1
-3 2 -3 2
2 -1 -1 -1
1 1 0 2

Output:
4
6
-1
0
3
3

Note:
For (-1, 0) to (-1, 2):
(-1, 0) -> (0, 1) -> (-1, 1) -> (0, 2) -> (-1, 2) in 4 moves.

Intuition:
- Move 1 (x+1, y+1) is the ONLY move that changes y, and it strictly increases y.
  Therefore, if destination d < start b, it is impossible -> -1.
- To match the y-coordinate, we must make exactly (d - b) diagonal moves.
- These (d - b) diagonal moves also shift x to:
  new_a = a + (d - b).
- Now y is matched. The only other move is Move 2 (x-1, y), which can ONLY decrease x.
  Therefore, if target c > new_a (target is to the right), it is impossible -> -1.
- Otherwise, we simply walk left from new_a to c:
  left_moves = new_a - c.
- Total moves = (d - b) + (new_a - c) = 2*(d - b) + a - c.

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
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        // Condition 1: y can never decrease
        if (d < b) {
            cout << -1 << "\n";
            continue;
        }

        // Moves needed to match y-coordinate
        long long up_right_moves = d - b;
        long long new_a = a + up_right_moves;

        // Condition 2: from new_a, we can only move left (decrease x)
        if (new_a < c) {
            cout << -1 << "\n";
            continue;
        }

        long long left_moves = new_a - c;
        long long total_moves = up_right_moves + left_moves;

        cout << total_moves << "\n";
    }
    return 0;
}