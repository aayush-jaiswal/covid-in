#include "download_data.hpp"
#include <curl/curl.h>
#include <iostream>

size_t write_data(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
}

std::string get_api_data(const char *api_url) {
    CURL *curl_handle = curl_easy_init();
    CURLcode return_code;

    if (!curl_handle) {
        std::cerr << "CURL ERROR! EXITING!";
        exit(2);
    }

    // setup
    curl_easy_setopt(curl_handle, CURLOPT_URL, api_url);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

    std::string data;
    
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &data);
    return_code = curl_easy_perform(curl_handle);
    curl_easy_cleanup(curl_handle);

    if (return_code != CURLE_OK) {
        std::cerr << "An error occured! Make sure you have an active internet connection!\n";
        exit(2);
    }

    return data;
}