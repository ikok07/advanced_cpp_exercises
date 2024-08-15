//
// Created by kok on 08.08.24.
//

#include "Movie.hpp"

string Movie::get_name() const { return this->name; }

Rating Movie::get_rating() const { return this->rating; }

int Movie::time_watched() const { return this->watched; }


void Movie::set_name(const string& val) { this->name = val; }

void Movie::set_rating(const Rating &val) { this->rating = val; }

void Movie::set_time_watched(const int val) { this->watched = val; }

string Movie::rating_str(const Rating &rating) {
    switch (rating) {
        case G: return "G";
        case PG: return "PG";
        case PG13: return "PG-13";
        case R: return "R";
        default: return "Invalid rating!";
    }
}
