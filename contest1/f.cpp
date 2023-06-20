/*#include <iostream>
#include <string>
#include <vector>

int PrefixFunctionMax(const std::string& str) {
  std::vector<int> pref(str.size(), 0);
  for (size_t i = 1; i < str.size(); ++i) {
    int previous = pref[i - 1];
    while (previous > 0 && str[i] != str[previous]) {
      previous = pref[previous - 1];
    }
    if (str[i] == str[previous]) {
      ++previous;
    }
    pref[i] = previous;
  }
  int prefix_max = 0;
  for (size_t i = 0; i < pref.size(); ++i) {
    prefix_max = std::max(prefix_max, pref[i]);
  }
  return prefix_max;
}

int FindSubstring(const std::string& string) {
  int counter = 1;
  std::string string_right_now(1, string[0]);
  for (size_t i = 1; i < string.size(); ++i) {
    std::string string_reverse;
    string_reverse.resize(1);
    string_reverse[0] = string[i];
    int string_right_now_size = string_right_now.size();
    for (int j = string_right_now_size - 1; j >= 0; --j) {
      string_reverse += string_right_now[j];
    }
    string_right_now += string[i];
    string_right_now_size++;
    counter += string_right_now_size - PrefixFunctionMax(string_reverse);
  }
  return counter;
}

int main() {
  std::string string;
  std::cin >> string;
  std::cout << FindSubstring(string);
  return 0;
}*/