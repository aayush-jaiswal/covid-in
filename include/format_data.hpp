#ifndef FORMAT_DATA_HPP
#define FORMAT_DATA_HPP

#include <string>
#include <iomanip>
#include "json.hpp"
using json = nlohmann::json;

std::string stripped_string(std::string s);
void print_formatted_output(json data);
void print_formatted_tested(json data);
void print_formatted_all(json states);
void print_content(std::string s, int width);

#endif