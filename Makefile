.PHONY: build clean install uninstall
SRC = src
BUILDING = obj
BIN = bin

CXX = g++
CXXFLAGS = -std=c++0x -Wall -lcurl

PREFIX = /usr/local

build: dayimg

clean:
	rm -Rf  $(BIN)/
	rm -Rf $(BUILDING)/
	rm -f ./log.txt
	rm -f $(SRC)/*.gch

install: dayimg
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp ./bin/$< $(DESTDIR)$(PREFIX)/bin/dayimg

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/dayimg

### MAIN ###
dayimg: main.o downloader.o wallpaper.o parser.o bin
	$(CXX) $(CXXFLAGS) $(BUILDING)/main.o $(BUILDING)/downloader.o $(BUILDING)/wallpaper.o $(BUILDING)/parser.o  -o $(BIN)/dayimg

main.o: building
	$(CXX) $(CXXFLAGS) -c $(SRC)/main.cpp  -o $(BUILDING)/main.o

### PARSER ###
parser.o: $(SRC)/parser/parser.cpp $(SRC)/parser/parser.h building
	$(CXX) $(CXXFLAGS) -c $(SRC)/parser/parser.cpp -o $(BUILDING)/parser.o

### WALLPAPER ###
wallpaper.o: $(SRC)/wallpaper/wallpaper.cpp $(SRC)/wallpaper/wallpaper.h building
	$(CXX) $(CXXFLAGS) -c $(SRC)/wallpaper/wallpaper.cpp -o $(BUILDING)/wallpaper.o

### DOWNLOADER ###
downloader.o: $(SRC)/downloader/downloader.cpp $(SRC)/downloader/downloader.h building
	$(CXX) $(CXXFLAGS) -c $(SRC)/downloader/downloader.cpp -o $(BUILDING)/downloader.o



### MAKE DIRECTORIES ###
bin:
	mkdir $(BIN) -p

building:
	mkdir $(BUILDING) -p