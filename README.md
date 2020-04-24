# Day Image

Sets as wallpaper the picture of the day of different sources.

The sources are:

- [Bing](https://www.bing.com)
- [Nasa](https://www.nasa.gov/multimedia/imagegallery/iotd.html)
- [National Geographic](https://www.nationalgeographic.com/photography/photo-of-the-day/)

## Getting started

```bash
git clone https://github.com/golim/day-image
cd day-image
make
./bin/dayimg [OPTION]
```

### Install

```bash
sudo make install
```

### Uninstall

```bash
sudo make uninstall
```

## Dependencies

- [Feh](https://feh.finalrewind.org/): used to set the image as wallpaper

### Options

```bash
-h, --help			dsplay this help and exit
-s, --source source		set the source of the day image (default is random)
    SOURCES:
    - bing		            www.bing.com
    - nasa		            www.nasa.gov/multimedia/imagegallery/iotd.html
    - national-geographic   www.nationalgeographic.com/photography/photo-of-the-day/
    - unsplash              https://unsplash.com
    - random                        choose randomly from the available sources
```

## Screenshots

![Functioning](screenshots/day-image.gif)
