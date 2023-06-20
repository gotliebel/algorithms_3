/*#include <iostream>
#include <string>
#include <vector>

void PrefixToString(const std::vector<int>& prefix) {
  std::string string;
  string += 'a';
  for (size_t i = 1; i < prefix.size(); ++i) {
    if (prefix[i] != 0) {
      string += string[prefix[i] - 1];
    } else {
      int k = prefix[i - 1];
      std::vector<bool> u(27, false);
      u[0] = true;
      while (k > 0) {
        u[string[k] - 'a' + 1] = true;
        k = prefix[k - 1];
      }
      size_t j = 1;
      do {
        j++;
      } while (u[j] && j < u.size()) ;
      j--;
      string += 'a' + j;
    }
  }
  for (size_t i = 0; i < string.size(); ++i) {
    std::cout << string[i];
  }
}

int main() {
  size_t n = 0;
  std::cin >> n;
  std::vector<int> prefix(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> prefix[i];
  }
  if (n != 0) {
    PrefixToString(prefix);
  }
  return 0;
}*/