#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <stdio.h>
#include <curl/curl.h>
#include <string>

using namespace std;

size_t callbackfunction(void *ptr, size_t size, size_t nmemb, void* userdata);

bool downloadImage(string url);

#endif