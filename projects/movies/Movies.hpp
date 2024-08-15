//
// Created by kok on 08.08.24.
//

#ifndef MOVIES_HPP
#define MOVIES_HPP
#include <vector>

#include "Movie.hpp"


class Movies {
public:
    std::vector<Movie> get();
    void add_movie(const string& name, const Rating& rating, int watch_count);
    void increment_watched(const string& movie_name);
    void display();
private:
    std::vector<Movie> movies;
};



#endif //MOVIES_HPP
