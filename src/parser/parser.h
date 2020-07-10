#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <curl/curl.h>
#include <string>
#include <curl/curl.h>

using namespace std;

string getImageURL(const char * URL, string begin, string end);

#endif