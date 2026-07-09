#include "core/downloader.hpp"
#include <iostream>
#include <spdlog/spdlog.h>
#include <string>

int main() {

  std::string url = "url.test.com";
  std::string quality = "BEST";

  std::cout << "Hello, Wordl!" << "\n";
  spdlog::warn("TEST SPDLOG");

  yt::download_audio(url);
  yt::download_video(url, quality);
  yt::get_video_info(url);

  return 0;
}
