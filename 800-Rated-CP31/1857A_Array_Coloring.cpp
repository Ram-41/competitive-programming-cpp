/*
Problem: 1857A - Array Coloring (Codeforces Rating 800)

You are given an array consisting of n integers. Your task is to determine whether it is 
possible to color all its elements in two colors in such a way that the sums of the elements 
of both colors have the same parity and each color has at least one element colored.

For example, if the array is [1,2,4,3,2,3,5,4], we can color it as follows: [1,2,4,3,2,3,5,4], 
where the sum of the blue elements is 6 and the sum of the red elements is 18.

Input:
The first line contains an integer t (1 <= t <= 1000) — the number of test cases.
Each test case begins with a line containing an integer n (2 <= n <= 50) — the length of the array a.
The next line contains n integers a1, a2, ..., an (1 <= ai <= 50) — the elements of the array a.

Output:
For each test case, output "YES" if it is possible to color the array such that both color sums 
have the same parity, and "NO" otherwise.

Example:
Input:
7
8
1 2 4 3 2 3 5 4
2
4 7
3
3 9 8
2
1 7
5
5 4 3 2 1
4
4 3 4 5
2
50 48

Output:
YES
NO
YES
YES
NO
YES
YES

Note:
The first sample is described in the statement.
In the second sample, there are only two colorings [4,7] and [4,7], but in both cases the parity of sums is different.
In the third sample, you can color [3,9,8] and 12 and 8 are both even.

Intuition:
- Let S1 be the sum of color 1 and S2 be the sum of color 2.
- Both sums must have the same parity:
  - If both are even: S1 + S2 = Even + Even = Even
  - If both are odd:  S1 + S2 = Odd + Odd   = Even
- Therefore, the total sum of the entire array MUST be even!
- Even numbers do not affect the total parity. Only odd numbers change parity.
- Thus, the total sum is even if and only if the count of odd numbers is even:
  - count_of_odd % 2 == 0 -> "YES"
  - count_of_odd % 2 == 1 -> "NO"

Time Complexity: O(n) per testcase (single pass to count odd elements)
Auxiliary Space Complexity: O(1) (counted on the fly without storing an array)
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

        int odd_count = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 2 != 0) {
                odd_count++;
            }
        }

        // Parity is preserved if and only if the number of odd elements is even
        if (odd_count % 2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}