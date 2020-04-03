#include "format_data.hpp"
#include <iostream>

std::string stripped_string(std::string s) {
    return s.substr(0, s.size());
}

void print_formatted_output (json data) {
    std::cout << stripped_string(data["state"]) << '\n';
    std::cout << "Confirmed: " << stripped_string(data["confirmed"]) << '\n';
    std::cout << "Active: " << stripped_string(data["active"]) << '\n';
    std::cout << "Deaths: " << stripped_string(data["deaths"]) << '\n';
    std::cout << "Recovered: " << stripped_string(data["recovered"]) << '\n';
    std::cout << "Last Updated Time: " << stripped_string(data["lastupdatedtime"]) << '\n';
    std::cout << "---------\n";
}