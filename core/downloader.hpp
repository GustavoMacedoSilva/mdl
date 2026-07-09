#pragma once
#include <spdlog/spdlog.h>
#include <string>

namespace yt {
int get_video_info(std::string url);
int download_video(std::string url, std::string quality);
int download_audio(std::string url);
} // namespace yt
