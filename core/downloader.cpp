#include "downloader.hpp"
#include <spdlog/spdlog.h>
#include <string>

namespace yt {
int download_audio(std::string url) {
  spdlog::info("YT Download Audio function called!");
  return 0;
}
int download_video(std::string url, std::string quality) {
  spdlog::info("YT Download Video function called!");
  return 0;
}
int get_video_info(std::string url) {
  spdlog::info("YT Video Info function called!");
  return 0;
}
} // namespace yt
