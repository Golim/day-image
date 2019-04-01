# Day Image
Sets the image of the day of different sources as a wallpaper on Linux.

The sources are:
- [Bing](https://www.bing.com)
- [Nasa](https://www.nasa.gov/multimedia/imagegallery/iotd.html)
- [National Geographic](https://www.nationalgeographic.com/photography/photo-of-the-day/)

## Getting started
```
git clone https://github.com/golim/day-image
cd day-image
make
./bin/dayimg [OPTION]
```

### Install
```
sudo make install
```

### Uninstall
```
sudo make uninstall
```

## Dependencies
- [Feh](https://feh.finalrewind.org/): used to set the image as wallpaper

### Options
```
-h, --help			dsplay this help and exit
-s, --source source		set the source of the day image (default is random)
    SOURCES:
    - bing		            www.bing.com
    - nasa		            www.nasa.gov/multimedia/imagegallery/iotd.html
    - national-geographic           www.nationalgeographic.com/photography/photo-of-the-day/
    - random                        choose randomly from the available sources
```

## Screenshots
![Bing](screenshots/bing.png)

![National Geographic](screenshots/national-geographic.png)
