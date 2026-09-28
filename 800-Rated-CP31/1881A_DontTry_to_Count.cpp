/*
Problem: 1881A - Don't Try to Count (Codeforces Rating 800)

Given a string x of length n and a string s of length m (n * m <= 25), consisting of lowercase Latin letters.
In one operation, you append the current value of x to the end of x (x = x + x).
Find the minimum number of operations after which s appears in x as a contiguous substring. 
If it is impossible, output -1.

Input:
The first line contains t (1 <= t <= 10^4) — number of test cases.
Each test case consists of:
1. Two integers n and m (1 <= n * m <= 25) — lengths of strings x and s.
2. String x of length n.
3. String s of length m.

Output:
Minimum operations to make s a substring of x, or -1 if impossible.

Example:
Input:
12
1 5
a
aaaaa
5 5
eforc
force
2 5
ab
ababa
3 5
aba
ababa
4 3
babb
bbb
5 1
aaaaa
a
4 2
aabb
ba
2 8
bk
kbkbkbkb
12 2
fjdgmujlcont
tf
2 2
aa
aa
3 5
abb
babba
1 19
m
mmmmmmmmmmmmmmmmmmm

Output:
3
1
2
-1
1
0
1
3
1
0
2
5

Intuition:
- In each operation, the length of x doubles: n -> 2n -> 4n -> 8n -> 16n -> 32n.
- Given the constraint n * m <= 25, the worst-case scenario is n = 1, m = 25.
- After 5 operations, |x| becomes at least 32, which is larger than the maximum possible length of s.
- If s does not appear as a substring after 5 operations, further duplications will only repeat 
  already-checked periodic patterns, meaning it is impossible -> output -1.
- Thus, we only need to simulate at most 5 operations.

Time Complexity: O(t * 6 * |x| * |s|) = O(t) per testcase since lengths are bounded <= 32
Auxiliary Space Complexity: O(|x|) to store the duplicated string (max ~64 chars)
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
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;

        string current = x;
        int ans = -1;

        // Simulate at most 5 operations (0 to 5)
        for (int ops = 0; ops <= 5; ops++) {
            if (current.find(s) != string::npos) {
                ans = ops;
                break;
            }
            current += current; // Double the string for the next operation
        }

        cout << ans << "\n";
    }
    return 0;
}