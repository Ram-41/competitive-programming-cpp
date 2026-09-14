/*

 * Problem Name : Halloumi Boxes
 * Platform     : Codeforces (Round 912 Div. 2, Problem 1903A)
 * Difficulty   : Rating 800 (CP-31 Sheet #1)
 * 
 * [Core Logic / Intuition]:
 * - If k >= 2: We can reverse subarrays of size 2, which is just swapping two adjacent elements.
 *   Since any array can be sorted by swapping adjacent elements (like in Bubble Sort), 
 *   an answer of "YES" is ALWAYS possible whenever k > 1.
 * 
 * - If k == 1: We can only reverse subarrays of length 1, which changes nothing.
 *   Therefore, the answer is "YES" only if the array is already sorted initially.
 * 
 * Time Complexity : O(N) per testcase (checking if sorted takes linear time)
 * Space Complexity: O(1) auxiliary space (no extra copies of the array created)
 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> boxes(n);
    for (int i = 0; i < n; i++) {
        cin >> boxes[i];
    }
    
    // If k > 1, we can always sort using adjacent swaps.
    // If k == 1, we can only succeed if the array is already in order.
    if (k > 1 || is_sorted(boxes.begin(), boxes.end())) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}