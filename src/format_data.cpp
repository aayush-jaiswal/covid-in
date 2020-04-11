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

void print_content(std::string s, int width) {
    char space = ' ';
    std::cout << std::right << std::setw(width) << std::setfill(space) << stripped_string(s);
}

void print_formatted_all(json states) {
    int state_width = 30;
    int num_width = 12;

    print_content("State/UT", state_width);
    print_content("Confirmed", num_width);
    print_content("Active", num_width);
    print_content("Recovered", num_width);
    print_content("Deaths", num_width);
    std::cout << '\n';
    std::cout << std::left << std::setw(state_width + 4 * num_width) << std::setfill('-') << " ";
    std::cout << '\n';
    bool skip_total = true;
    for (auto& s : states) {
        if (skip_total) {
            skip_total = false;
            continue;
        }
        print_content(s["state"], state_width);
        print_content(s["confirmed"], num_width);
        print_content(s["active"], num_width);
        print_content(s["recovered"], num_width);
        print_content(s["deaths"], num_width);
        std::cout << '\n';
    }
    std::cout << std::left << std::setw(state_width + 4 * num_width) << std::setfill('-') << " ";
    std::cout << '\n';
    print_content(states[0]["state"], state_width);
    print_content(states[0]["confirmed"], num_width);
    print_content(states[0]["active"], num_width);
    print_content(states[0]["recovered"], num_width);
    print_content(states[0]["deaths"], num_width);
    std::cout << '\n';
    std::cout << std::left << std::setw(state_width + 4 * num_width) << std::setfill('-') << " ";
    std::cout << '\n';
}

