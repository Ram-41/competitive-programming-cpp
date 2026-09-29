/*
Problem: 1877A - Goals of Victory (Codeforces Rating 800)

There are n teams in a football tournament. Each pair of teams match up once. 
The efficiency of a team is equal to total goals scored minus total goals conceded.
Given the efficiency of n-1 teams, find the efficiency of the missing team.

Input:
The first line contains t (1 <= t <= 500) — number of test cases.
Each test case consists of:
1. An integer n (2 <= n <= 100) — number of teams.
2. n-1 integers a1, a2, ..., an-1 (-100 <= ai <= 100) — efficiency of n-1 teams.

Output:
For each test case, output an integer representing the efficiency of the missing team.

Example:
Input:
2
4
3 -4 5
11
-30 12 -57 7 0 -81 -68 41 -89 0

Output:
-4
265

Intuition:
- In any individual match between Team A and Team B:
  (Goals A - Goals B) + (Goals B - Goals A) = 0.
- Every goal scored by one team is conceded by another, meaning total tournament 
  efficiency is a zero-sum game: sum(a_1 to a_n) = 0.
- Therefore, the missing team's efficiency is simply the negation of the sum of the 
  other n-1 teams: a_n = -sum(a_1 to a_n-1).

Time Complexity: O(n) per testcase (reading the n-1 numbers)
Auxiliary Space Complexity: O(1) (computing running sum on the fly)
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

        long long sum = 0;
        for (int i = 0; i < n - 1; i++) {
            int x;
            cin >> x;
            sum += x;
        }

        long long ans = -sum;
        cout << ans << "\n";
    }
    return 0;
}