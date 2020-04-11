#include "format_data.hpp"
#include <iostream>

std::string stripped_string(std::string s) {
    return s.substr(0, s.size());
}

void print_formatted_output (json data) {
    std::cout << "### " << stripped_string(data["state"]) << " ###" << "\n\n";
    std::cout << "Confirmed: " << stripped_string(data["confirmed"]) << " [+" << stripped_string(data["deltaconfirmed"]) <<"]\n";
    std::cout << "Active: " << stripped_string(data["active"]) << '\n';
    std::cout << "Deaths: " << stripped_string(data["deaths"]) << " [+" << stripped_string(data["deltadeaths"]) <<"]\n";
    std::cout << "Recovered: " << stripped_string(data["recovered"]) << " [+" << stripped_string(data["deltarecovered"]) <<"]\n";
    std::cout << "Last Updated Time: " << stripped_string(data["lastupdatedtime"]) << '\n';
    std::cout << "---------\n";
}

void print_formatted_tested (json data) {
    std::cout << "### Test Data ###\n\n";
    std::cout << "Total Samples Tested: " << stripped_string(data["totalsamplestested"]) << '\n';
    std::cout << "Total Positive Cases: " << stripped_string(data["totalpositivecases"]) << '\n';
    std::cout << "Last Updated Time: " << stripped_string(data["updatetimestamp"]) << '\n';
    std::cout << "---------\n";
}