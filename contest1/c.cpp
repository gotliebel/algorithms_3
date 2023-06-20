/*#include <iostream>
#include <string>
#include <vector>

void ZFunction(const std::string& str) {
  std::vector<int> zf(str.size());
  zf[0] = str.size();
  int left = 0, right = 0;
  for (int i = 1; i < zf[0]; ++i) {
    zf[i] = std::max(0, std::min(right - i, zf[i - left]));
    while (i + zf[i] < zf[0] && str[zf[i]] == str[i + zf[i]]) {
      ++zf[i];
    }
    if (i + zf[i] > right) {
      right = i + zf[i];
      left = i;
    }
  }
  for (size_t i = 0; i < zf.size(); ++i) {
    std::cout << zf[i] << " ";
  }
}
int main() {
  std::string string;
  std::cin >> string;
  ZFunction(string);
  return 0;
}*/