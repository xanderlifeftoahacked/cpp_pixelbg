#include <SFML/Graphics/Color.hpp>
#include <random>
#include <vector>

inline int gen_random_range(int l, int r) {
  static std::mt19937 dev;
  std::uniform_int_distribution<int> gen(l, r);
  return gen(dev);
}

inline std::wstring get_random_char(const std::vector<wchar_t> &vec) {
  std::wstring str;
  str.push_back(vec[gen_random_range(0, vec.size())]);
  return str;
}

inline sf::Color get_random_color(const std::vector<sf::Color> &vec) {
  return vec[gen_random_range(0, vec.size())];
}
