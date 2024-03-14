#include "colors.hpp"
#include "random.hpp"
#include "utils.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Window.hpp>
#include <chrono>
#include <iostream>
#include <thread>

constexpr inline size_t SCREEN_WIDTH = 1366;
constexpr inline size_t SCREEN_HEIGHT = 768;
constexpr inline size_t FONT_SIZE = 64;

int main() {
  sf::RenderWindow window{sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Satris"};

  sf::Font font;
  font.setSmooth(false);
  if (!font.loadFromFile(
          "/usr/share/fonts/TTF/PixelifySans-VariableFont_wght.ttf")) {
    std::cerr << "no font";
  }

  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(FONT_SIZE);
  text.setStyle(sf::Text::Style::Regular);

  std::vector<wchar_t> unicodeSymbols;
  for (size_t i = 21; i < 0x10FFF; ++i) {
    if (!font.hasGlyph(static_cast<wchar_t>(i)))
      continue;

    if (i >= 0xD800 && i <= 0xDFFF)
      continue;

    unicodeSymbols.push_back(static_cast<wchar_t>(i));
  }

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    for (size_t i = 0;
         i < (SCREEN_HEIGHT / FONT_SIZE) * (SCREEN_WIDTH / FONT_SIZE); ++i) {
      size_t row = i / (SCREEN_WIDTH / FONT_SIZE);
      size_t col = i % (SCREEN_WIDTH / FONT_SIZE);
      text.setPosition(col * FONT_SIZE, row * FONT_SIZE);
      text.setString(get_random_char(unicodeSymbols));
      text.setCharacterSize(FONT_SIZE);
      text.setFillColor(get_random_color(catpuccinoColors));
      window.draw(text);
    }
    window.display();
    // screenshot(window);
    // std::this_thread::sleep_for(std::chrono::duration(std::chrono::seconds(4)));
    // return 0;
  }
  return 0;
}
