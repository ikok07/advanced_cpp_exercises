//
// Created by kok on 06.08.24.
//

#include <iostream>
#include <cmath>

using namespace std;

void pyramide() {
    string str;
    cin >> str;

    size_t width = str.length() + str.length() - 1;
    size_t height = str.length();

    int curr_w = 1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < (width - curr_w) / 2; j++) {
            cout << ' ';
        }
        for (int k = 0; k < ceil(curr_w / 2) + 1; k++) {
            cout << str[k];
        }
        for (int k = curr_w / 2 - 1; k >= 0; k--) {
            cout << str[k];
        }
        for (int j = 0; j < (width - curr_w) / 2; j++) {
            cout << ' ';
        }
        cout << endl;
        curr_w += 2;
    }
}