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

void print_formatted_tested (json data) {
    std::cout << "Test Data\n";
    std::cout << "Total sample tested: " << stripped_string(data["totalsamplestested"]) << '\n';
    std::cout << "Total positive cases: " << stripped_string(data["totalpositivecases"]) << '\n';
    std::cout << "Last Updated Time: " << stripped_string(data["updatetimestamp"]) << '\n';
    std::cout << "---------\n";
}