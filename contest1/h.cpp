/*#include <iostream>
#include <string>
#include <vector>

std::string& PrefixFunction(std::string& str, const size_t& size_p) {
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
  for (size_t i = pref[str.size() - 1]; i < size_p; ++i) {
    str += str[i];
  }
  return str;
}

int main() {
  size_t n = 0;
  std::cin >> n;
  std::string string_first;
  std::cin >> string_first;
  std::string string_second;
  std::string string_tmp;
  std::string final;
  for (size_t i = 1; i < n; ++i) {
    std::cin >> string_second;
    if (string_second.size() <= string_first.size()) {
      for (size_t j = 0; j < string_first.size() - string_second.size(); ++j) {
        final += string_first[j];
      }
      string_first.erase(0, string_first.size() - string_second.size());
    } else if (string_first.size() + final.size() <= string_second.size()) {
      string_first.insert(string_first.begin(), final.begin(), final.end());
      final.clear();
    } else {
      size_t difference = string_second.size() - string_first.size();
      string_first.insert(string_first.begin(), final.end() - difference, final.end());
      final.erase(final.end() - difference, final.end());
    }
    string_tmp.append(string_second);
    string_tmp.append("#");
    string_tmp.append(string_first);
    string_first = PrefixFunction(string_tmp, string_second.size());
    string_first.erase(0, string_second.size() + 1);
    string_tmp.clear();
  }
  final += string_first;
  for (char i : final) {
    std::cout << i;
  }
  return 0;
}*/