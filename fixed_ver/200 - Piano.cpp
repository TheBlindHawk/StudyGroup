#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string S = "wbwbwwbwbwbw";
    int W, B;
    cin >> W >> B;
    int wl = W/14, bl = B/10;
    int w = W%7, b = B%5;
    w = w < 7 && W/7 >= B/5 ? w + 7 : w;
    b = b < 5 && B/5 >= W/7 ? b + 5 : b;

    if(abs(wl - bl) > 1) {
        cout << "No" << endl;
        return 0;
    }

    int p1 = (b > 3) + (b > 5) + (b > 8) - 1;
    int p2 = (w > 4) + (w > 7) + (w > 11) + 2;

    if (w - b >= p1 && w - b <= p2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}