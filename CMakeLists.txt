cmake_minimum_required(VERSION 3.28)
project(advanced_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(advanced_cpp main.cpp
        projects/pyramide.cpp
        projects/movies/Movie.cpp
        projects/movies/Movie.hpp
        projects/movies/Movies.cpp
        projects/movies/Movies.hpp
        projects/operator_overloading/Mystring.h
        projects/operator_overloading/Mystring.cpp
        projects/accounts/Account.h
        projects/accounts/Account_Util.cpp
        projects/accounts/Account_Util.h
        projects/accounts/Savings_Account.cpp
        projects/accounts/Account.cpp
        projects/accounts/Checking_Account.hpp
        projects/accounts/Checking_Account.cpp
        projects/accounts/Trust_Account.hpp
        projects/accounts/Trust_Account.cpp
        projects/printable/I_Printable.cpp
        projects/printable/I_Printable.hpp
        projects/exceptions/IllegalBalanceException.hpp
        projects/exceptions/InsufficentFundsException.hpp
        projects/file_streams/read_from_text_file.cpp
        projects/file_streams/search_from_text.cpp
        projects/file_streams/write_to_text_file.cpp
        projects/array/array.cpp
        projects/palindrome/is_palindrome.cpp
        projects/music_player/music_player.cpp)
