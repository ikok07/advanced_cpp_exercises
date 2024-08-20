//
// Created by kok on 19.08.24.
//

#include <fstream>

using namespace std;

void write_to_text_file() {
    ifstream in_file{"../romeoandjuliet.txt"};
    if (!in_file) throw runtime_error("Failed to open file for reading!");

    ofstream out_file{"../copy.txt"};
    if (!out_file) throw runtime_error("Failed to open file for writing!");

    string curr_line;

    while (getline(in_file, curr_line)) {
        out_file << curr_line << endl;
    }

    in_file.close();
    out_file.close();
}