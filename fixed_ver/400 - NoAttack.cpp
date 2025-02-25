#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long int N, A, B;
        cin >> N >> A >> B;

        long long int diam = N-A;

        if(diam < 0) {
            cout << "No" << endl;
            continue;
        }

        if(diam - 1 <= A) {
            if (diam * diam >= B) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            long long int leftover = N - A * 2;
            if(A * diam + (leftover+1)/2 * diam >= B) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
