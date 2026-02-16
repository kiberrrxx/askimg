#ifndef ASCII_H
#define ASCII_H

#include <string>

struct Config {
 std::string path;
 int width = 100;
 int height = 0;
 bool color = false;
 bool invert = false;
 std::string output = "";
};

void process_image(const Config& conf);

#endif
