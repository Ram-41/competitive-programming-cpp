/*
Problem: 1866A - Ambitious Kid (Codeforces Rating 800)

Given an array of integers [A1, A2, ..., AN]. In one operation, you can increase 
or decrease any element by 1.
Find the minimum number of operations to make the product A1 * A2 * ... * AN = 0.

Input:
The first line contains N (1 <= N <= 10^5) — the number of elements.
The second line contains N integers A1, A2, ..., AN (-10^5 <= Ai <= 10^5).

Output:
An integer representing the minimum operations needed.

Example:
Input:
3
2 -6 5
Output:
2

Input:
1
-3
Output:
3

Input:
5
0 -1 0 1 0
Output:
0

Intuition:
- A product of numbers equals 0 if and only if at least one number is 0.
- The cost to turn any number A_i into 0 using +/- 1 operations is its absolute value |A_i|.
- To minimize the cost, we greedily pick the single number that is already closest to 0.
- If 0 is already present in the array, |0| = 0 operations are required.
- Thus, the answer is simply the minimum of |A_i| across the entire array.

Time Complexity: O(N) (single pass through N elements)
Auxiliary Space Complexity: O(1) (computing minimum on the fly without storing an array)
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int min_operations = INT_MAX;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        min_operations = min(min_operations, abs(x));
    }

    cout << min_operations << "\n";

    return 0;
}