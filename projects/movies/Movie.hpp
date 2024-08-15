//
// Created by kok on 08.08.24.
//

#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>

using std::string;

enum Rating {
    G, PG, PG13, R
};

class Movie {
public:
    Movie(const string& name, const Rating& rating, const int watched = 1) : name{name}, rating{rating}, watched{watched} {}
    string get_name() const;
    Rating get_rating() const;
    int time_watched() const;

    void set_name(const string& val);
    void set_rating(const Rating& val);
    void set_time_watched(int val);

    static string rating_str(const Rating& rating);
private:
    string name;
    Rating rating;
    int watched;
};


#endif //MOVIE_HPP
