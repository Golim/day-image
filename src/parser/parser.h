#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <curl/curl.h>
#include <string>
#include <curl/curl.h>

using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
string getImageURL(const char * URL, string begin, string end);
string getSubstring(string str, string begin, string end);

#endif