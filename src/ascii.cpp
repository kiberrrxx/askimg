#include <iostream>
#include <fstream>
#include <cstring>
#include <Magick++.h>
#include "ascii.hpp"

using namespace Magick;

void process_image(const Config& conf) {
 try {
 InitializeMagick("");
 Image image;
 image.read(conf.path);

 int target_w = conf.width;
 int target_h;

 if (conf.height > 0) {

  target_h = conf.height;
 } else {

  target_h = static_cast<int>(image.rows() * (static_cast<double>(target_w) / image.columns()) * 0.5);
 }

 image.scale(Geometry(std::to_string(target_w) + "x" + std::to_string(target_h) + "!"));

 image.type(TrueColorType);

 const char* char_map = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczMW&8%B@$";
 int num_chars = strlen(char_map);
 std::string result = "";

 for (size_t y = 0; y < image.rows(); ++y) {
  const Quantum *pixels = image.getConstPixels(0, y, image.columns(), 1);
  for (size_t x = 0; x < image.columns(); ++x) {
  int r = MagickCore::ScaleQuantumToChar(MagickCore::GetPixelRed(image.image(), pixels));
  int g = MagickCore::ScaleQuantumToChar(MagickCore::GetPixelGreen(image.image(), pixels));
  int b = MagickCore::ScaleQuantumToChar(MagickCore::GetPixelBlue(image.image(), pixels));

  int avg = static_cast<int>(0.2126 * r + 0.7152 * g + 0.0722 * b);
  if (conf.invert) avg = 255 - avg;

  char c = char_map[avg * (num_chars - 1) / 255];

  if (conf.color) {
   printf("\033[38;2;%d;%d;%dm%c\033[0m", r, g, b, c);
  } else {
   std::cout << c;
  }
  result += c;

  pixels += MagickCore::GetPixelChannels(image.image());
  }
  std::cout << "\n";
  result += "\n";
 }

 if (!conf.output.empty()) {
  std::ofstream out(conf.output);
  if (out.is_open()) {
  out << result;
  out.close();
  std::cout << "\n[Done] Saved to " << conf.output << std::endl;
  }
 }

 } catch (Exception &error) {
 std::cerr << "Error: " << error.what() << std::endl;
 }
}
