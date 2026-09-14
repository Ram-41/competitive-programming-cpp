/*
Theofanis is busy after his last contest, as now, he has to deliver many halloumis all over the world. He stored them inside n
boxes and each of which has some number ai written on it.

He wants to sort them in non-decreasing order based on their number, however, his machine works in a strange way. It can only reverse any subarray†
of boxes with length at most k.

Find if it's possible to sort the boxes using any number of reverses.

† Reversing a subarray means choosing two indices i and j (where 1 <= i <= j <= n) and changing the array a1,a2,...,an
to a1,a2,...,ai-1,aj,aj-1,...,ai,aj+1,...,an. The length of the subarray is then j - i + 1.

Input:
The first line contains a single integer t (1 <= t <= 100) — the number of test cases.
Each test case consists of two lines.
The first line contains two integers n and k (1 <= k <= n <= 100) — the number of boxes and the length of the maximum reverse that Theofanis can make.
The second line contains n integers a1, a2, ..., an (1 <= ai <= 10^9) — the number written on each box.

Output:
For each test case, print YES (case-insensitive), if the array can be sorted in non-decreasing order, or NO (case-insensitive) otherwise.

Example:
Input:
5
3 2
1 2 3
3 1
9 9 9
4 4
6 4 2 1
4 3
10 3 830 14
2 1
3 1

Output:
YES
YES
YES
YES
NO

Note:
In the first two test cases, the boxes are already sorted in non-decreasing order.
In the third test case, we can reverse the whole array.
In the fourth test case, we can reverse the first two boxes and the last two boxes.
In the fifth test case, it can be shown that it's impossible to sort the boxes.

Time Complexity: O(n) per testcase
Auxiliary Space Complexity: O(1)
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
        long long n, k;
        cin >> n >> k;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // If k > 1, we can reverse any subarray of size 2 (adjacent swap).
        // With adjacent swaps (like Bubble Sort), we can sort any array, so we print "YES".
        // If k == 1, we cannot swap or move anything, so it must already be sorted.
        // Using is_sorted keeps auxiliary space O(1) without creating a duplicate array.
        if (k > 1 || is_sorted(arr.begin(), arr.end())) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}