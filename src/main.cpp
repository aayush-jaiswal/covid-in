#include <iostream>
#include <algorithm>
#include "json.hpp"
#include "cxxopts.hpp"

#include "format_data.hpp"
#include "download_data.hpp"
#include "abbreviation.hpp"

using json = nlohmann::json;

int main(int argc, char *argv[]) {
    std::string app_name = argv[0];
    try {
        cxxopts::Options options(app_name, "A command line app to get covid-19 update.");
        options.add_options()
            ("h, help", "Print help/usage")
            ("s, state", "Choose state(s) to display stats", cxxopts::value<std::vector<std::string>>(), "statecode")
            ("t, tested", "Show tested data")
            ("a, all", "Show data of all states in tabular form")
            ("statecodes", "Display state codes");

        auto result = options.parse(argc, argv);

        if (result.count("help")) {
            std::cout << options.help() << '\n';
            exit(0);
        }

        if (result.count("statecodes")) {
            std::cout << "The state codes are: \n\n";
            for (auto &s : abbr::india_states) {
                std::cout << s.second << ": " << s.first << '\n';
            } 
            exit(0);
        }

        std::cout << "Fetching data...\n\n";
        const char *covid_india_api = "https://api.covid19india.org/data.json";
        json all_data = json::parse(get_api_data(covid_india_api));
        
        if (result.count("all")) {
            print_formatted_all(all_data["statewise"]);
        }

        if (result.count("state")) {
            auto states = result["state"].as<std::vector<std::string>>();
            for (auto &s :  states) {
                std::transform(s.begin(), s.end(), s.begin(), ::toupper);
                for (auto &x : all_data["statewise"]) {
                    if (x["statecode"] == s) {
                        print_formatted_output(x);
                    }
                }
            }
        }
        
        if (result.count("all") == 0) {
            print_formatted_output(all_data["statewise"][0]);
        }
        
        if (result.count("tested")) {
            print_formatted_tested(all_data["tested"].back());
        }
    }
    catch (const cxxopts::OptionException& e) {
        std::cerr << "Error parsing options! Try again with valid options.\n";
        std::cerr << "Use " << app_name << " -h for help\n"; 
        return 1;
    }

    return 0;
}
