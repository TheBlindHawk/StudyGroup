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

        if(diam <= A) {
            if (diam * diam >= B) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            long long bonus = diam - A / 2;
            if(diam * A + bonus * diam / 2 + bonus / 2 >= B) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
