# Day Image
Sets the image of the day of different sources as a wallpaper.

The sources are:
- [Bing](https://www.bing.com)
- [Nasa](https://www.nasa.gov/multimedia/imagegallery/iotd.html)

## Getting started
```
git clone https://github.com/golim/day-image
cd day-image
make
./bin/dayimg [OPTION]
```

### Options
```
-h, --help			dsplay this help and exit
-s, --source source		set the source of the day image (default is random)
    SOURCES:
    - bing		www.bing.com
    - nasa		www.nasa.gov/multimedia/imagegallery/iotd.html
    - random	choose randomly from the available sources
```