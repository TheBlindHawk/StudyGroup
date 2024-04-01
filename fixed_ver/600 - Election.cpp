#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, result;
    string V;
    cin >> N >> V;

    int countA = 0;
    int countB = 0;
    string A1;

    for (char c : V) {
        if (c == 'A') { countA++; }
        else { countB++; }
        
        if (countA > countB) {
            A1 += 'A';
        } else if (countB > countA) {
            A1 += 'B';
        } else {
            A1 += 'C';
        }
    }

    V = V.substr(1);

    countA = 0;
    countB = 0;
    string A2;

    for (char c : V) {
        if (c == 'A') { countA++; }
        else { countB++; }
        
        if (countA > countB) {
            A2 += 'A';
        } else if (countB > countA) {
            A2 += 'B';
        } else {
            A2 += 'C';
        }
    }
    A2 += 'N';

    int diffCount = 0;
    for (int i = 0; i < N; i++) {
        if (A1[i] != A2[i]) {
            diffCount++;
        }
    }
    
    cout << diffCount << endl;
    
    return 0;
}