//
// Created by kok on 15.08.24.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

vector<char> get_answers_arr(string& answers) {
    vector<char> arr;
    for (const char& c: answers) {
        arr.push_back(c);
    }
    return arr;
}

int calc_score(const vector<char> correct_answers, const vector<char> student_anwers) {
    int count{};
    for (int i = 0; i < correct_answers.size(); i++) {
        if (correct_answers[i] == student_anwers[i]) count++;
    }
    return count;
}

double sum_scores(const vector<int>& scores) {
    double sum{};
    for (const int score: scores) sum += score;
    return sum;
}

void read_from_text_file() {
    ifstream file{"./responses.txt"};
    if (!file) throw runtime_error("Failed to open responses file!");

    string answers_str;
    getline(file, answers_str);
    answers_str.pop_back();

    auto correct_answers = get_answers_arr(answers_str);

    cout << setw(20) << left << "Student" << setw(10) << right << "Score" << endl;
    cout << setw(30) << setfill('-') << "" << setfill(' ') << endl;

    vector<int> scores;

    string curr_student;
    while(getline(file, curr_student)) {
        curr_student.pop_back();
        string str;
        getline(file, str);
        if (str[str.length()] == '\r') str.pop_back();

        auto answers = get_answers_arr(str);
        int score = calc_score(correct_answers, answers);
        scores.push_back(score);
        cout << setw(20) << left << curr_student << setw(10) << right << score << endl;
    }

    cout << setw(30) << setfill('-') << "" << setfill(' ') << endl;

    cout << "Average score" << setw(17) << sum_scores(scores) / scores.size() << endl;
}