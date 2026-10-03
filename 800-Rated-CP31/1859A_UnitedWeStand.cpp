/*
Problem: 1859A - United We Stand (Codeforces Rating 800)

Given an array a of length n. You need to divide all its elements into two 
non-empty arrays b and c such that:
For any element b_i in b and c_j in c, c_j is NOT a divisor of b_i.
Output the arrays b and c, or -1 if no such division is possible.

Input:
The first line contains t (1 <= t <= 500) — number of test cases.
Each test case consists of:
1. An integer n (2 <= n <= 100) — length of array a.
2. n integers a1, a2, ..., an (1 <= ai <= 10^9).

Output:
If impossible, output -1.
Otherwise:
Line 1: Lengths of b and c.
Line 2: Elements of b.
Line 3: Elements of c.

Example:
Input:
5
3
2 2 2
5
1 2 3 4 5
3
1 3 5
7
1 7 7 2 9 1 4
5
4 8 12 12 4

Output:
-1
3 2
1 3 5 
2 4 
1 2
1 
3 5 
2 5
1 1 
2 4 7 7 9 
3 2
4 8 4 
12 12 

Intuition:
- A larger positive integer can NEVER divide a strictly smaller positive integer (e.g. 5 cannot divide 3).
- Therefore, we can find the maximum element (maxi) in array a:
  - Place all occurrences of maxi into array c.
  - Place all other elements (< maxi) into array b.
- Since every element in c is strictly greater than every element in b, no element in c 
  can ever divide any element in b!
- If all elements in array a are equal, array b will be empty -> output -1.

Time Complexity: O(n) per testcase (single pass to find max, single pass to distribute)
Auxiliary Space Complexity: O(n) to store arrays b and c
*/

#include <iostream>
#include <vector>
#include <algorithm>

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

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int maxi = *max_element(arr.begin(), arr.end());
        vector<int> b, c;

        for (int i = 0; i < n; i++) {
            if (arr[i] != maxi) {
                b.push_back(arr[i]);
            } else {
                c.push_back(arr[i]);
            }
        }

        // If array b is empty, it means all elements were identical
        if (b.empty()) {
            cout << -1 << "\n";
        } else {
            cout << b.size() << " " << c.size() << "\n";
            for (int i = 0; i < (int)b.size(); i++) {
                cout << b[i] << (i == (int)b.size() - 1 ? "" : " ");
            }
            cout << "\n";
            for (int i = 0; i < (int)c.size(); i++) {
                cout << c[i] << (i == (int)c.size() - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
    return 0;
}