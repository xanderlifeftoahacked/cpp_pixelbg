#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

inline void screenshot(sf::RenderWindow &win) {
  sf::Texture texture;
  texture.create(win.getSize().x, win.getSize().y);
  texture.update(win);
  texture.copyToImage().saveToFile("bg.png");
}
