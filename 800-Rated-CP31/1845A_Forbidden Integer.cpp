/*
Problem: 1845A - Forbidden Integer (Codeforces Rating 800)

You are given an integer n. You have an unlimited supply of every integer from 1 to k, 
except integer x (x cannot be used).
Determine if you can make the sum of chosen integers equal to n, and if so, 
output any valid configuration.

Input:
The first line contains a single integer t (1 <= t <= 100) — number of testcases.
The only line of each testcase contains three integers n, k, and x (1 <= x <= k <= n <= 100).

Output:
For each test case:
- Print "YES" or "NO".
- If "YES", print m (number of integers used) on the second line.
- On the third line, print m integers whose sum is n.

Example:
Input:
5
10 3 2
5 2 1
4 2 1
7 7 3
6 1 1

Output:
YES
6
3 1 1 1 1 3
NO
YES
2
2 2
YES
1
7
NO

Note:
In the first testcase, another possible answer is [3, 3, 3, 1] or ten 1s.
In the second testcase, you only have integer 2 available, which cannot sum to 5.
In the fifth testcase, no integers are available at all.

Intuition:
- Case 1: x != 1
  The number 1 is always available (since 1 <= k). We can trivially represent n as 
  the sum of n ones (1 + 1 + ... + 1 = n). Always "YES".
- Case 2: x == 1
  1 is forbidden. We can only use integers >= 2.
  - If k == 1: No integers are available at all -> "NO".
  - If k == 2: Only 2 is available.
    - If n is even: we can use n/2 twos -> "YES".
    - If n is odd: sum of twos is always even, impossible to make odd n -> "NO".
  - If k >= 3: Both 2 and 3 are available.
    - If n is even: use n/2 twos -> "YES".
    - If n is odd: use one 3, leaving (n - 3) which is even. Fill the remaining sum with 
      (n - 3)/2 twos -> "YES".

Time Complexity: O(n) per testcase (to print the sequence of numbers)
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
        long long n, k, x;
        cin >> n >> k >> x;

        // If 1 is allowed, use n ones
        if (x != 1) {
            cout << "YES\n";
            cout << n << "\n";
            for (int i = 0; i < n; i++) {
                cout << 1 << (i == n - 1 ? "" : " ");
            }
            cout << "\n";
        } 
        // 1 is forbidden
        else {
            if (k == 1 || (k == 2 && n % 2 == 1)) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                // If even, use all 2s
                if (n % 2 == 0) {
                    cout << n / 2 << "\n";
                    for (int i = 0; i < n / 2; i++) {
                        cout << 2 << (i == n / 2 - 1 ? "" : " ");
                    }
                    cout << "\n";
                } 
                // If odd, use one 3 and the rest 2s
                else {
                    cout << (n - 3) / 2 + 1 << "\n";
                    for (int i = 0; i < (n - 3) / 2; i++) {
                        cout << 2 << " ";
                    }
                    cout << 3 << "\n";
                }
            }
        }
    }
    return 0;
}