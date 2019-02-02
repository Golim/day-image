using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string>


void setWallpaper(string path){
    string cmd = "nitrogen --set-auto " + path;
    system(cmd.c_str());
}