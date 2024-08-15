//
// Created by kok on 08.08.24.
//

#include "Movies.hpp"

#include <iostream>
#include <stdexcept>

std::vector<Movie> Movies::get() { return movies; }

void Movies::add_movie(const string &name, const Rating &rating, int watch_count) {
    auto found_movie = find_if(this->movies.begin(), this->movies.end(), [&](const Movie& search_movie) {
       return search_movie.get_name() == name;
    });
    if (found_movie != this->movies.end()) throw std::invalid_argument("Movie is already added to collection!");
    this->movies.emplace_back(name, rating, watch_count);
}

void Movies::increment_watched(const string &movie_name) {
    auto found_movie = find_if(this->movies.begin(), this->movies.end(), [&](const Movie& search_movie) {
       return search_movie.get_name() == movie_name;
    });
    if (found_movie == this->movies.end()) throw std::invalid_argument("Movie was not found!");

    found_movie->set_time_watched(found_movie->time_watched() + 1);
}

void Movies::display() {
    for (Movie& movie: this->movies) {
        std::cout << "-------------------------------------" << '\n'
                  << "Movie name: " << movie.get_name() << '\n'
                  << "Movie rating: " << Movie::rating_str(movie.get_rating()) << '\n'
                  << "Movie watch count: " << movie.time_watched() << '\n'
                  << "-------------------------------------" << std::endl;
    }
}
