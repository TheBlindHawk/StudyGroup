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

int main() {
    long long  N;
    cin >> N;
    long long root = 1, cube = 1;

    while( root * root * root <= N ) {
        if(isPalindrome(root * root * root)) {
            cube = root * root * root;
        }
        root++;
    }

    cout << cube << endl;

    return 0;
}