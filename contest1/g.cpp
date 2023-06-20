/*#include <iostream>
#include <string>
#include <vector>

bool PrefixFunction(const std::string& str, const size_t& size_p) {
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
  for (size_t i = size_p; i < pref.size(); ++i) {
    if (size_p == pref[i]) {
      return true;
    }
  }
  return false;
}

bool KMP(const std::string& string_p, const std::string& string_s) {
  std::string string_final = string_p + "#" + string_s;
  return PrefixFunction(string_final, string_p.size());
}

void SpinRevolver(const std::string& string_begin, const std::string& string_end) {
  std::string string_end_with_zero = "0" + string_end;
  std::string string_end_with_one = "1" + string_end;
  std::string string_begin_with_zero = string_begin + "0" + string_begin;
  std::string string_begin_with_one = string_begin + "1" + string_begin;
  bool zero_zero = KMP(string_end_with_zero, string_begin_with_zero);
  bool one_one = KMP(string_end_with_one, string_begin_with_one);
  bool one_zero = KMP(string_end_with_one, string_begin_with_zero);
  if (zero_zero && one_one) {
    std::cout << "Random";
  } else if (one_zero || one_one) {
    std::cout << "Yes";
  } else {
    std::cout << "No";
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  std::string string_first;
  std::string string_second;
  std::cin >> string_first >> string_second;
  SpinRevolver(string_first, string_second);
  return 0;
}*/