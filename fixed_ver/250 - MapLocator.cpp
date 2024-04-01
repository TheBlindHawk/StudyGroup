#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    string T;
    cin >> T;
    string S[H];
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    pair<int, int> locations[T.length()];
    int x = 0, y = 0;
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
        locations[i] = make_pair(x, y);
    }

    // Remove duplicates from locations
    sort(locations, locations + T.size());
    auto last = unique(locations, locations + T.size());
    T.resize(distance(locations, last));

    int patternCount = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] != '.') continue;
            bool isPattern = true;
            for (const pair<int, int>& loc: locations) {
                int dx = loc.first + j;
                int dy = loc.second + i;
                if (dy >= 0 && dy < H && dx >= 0 && dx < W) {
                    if (S[dy][dx] != '.') {
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
