/*#include <iostream>
#include <string>
#include <vector>

void PrefixFunction(const std::string& str, const size_t& size_p) {
  std::vector<size_t> pref(str.size(), 0);
  for (size_t i = 1; i < str.size(); ++i) {
    size_t previous = pref[i - 1];
    while (previous > 0 && str[i] != str[previous]) {
      previous = pref[previous - 1];
    }
    if (str[i] == str[previous]) {
      ++previous;
    }
    pref[i] = previous;
  }
  for (size_t i = 0; i < pref.size(); ++i) {
    if (pref[i] == size_p) {
      std::cout << i - 2 * size_p << "\n";
    }
  }
}

void KMP(const std::string& string_s, const std::string& string_p) {
  std::string string_final = string_p + "#" + string_s;
  PrefixFunction(string_final, string_p.size());
}

int main() {
  std::string string_p;
  std::string string_s;
  std::cin >> string_s >> string_p;
  KMP(string_s, string_p);
  return 0;
}*/