#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <map>

int countSimilarPairs(vector<vector<int>>& sequences) {
    int n = sequences.size();
    int m = sequences[0].size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int similarCount = 0;
            for (int k = 0; k < m; k++) {
                if (sequences[i][k] == sequences[j][k]) {
                    similarCount++;
                }
            }
            if (similarCount % 2 == 1) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> sequences(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> sequences[i][j];
        }
    }

    int answer = countSimilarPairs(sequences);
    cout << answer << endl;

    return 0;
}
