# Day Image

Sets as wallpaper the picture of the day of different sources.

The sources are:

- [Bing](https://www.bing.com)
- [Earth Science Picture of the Day](https://epod.usra.edu/)
- [NASA Earth Observatory](https://earthobservatory.nasa.gov/topic/image-of-the-day)
- [NASA](https://www.nasa.gov/multimedia/imagegallery/iotd.html)
- [National Geographic](https://www.nationalgeographic.com/photography/photo-of-the-day/)
- [Unsplash](https://unsplash.com)
- [NASA Astronomy Picture of the Day](https://apod.nasa.gov/apod/astropix.html)

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

#### On AUR

- `day-image-git`: [https://aur.archlinux.org/packages/day-image-git](https://aur.archlinux.org/packages/day-image-git)

### Uninstall

```bash
sudo make uninstall
```

## Dependencies

- [Feh](https://feh.finalrewind.org/): used to set the image as wallpaper

### Options

```bash
-h, --help             display this help and exit
-v, --verbose          print some information messages
-s, --source source    set the source of the day image (default is random)
    SOURCES:
    - bing                   https://bing.com
    - earthobservatory       https://earthobservatory.nasa.gov/topic/image-of-the-day
    - epod                   https://epod.usra.edu/
    - nasa                   https://nasa.gov/multimedia/imagegallery/iotd.html
    - national-geographic    https://nationalgeographic.com/photography/photo-of-the-day/
    - unsplash               https://unsplash.com
    - apod                   https://apod.nasa.gov/apod/astropix.html
    - random                 choose randomly from the available sources
-S, --save /path/to/image/   save the image to the specified path (default is /tmp/dayimg/)
```

## Screenshots

![How it works](screenshots/day-image.gif)
