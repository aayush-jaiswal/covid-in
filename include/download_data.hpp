#ifndef DOWNLOAD_DATA_HPP
#define DOWNLOAD_DATA_HPP

#include <string>

size_t write_data(void *contents, size_t size, size_t nmemb, void *userp);
std::string get_api_data(const char *api_url);

#endif
