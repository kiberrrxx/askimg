#include <iostream>
#include <getopt.h>
#include "ascii.hpp"

// Цвета в стиле Hyprland
#define HYPR_MAGENTA "\033[1;38;2;237;145;231m"
#define HYPR_CYAN  "\033[1;38;2;130;200;245m"
#define HYPR_WHITE  "\033[1;37m"
#define RESET    "\033[0m"

void print_help() {
  std::cout << HYPR_MAGENTA << " __ _ ___| | _(_)_ __ ___  __ _ \n"
       << " / _` |/ __| |/ / | '_ ` _ \\ / _` |\n"
       << "| (_| | (__|  <| | | | | | | (_| |\n"
       << " \\__,_|\\___|_|\\_\\_|_| |_| |_|\\__, |\n"
       << "               |___/ " << RESET << "\n\n";

  std::cout << HYPR_CYAN << "Usage: " << RESET << "askimg [options] <file>\n\n";

  std::cout << HYPR_MAGENTA << "Options:\n" << RESET
       << " " << HYPR_CYAN << "-w <n>" << RESET << " Width of the output\n"
       << " " << HYPR_CYAN << "-h <n>" << RESET << " Height of the output\n"
       << " " << HYPR_CYAN << "-c  " << RESET << " Enable TrueColor mode\n"
       << " " << HYPR_CYAN << "-i  " << RESET << " Invert luminance\n"
       << " " << HYPR_CYAN << "-o <f>" << RESET << " Save clean ASCII to file\n"
       << " " << HYPR_CYAN << "-v  " << RESET << " Show version\n\n";

  std::cout << HYPR_WHITE << "Example: " << RESET << "askimg -w 100 -c image.jpg\n";
}

int main(int argc, char** argv) {
  Config conf;
  int c;

  if (argc < 2) {
    print_help();
    return 0;
  }

  while ((c = getopt(argc, argv, "w:h:co:iv")) != -1) {
    switch (c) {
      case 'w': conf.width = std::stoi(optarg); break;
      case 'h': conf.height = std::stoi(optarg); break;
      case 'c': conf.color = true; break;
      case 'i': conf.invert = true; break;
      case 'o': conf.output = optarg; break;
      case 'v': 
        std::cout << HYPR_MAGENTA << "askimg" << RESET << " version " << HYPR_CYAN << "1.0.0-gentoo" << RESET << std::endl;
        return 0;
      default: print_help(); return 1;
    }
  }

  if (optind < argc) {
    conf.path = argv[optind];
  } else {
    std::cout << HYPR_MAGENTA << "[Error] " << RESET << "No input file provided!\n";
    return 1;
  }

  process_image(conf);
  return 0;
}
