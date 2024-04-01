#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, result;
    string V, vv;
    vector<string> SS;
    cin >> N >> V;
    vv = V[0];
    V = V.substr(1);

    for (int i = 0; i < N; i++) {
        string CV = V;
        CV.insert(i, vv);

        int countA = 0;
        int countB = 0;
        string S;

        for (char c : CV) {
            if (c == 'A') { countA++; }
            else { countB++; }

            if (countA > countB) {
                S += 'A';
            } else if (countA < countB) {
                S += 'B';
            } else {
                S += 'C';
            }
        }

        // cout << S << endl;

        SS.push_back(S);
    }

    sort( SS.begin(), SS.end() );
    SS.erase( unique( SS.begin(), SS.end() ), SS.end() );
    int count = SS.size();
    
    cout << count << endl;
    
    return 0;
}