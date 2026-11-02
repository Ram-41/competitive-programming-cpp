/*
Problem: 1858A - Buttons (Codeforces Rating 800)
Link: https://codeforces.com/problemset/problem/1858/A

Anna and Katie ended up in a secret laboratory.

There are a+b+c buttons in the laboratory. It turned out that a buttons can only be pressed 
by Anna, b buttons can only be pressed by Katie, and c buttons can be pressed by either of them. 
Anna and Katie decided to play a game, taking turns pressing these buttons. Anna makes the first turn. 
Each button can be pressed at most once, so at some point, one of the girls will not be able to make her turn.

The girl who cannot press a button loses. Determine who will win if both girls play optimally.

Input:
The first line contains a single integer t (1 <= t <= 10^4) — the number of test cases.
Each test case consists of three integers a, b, and c (1 <= a, b, c <= 10^9) — the number of buttons 
that can only be pressed by Anna, the number of buttons that can only be pressed by Katie, and the 
number of buttons that can be pressed by either of them, respectively.

Output:
For each test case, output First if Anna wins, or Second if Katie wins.

Example:
Input:
5
1 1 1
9 3 3
1 2 3
6 6 9
2 2 8

Output:
First
First
Second
First
Second

Note:
For the simplicity of the explanation, we will numerate the buttons by the numbers from 1 to a+b+c: 
the first a buttons can only be pressed by Anna, the next b buttons can only be pressed by Katie, 
and the last c buttons can be pressed by either of them.

In the first test case, Anna can press the 3-rd button on the first turn. Then Katie will press the 
2-nd button (since it is the only possible turn for her). Then Anna will press the 1-st button. 
Katie won't have a button to press, so Anna will win.

In the second test case, Anna can press the first nine buttons in some order on her turns. 
No matter what buttons Katie will press, all the buttons from the 10-th to the 15-th will be 
pressed after 12 turns. On the 13-th turn, Anna will press one of the first nine buttons and 
Katie will not have a button to press on her turn. Thus, Anna will win.

In the third test case, the game can proceed as follows:
On the 1-st turn Anna presses the 5-th button.
On the 2-st turn Katie presses the 4-th button.
On the 3-st turn Anna presses the 6-th button.
On the 4-st turn Katie presses the 3-th button.
On the 5-st turn Anna presses the 1-th button.
On the 6-st turn Katie presses the 2-th button.
Anna cannot make the turn, so Katie wins.
It can be shown that Katie can win no matter what moves Anna takes.

Intuition:
- Both players will greedily press the c shared buttons first to deny moves to the opponent.
- Case 1: c is odd.
  Anna takes (c + 1) / 2 buttons, Katie takes (c - 1) / 2 buttons.
  Anna gets 1 extra move from the shared pool.
  Thus, Katie wins ONLY if she has strictly more exclusive buttons (b > a).
  Otherwise, Anna wins (First).
- Case 2: c is even.
  Both players take c / 2 buttons equally.
  Anna must start pressing her exclusive buttons first.
  Thus, Anna wins ONLY if she has strictly more exclusive buttons (a > b).
  Otherwise, Katie wins (Second).

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
        long long a, b, c;
        cin >> a >> b >> c;

        // If c is odd, Anna gets one more shared button than Katie
        if (c % 2 == 1) {
            if (b > a) {
                cout << "Second\n";
            } else {
                cout << "First\n";
            }
        } 
        // If c is even, both get equal shared buttons
        else {
            if (a > b) {
                cout << "First\n";
            } else {
                cout << "Second\n";
            }
        }
    }
    return 0;
}