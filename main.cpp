// #include "core/downloader.hpp"
#include <ftxui/component/app.hpp>
#include <ftxui/component/captured_mouse.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/dom/elements.hpp>
#include <spdlog/spdlog.h>
#include <string>

using namespace ftxui;

void Video(std::string url) {}

void Audio(std::string url) {}

int main() {
  App screen = App::FitComponent();
  std::string url("");
  std::string url_final;
  Component input_url = Input(&url, "placeholder");
  auto video_button = Button("Video", [&url, &screen, &url_final] {
    url_final = url;
    screen.PostEvent(Event::Custom);
  });

  auto component = Container::Vertical({
      input_url,
      video_button,
  });
  auto renderer = Renderer(component, [&] {
    return vbox({
               hbox(text("input url: "), input_url->Render()),
               hbox(text(""), video_button->Render()),
               vbox({
                   text(url_final),
               }) | border,
           }) |
           border;
  });
  screen.Loop(renderer);

  return 0;
}
