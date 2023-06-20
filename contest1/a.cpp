/*#include <iostream>
#include <string>
#include <vector>

void PrefixFunction(const std::string& str) {
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
    std::cout << pref[i] << " ";
  }
}


int main() {
  std::string string;
  std::cin >> string;
  PrefixFunction(string);
  return 0;
}*/