/*
Filip has a row of cells, some of which are blocked, and some are empty. He wants all empty cells to have water in them. 
He has two actions at his disposal:
1. Place water in an empty cell.
2. Remove water from a cell and place it in any other empty cell.

If at some moment cell i (2 <= i <= n-1) is empty and both cells i-1 and i+1 contain water, then it becomes filled with water.
Find the minimum number of times he needs to perform action 1 in order to fill all empty cells with water.

Input:
t (1 <= t <= 100) — number of test cases.
Each testcase has n (1 <= n <= 100) and a string s containing '.' (empty) and '#' (blocked).

Output:
Minimal amount of action 1 needed.

Example:
Input:
5
3
...
7
##....#
7
..#.#..
4
####
10
#...#..#.#

Output:
2
2
5
0
2

Intuition:
- If there are 3 consecutive empty cells ("..."), we can place water in the left and right cells (cost = 2). 
  The middle cell fills automatically, giving us an infinite water generator using action 2. 
  Thus, cost is ALWAYS 2.
- Otherwise (no 3 consecutive dots exist), no cell can ever be filled automatically, 
  so we must manually fill every empty cell with action 1 (cost = total count of '.').

Time Complexity: O(n) per testcase (single linear scan through string)
Auxiliary Space Complexity: O(1)
*/

#include <iostream>
#include <string>

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
        string s;
        cin >> s;

        // Check if 3 consecutive empty cells exist
        if (s.find("...") != string::npos) {
            cout << 2 << "\n";
        } else {
            // Count total individual empty cells
            int total_empty_cells = 0;
            for (char c : s) {
                if (c == '.') {
                    total_empty_cells++;
                }
            }
            cout << total_empty_cells << "\n";
        }
    }
    return 0;
}