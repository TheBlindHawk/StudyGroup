#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    string T;
    cin >> T;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    int patternCount = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] != '.') continue;

            bool isPattern = true;
            int x = j, y = i;

            for (int i = 0; i < T.length(); i++) {
                char c = T[i];
                if (c == 'L') {
                    x--;
                } else if (c == 'R') {
                    x++;
                } else if (c == 'U') {
                    y--;
                } else if (c == 'D') {
                    y++;
                }
                if (y >= 0 && y < H && x >= 0 && x < W) {
                    if (S[y][x] != '.') {
                        isPattern = false;
                        break;
                    }
                } else {
                    isPattern = false;
                    break;
                }
            }

            if (isPattern) {
                patternCount++;
            }
        }
    }

    cout << patternCount << endl;

    return 0;
}
