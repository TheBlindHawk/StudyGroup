#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(long long   num) {
    long long reversedNum = 0;
    long long temp = num;
    while (temp > 0) {
        reversedNum = reversedNum * 10 + temp % 10;
        temp /= 10;
    }
    return num == reversedNum;
}

bool isPerfectCube(long long num) {
    long long h = num & 0xF;
    if (!(h == 0 || h == 1 || h == 4 || h == 9)) return false;
    long long cubeRoot = cbrt(num);
    return cubeRoot * cubeRoot * cubeRoot == num;
}

int main() {
    long long  N;
    cin >> N;

    for (long long i = N; i >= 1; i--) {
        if (isPalindrome(i) && isPerfectCube(i)) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}