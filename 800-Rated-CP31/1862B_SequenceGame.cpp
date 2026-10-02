/*
Problem: 1862B - Sequence Game (Codeforces Rating 800)

Vika has a sequence a of length m. She generates sequence b of length n by keeping:
1. The first element a1.
2. Any subsequent element ai (2 <= i <= m) ONLY IF a_{i-1} <= a_i.

Given sequence b, reconstruct any possible original sequence a such that its length m <= 2*n.

Input:
The first line contains t (1 <= t <= 10^4) — number of test cases.
Each test case consists of:
1. An integer n (1 <= n <= 2 * 10^5) — length of sequence b.
2. n integers b1, b2, ..., bn (1 <= bi <= 10^9).
Sum of n over all test cases does not exceed 2 * 10^5.

Output:
For each test case, output two lines:
1. Integer m — length of sequence a (n <= m <= 2*n).
2. m integers — the reconstructed sequence a.

Example:
Input:
6
3
4 6 3
3
1 2 3
5
1 7 9 5 7
1
144
2
1 1
5
1 2 2 1 1

Output:
4
4 6 3 3
3
1 2 3
6
1 7 9 5 5 7
1
144
2
1 1
6
1 2 2 1 1 1

Intuition:
- We can reconstruct sequence a greedily:
  - Always start with a[0] = b[0].
  - For each subsequent element b[i]:
    - If b[i] >= b[i-1]: Simply append b[i], as it naturally satisfies the condition a_{k-1} <= a_k.
    - If b[i] < b[i-1]: Append b[i] TWICE.
      The first b[i] is smaller than b[i-1], so the rule drops it.
      The second b[i] is equal to the first b[i] (b[i] >= b[i]), so the rule keeps it!
- Length of a will never exceed 2*n, which perfectly satisfies m <= 2*n.

Time Complexity: O(n) per testcase, O(sum of n) overall = O(2 * 10^5)
Auxiliary Space Complexity: O(n) to store the reconstructed sequence a
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O is crucial here since sum of n <= 2 * 10^5
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<int> a;
        a.push_back(b[0]);

        for (int i = 1; i < n; i++) {
            if (b[i] >= b[i - 1]) {
                a.push_back(b[i]);
            } else {
                // Sacrificial element: first b[i] is dropped, second b[i] is kept
                a.push_back(b[i]);
                a.push_back(b[i]);
            }
        }

        cout << a.size() << "\n";
        for (int i = 0; i < (int)a.size(); i++) {
            cout << a[i] << (i == (int)a.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}s