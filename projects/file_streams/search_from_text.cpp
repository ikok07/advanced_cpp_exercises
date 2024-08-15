//
// Created by kok on 15.08.24.
//

#include <iomanip>
#include <iostream>
#include <memory>
#include <fstream>

using namespace std;

int search_from_text() {

    string target_word;
    cout << "Enter a word to search: " << endl;
    cin >> target_word;

    ifstream file{"../romeoandjuliet.txt"};
    if (!file) throw runtime_error("Failed to open file!");

    int words_count{};
    int target_word_count{};
    string curr_word;
    char curr_char;
    while (!file.eof()) {
        curr_char = file.get();
        if (curr_char == ' ' || curr_char == '\n' || curr_char == '\t' || curr_char == '\r') {
            if (curr_word.empty()) continue;
            words_count++;
            if (curr_word.find(target_word) != string::npos) target_word_count++;
            curr_word = "";
            continue;
        }
        curr_word.push_back(curr_char);
    }

    cout << words_count << " words were searched..." << endl;
    cout << "The substring " << target_word << " was found " << target_word_count << " times" << endl;
    return 0;
}


