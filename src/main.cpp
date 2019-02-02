#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 

#include "downloader/downloader.h"
#include "wallpaper/wallpaper.h"
#include "parser/parser.h"

using namespace std;

string SOURCE = "random";

// Move this in a util file
char * BING_URL = "www.bing.com";
string BING_BEGIN = "background-image:url(";
string BING_END = ".jpg);";

char * NASA_URL = "https://www.nasa.gov/rss/dyn/lg_image_of_the_day.rss";
string NASA_BEGIN = "<enclosure url=\"";
string NASA_END = ".jpg";

char * NATGEO_URL = "https://www.nationalgeographic.com/photography/photo-of-the-day/";
string NATGEO_BEGIN = "https://yourshot.nationalgeographic.com";
string NATGEO_END = "\"/>";

int parseArgument(int argc, char **argv);
void printUsage();
void printHelp();
void printError(string err);

int main(int argc, char** argv) {
    int r = parseArgument(argc, argv);

    if(r == 0){
        string imageURL = "";

        if(SOURCE.compare("bing") == 0){
            imageURL = BING_URL + getImageURL(BING_URL, BING_BEGIN, BING_END) + ".jpg";
        }
        else if (SOURCE.compare("nasa") == 0) {
            imageURL =  getImageURL(NASA_URL, NASA_BEGIN, NASA_END) + ".jpg";
        }
        else if (SOURCE.compare("national-geographic") == 0) {
            imageURL =  NATGEO_BEGIN +  getImageURL(NATGEO_URL, NATGEO_BEGIN, NATGEO_END);
        }
        else if (SOURCE.compare("random") == 0) {
            srand (time(NULL));
            int random = rand() % 3;
            if(random == 0){
                imageURL = BING_URL + getImageURL(BING_URL, BING_BEGIN, BING_END) + ".jpg";
            } else if(random == 1){
                imageURL =  getImageURL(NASA_URL, NASA_BEGIN, NASA_END) + ".jpg";
            } else if(random == 2){
                imageURL =  NATGEO_BEGIN +  getImageURL(NATGEO_URL, NATGEO_BEGIN, NATGEO_END);
            }
        }
        else {
            printError("Error: source not found");
            printUsage();
            return -2;
        }

        if (!downloadImage(imageURL))
        {
            cout << "Failed to download file";
            return -1;
        } else {
            setWallpaper("img.jpg");
            cout << "Done!\n";
        }

        return 0;
    }

    if(r > 0){
        return 0;
    }

    return r;
}

/**
 * return -1 if ERROR
 * return  0 if OK
 * return +1 if HELP
 * */
int parseArgument(int argc, char **argv){
    string option = "", value = "";

    for(int i = 1; i < argc; i++){
        option = (string) argv[i];

        // HELP         -h  --help
        if (((string) argv[1]).compare("--help") == 0 || ((string) argv[1]).compare("-h") == 0) {
            printHelp();
            return 1;
        }

        // SOURCE       -s  --source
        else if(option.compare("-s") == 0 || option.compare("--source") == 0){
            if(i + 1 <= argc){
                SOURCE = argv[i + 1];
                i++;
            } else {
                printUsage();
                return -1;
            }
        }

        // Error
        else {
            printError("Option " + option + " not found");
            printUsage();
            return -1;
        }
    }

    return 0;
}

void printUsage(){
    cout << ("Usage:  dayimg [OPTION]\n\n");
    cout << ("Try 'dayimg --help' for more information.\n");
}

void printHelp(){
    cout << "Usage:  dayimg [OPTION]" << endl;
    cout << "Sets the image of the day of different sources as a wallpaper." << endl << endl;
    cout << "OPTIONS:\nAll OPTION are not mandatory. Contemplated options are:\n";
    cout << "\t-h, --help\t\t\tdsplay this help and exit\n";
    cout << "\t-s, --source source\t\tset the source of the day image (default is random)\n";
    cout << "\t\tSOURCES:\n";
    cout << "\t\t- bing\t\t\twww.bing.com\n";
    cout << "\t\t- nasa\t\t\twww.nasa.gov/multimedia/imagegallery/iotd.html\n";
    cout << "\t\t- national-geographic\twww.nationalgeographic.com/photography/photo-of-the-day/\n";
    cout << "\t\t- random\t\tchoose randomly from the available sources\n";
    cout << "Exit codes:\n\t0: OK\n\t-1:Generic Error\n\t-2: Source not found\n";

}

void printError(string err){
    cerr << err << endl;
}