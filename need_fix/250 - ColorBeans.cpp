#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <map>

int main() {
    int N;
    cin >> N;
    
    map<int, int> Deliciousness;

    for (int i = 0; i < N; i++) {
        int A, C;
        cin >> A >> C;
        
        if (A > Deliciousness[C]) {
            Deliciousness[C] = A;
        }
    }

    int minimum = 1000000000;

    for (auto it = Deliciousness.begin(); it != Deliciousness.end(); it++) {
        if (it->second < minimum) { minimum = it->second; }
    }

    cout << minimum << endl;
    
    return 0;
}
