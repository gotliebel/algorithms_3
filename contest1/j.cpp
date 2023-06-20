/*#include <iostream>
#include <string>
#include <vector>

void ZFunction(std::string& string, int size_first_word) {
  std::vector<int> zf(string.size());
  zf[0] = string.size();
  int left = 0;
  int right = 0;
  for (int i = 1; i < zf[0]; ++i) {
    zf[i] = std::max(0, std::min(right - i, zf[i - left]));
    while (i + zf[i] < zf[0] && string[zf[i]] == string[i + zf[i]]) {
      ++zf[i];
    }
    if (i + zf[i] > right) {
      right = i + zf[i];
      left = i;
    }
  }
  int len = string.size();
  int size = string.size();
  int position = 0;
  int index = 0;
  std::vector<std::string> answer;
  answer.resize(1);
  for (int i = size - 1; i > size_first_word; i--) {
    if (zf[i] >= len - i) {
      position = i;
      index++;
      answer.resize(index + 1);
      for (int j = i; j < len; ++j) {
        answer[index] += string[j];
      }
      len = i;
    }
  }

  if (position == size_first_word + 1) {
    std::cout << "No\n";
    for (size_t i = answer.size() - 1; i > 0; i--) {
      for (char j : answer[i]) {
        std::cout << j;
      }
      if (i > 1) {
        std::cout << " ";
      }
    }
  } else {
    std::cout << "Yes";
  }
}
int main() {
  std::string first_word;
  std::string second_word;
  std::cin >> first_word >> second_word;
  std::string new_string = first_word;
  new_string += '#';
  new_string += second_word;
  ZFunction(new_string, first_word.size());
}*/