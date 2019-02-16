using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

void setWallpaper(string imagePath){
    string cmd = "feh --bg-fill " + imagePath;
    system(cmd.c_str());
}