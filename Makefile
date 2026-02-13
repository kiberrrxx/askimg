CXX = g++
MAGICK_PKG = $(shell pkg-config --list-all | grep -oE "Magick\+\+-[^ ]+|Magick\+\+" | head -n 1)

CXXFLAGS = -O3 -std=c++11 -Isrc $(shell pkg-config --cflags $(MAGICK_PKG))
LDFLAGS = $(shell pkg-config --libs $(MAGICK_PKG))
PREFIX = /usr/local

SRC = src/main.cpp src/ascii.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = askimg

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)

install: all
	install -m 0755 -D $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)

.PHONY: all clean install
