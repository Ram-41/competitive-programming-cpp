/*
Problem: 1873C - Target Practice (Codeforces Rating 800)

A 10x10 target is made out of five concentric "rings". 
Each ring has a different point value:
- Outermost ring: 1 point
- Second ring: 2 points
- Third ring: 3 points
- Fourth ring: 4 points
- Center ring: 5 points

Given a 10x10 grid with 'X' representing an arrow and '.' representing no arrow,
calculate the total score of all arrows.

Input:
The first line contains t (1 <= t <= 1000) — number of test cases.
Each test case consists of 10 lines, each containing 10 characters ('X' or '.').

Output:
For each test case, output a single integer — the total score.

Example
Input
4
X.........
..........
.......X..
.....X....
......X...
..........
.........X
..X.......
..........
.........X
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
..........
....X.....
..........
..........
..........
..........
..........
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX
XXXXXXXXXX

Output
17
0
5
220

Intuition:
- A cell at 0-based coordinates (i, j) in a 10x10 grid is at a certain distance from the 4 borders:
  1. Distance from top border: i + 1
  2. Distance from bottom border: 10 - i
  3. Distance from left border: j + 1
  4. Distance from right border: 10 - j
- The ring value is determined by the minimum distance to any of the 4 borders:
  score = min({i + 1, 10 - i, j + 1, 10 - j})
- For example, cell (0, 0) gives min(1, 10, 1, 10) = 1 (outermost ring).
  Cell (4, 4) gives min(5, 6, 5, 6) = 5 (bullseye center).

Time Complexity: O(1) per testcase (fixed 10x10 = 100 cells evaluated)
Auxiliary Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long total_score = 0;

        for (int i = 0; i < 10; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < 10; j++) {
                if (row[j] == 'X') {
                    // Distance to the closest of the 4 borders defines the ring value
                    int score = min({i + 1, 10 - i, j + 1, 10 - j});
                    total_score += score;
                }
            }
        }

        // Print once after the entire 10x10 target is scored
        cout << total_score << "\n";
    }
    return 0;
}