#include <stdio.h>
#include <curl/curl.h>
#include <string>
#include <iostream>
#include <stdlib.h>

#include "../util/util.h"

using namespace std;

size_t callbackfunction(void *ptr, size_t size, size_t nmemb, void* userdata)
{
    FILE* stream = (FILE*)userdata;
    if (!stream)
    {
        printf("No stream\n");
        return 0;
    }

    size_t written = fwrite((FILE*)ptr, size, nmemb, stream);
    return written;
}

bool downloadImage(string URL, string imagePath, string imageName)
{
    const char *url = URL.c_str();

    string cmd = string("mkdir -p ") + imagePath;
    system(cmd.c_str());

    string image = imagePath + "/" + imageName;

    FILE* fp = fopen(image.c_str(), "w+b");
    if (!fp){
        printf("Failed to create file on the disk\n");
        return false;
    }

    CURL* curlCtx = curl_easy_init();
    curl_easy_setopt(curlCtx, CURLOPT_URL, url);
    curl_easy_setopt(curlCtx, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curlCtx, CURLOPT_WRITEFUNCTION, callbackfunction);
    curl_easy_setopt(curlCtx, CURLOPT_FOLLOWLOCATION, 1);


    CURLcode rc = curl_easy_perform(curlCtx);
    if (rc)
    {
        printf("Failed to download: %s\n", url);
        return false;
    }

    int res_code = 0;
    curl_easy_getinfo(curlCtx, CURLINFO_RESPONSE_CODE, &res_code);
    if (!((res_code == 200 || res_code == 201) && rc != CURLE_ABORTED_BY_CALLBACK))
    {
        printf("Response code: %d\n", res_code);
        return false;
    }

    curl_easy_cleanup(curlCtx);

    fclose(fp);

    return true;
}
