/*
An array b1,b2,…,bn of positive integers is good if all the sums of two adjacent elements are equal to the same value. More formally, the array is good if there exists a k
such that b1+b2=b2+b3=…=bn−1+bn=k

Doremy has an array a of length n.
Now Doremy can permute its elements (change their order) however she wants. Determine if she can make the array good.

Input
The input consists of multiple test cases. The first line contains a single integer t(1≤t≤100) — the number of test cases. 
The description of the test cases follows.

The first line of each test case contains a single integer n(2≤n≤100) — the length of the array a.
The second line of each test case contains n integers a1,a2,…,an(1≤ai≤10^5).
There are no constraints on the sum of n over all test cases.

Output
For each test case, print "Yes" (without quotes), if it is possible to make the array good, and "No" (without quotes) otherwise.
You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
Input
5
2
8 9
3
1 1 2
4
1 1 4 5
5
2 3 3 3 3
4
100000 100000 100000 100000

Output
Yes
Yes
No
No
Yes

Intuition:
- Since b_1 + b_2 = b_2 + b_3 => b_1 = b_3, and b_2 + b_3 = b_3 + b_4 => b_2 = b_4,
  a good array must strictly alternate between at most two numbers: x, y, x, y, x...
- Therefore:
  1. If there are 3 or more distinct elements, it is impossible -> "No".
  2. If there are 1 or 2 distinct elements, their counts can differ by at most 1 
     (|freq_1 - freq_2| <= 1) to form an alternating pattern -> "Yes".

Time Complexity: O(n log(distinct elements)) = O(n) per testcase
Auxiliary Space Complexity: O(n) to store frequency map and elements

*/

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> frequency_map;
        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
            frequency_map[a[i]]++;
        }
        // If there are 3 or more distinct numbers, we can never alternate
        if (frequency_map.size() >= 3) 
        {
            cout << "No\n";
        } 
        else 
        {
            int freq_1 = frequency_map.begin()->second;
            int freq_2 = frequency_map.rbegin()->second;
            // Frequencies must be equal (for even n) or differ by at most 1 (for odd n)
            if (abs(freq_1 - freq_2) <= 1) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
    return 0;
}