/*
There is a road, which can be represented as a number line. You are located in the point 0 of the number line, and you want to travel from the point 0
to the point x, and back to the point 0.

You travel by car, which spends 1 liter of gasoline per 1 unit of distance travelled. When you start at the point 0,
your car is fully fueled (its gas tank contains the maximum possible amount of fuel).

There are n gas stations, located in points a1,a2,…,an.
When you arrive at a gas station, you fully refuel your car. Note that you can refuel only at gas stations, and there are no gas stations in points 0
and x.

You have to calculate the minimum possible volume of the gas tank in your car (in liters) that will allow you to travel from the point 0
to the point x and back to the point 0.

Input
The first line contains one integer t (1<=t<=1000) — the number of test cases.

Each test case consists of two lines:
 -> the first line contains two integers n and x (1<=n<=50; 2<=x<=100);
 -> the second line contains n integers a1,a2,...,an (0<a1<a2<...<an<x).

Output
For each test case, print one integer — the minimum possible volume of the gas tank in your car that will allow you to travel from the point 0
to the point x and back.

Example
Input:
3
3 7
1 2 5
3 6
1 2 5
1 10
7

Output:
4
3
7

Time Complexity: O(n) per testcase
Auxiliary Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // 1. Gap from starting point 0 to the first gas station
        int req = arr[0];

        // 2. Maximum gap between any two adjacent gas stations on the road
        for (int i = 1; i < n; i++) {
            req = max(req, arr[i] - arr[i - 1]);
        }

        // 3. From last station to point x and back to the last station (doubled because no station at x)
        req = max(req, 2 * (x - arr[n - 1]));

        cout << req << '\n';
    }
    return 0;
}