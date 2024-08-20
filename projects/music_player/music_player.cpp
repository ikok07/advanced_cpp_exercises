//
// Created by kok on 20.08.24.
//

#include <iostream>
#include <list>
#include <iomanip>
#include <limits>


using namespace std;

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }

    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }

    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "E - Play Last Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    cout << "Playing:\n" << setw(30) << left << song.get_name()
         << setw(50) << left << song.get_artist()
         << song.get_rating()
         << endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    for (const Song& song: playlist) {
        cout << setw(30) << left << song.get_name() << setw(50) << left << song.get_artist() << song.get_rating() << endl;
    }
    cout << "Current song:\n"
         << setw(30) << left << current_song.get_name()
         << setw(50) << left << current_song.get_artist()
         << current_song.get_rating()
         << endl;
}

void play_first_song(std::list<Song> &playlist, std::list<Song>::iterator& current_song) {
    current_song = playlist.begin();
    play_current_song(*current_song);
}

void play_last_song(std::list<Song> &playlist, std::list<Song>::iterator& current_song) {
    current_song = --playlist.end();
    play_current_song(*current_song);
}

void play_next_song(std::list<Song> &playlist, std::list<Song>::iterator& current_song) {
    if (current_song == --playlist.end()) {
        play_first_song(playlist, current_song);
        return;
    }

    play_current_song(*++current_song);
}

void play_previous_song(std::list<Song> &playlist, std::list<Song>::iterator& current_song) {
    if (current_song == playlist.begin()) {
        play_last_song(playlist, current_song);
        return;
    }
    play_current_song(*--current_song);
}

void add_and_play_song(std::list<Song>& playlist, std::list<Song>::iterator& current_song) {
    string name;
    string artist;
    int rating;

    cout << "Adding and playing a new song" << endl;
    cout << "Enter song name: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    cout << "Enter song artist: " << endl;
    getline(cin, artist);
    cout << "Enter your rating (1-5): " << endl;
    cin >> rating;

    Song new_song{name, artist, rating};
    playlist.insert(current_song, new_song);
    play_current_song(new_song);
}

int music_player() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}
    };

    std::list<Song>::iterator current_song = playlist.begin();

    char option{};

    display_playlist(playlist, *current_song);

    while (true) {
        display_menu();
        cin >> option;
        option = toupper(option);
        if (option == 'Q') break;
        switch (option) {
            case 'F':
                play_first_song(playlist, current_song);
                break;
            case 'E':
                play_last_song(playlist, current_song);
                break;
            case 'N':
                play_next_song(playlist, current_song);
                break;
            case 'P':
                play_previous_song(playlist, current_song);
                break;
            case 'A':
                add_and_play_song(playlist, current_song);
                break;
            case 'L':
                display_playlist(playlist, *current_song);
                break;
            default:
                cout << "Invalid option selected!" << endl;
        }
    }

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}
