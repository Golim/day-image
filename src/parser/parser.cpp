#include <stdio.h>
#include <curl/curl.h>
#include <string>
#include <iostream>

using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

string getImageURL(const char * URL, string begin, string end) {
    CURL *curl;
    string readBuffer;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    string str = readBuffer;

    
    int pos1 = str.find(begin);
    if (pos1 > 0){
        pos1 += begin.length();
        int pos2 = str.find(end, pos1 + 1);
        if (pos2 > 0){
            return str.substr(pos1, pos2 - pos1);
        }
    }

    return "";
}