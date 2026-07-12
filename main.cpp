#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>
#include <vector>

using namespace ftxui;

struct TabState {
  std::vector<std::string> tab_values{"Video", "Audio"};
  int tab_selected = 0;

  std::vector<std::string> video_entries{"No URL provided"};
  int video_tab_selected = 0;

  std::vector<std::string> audio_entries{"No URL provided"};
  int audio_tab_selected = 0;
} g_tab_state;

bool show_tabs = false;

Component create_tabs() {
  auto tab_toggle = Toggle(&g_tab_state.tab_values, &g_tab_state.tab_selected);

  auto tab_container = Container::Tab(
      {
          Radiobox(&g_tab_state.video_entries, &g_tab_state.video_tab_selected),
          Radiobox(&g_tab_state.audio_entries, &g_tab_state.audio_tab_selected),
      },
      &g_tab_state.tab_selected);

  return Container::Vertical({
      tab_toggle,
      tab_container,
  });
}

void get_video_info(std::string video_url) {
  g_tab_state.video_entries = {video_url, "1080p MP4", "720p MP4"};
  g_tab_state.audio_entries = {"M4A Audio", "MP3 Audio"};
  show_tabs = true;
}

int main() {
  auto screen = ScreenInteractive::TerminalOutput();
  std::string url;

  auto url_input = Input(&url, "Paste the video URL here...");
  auto confirm_url_btn = Button("Confirm", [&url, &screen] {
    get_video_info(url);
    screen.PostEvent(Event::Custom);
  });

  auto tabs_component = create_tabs();

  auto main_container = Container::Vertical({
      url_input,
      confirm_url_btn,
      tabs_component,
  });

  // TODO -> fazer logica do botao de confirmar o download escolhido
  // TODO -> fazer as opções de qualidade serem dinamicas baseado na informaçao
  // de qualidade do video

  auto renderer = Renderer(main_container, [&] {
    Elements layout_elements;

    layout_elements.push_back(hbox(text("Welcome to MDL!")) | border);
    layout_elements.push_back(
        hbox(url_input->Render(), confirm_url_btn->Render()));

    if (show_tabs) {
      layout_elements.push_back(separator());
      layout_elements.push_back(tabs_component->Render());
    }

    return vbox(std::move(layout_elements)) | border;
  });

  screen.Loop(renderer);

  return 0;
}
