/*
Vanya and Vova are playing a game. Players are given an integer n. 
On their turn, the player can add 1 to the current integer or subtract 1.
The players take turns; Vanya starts. If after Vanya's move the integer is divisible by 3, then he wins. 
If 10 moves have passed and Vanya has not won, then Vova wins.

Write a program that, based on the integer n, determines who will win if both players play optimally.

Input:
The first line contains the integer t (1 <= t <= 100) — number of test cases.
The single line of each test case contains the integer n (1 <= n <= 1000).

Output:
Print "First" if Vanya wins, and "Second" if Vova wins.

Example:
Input:
6
1
3
5
100
999
1000

Output:
First
Second
First
First
Second
First

Intuition:
- Any number n mod 3 is either 0, 1, or 2.
- If n % 3 == 1: Vanya subtracts 1 on move 1 to make it divisible by 3 -> Vanya (First) wins immediately.
- If n % 3 == 2: Vanya adds 1 on move 1 to make it divisible by 3 -> Vanya (First) wins immediately.
- If n % 3 == 0: Any move Vanya makes makes it not divisible by 3. Vova will always undo Vanya's move, 
  preventing Vanya from ever landing on a multiple of 3 on his turn -> Vova (Second) wins.

Time Complexity: O(1) per testcase
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
        int n;
        cin >> n;

        // If n is not already divisible by 3, Vanya can reach a multiple of 3 in 1 step
        if ((n + 1) % 3 == 0 || (n - 1) % 3 == 0) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
    }
    return 0;
}