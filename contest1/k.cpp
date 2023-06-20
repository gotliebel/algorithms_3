/*#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

class Trie {
 public:
  struct Node {
    std::unordered_map<char, std::shared_ptr<Node>> next_;
  };
  std::shared_ptr<Node> root_ = nullptr;
  void Insert(const std::string& str) {
    if (root_ == nullptr) {
      root_ = std::make_shared<Node>(Node{});
    }
    std::shared_ptr<Node> node = root_;
    for (size_t i = 0; i < str.size(); ++i) {
      if (node->next_.find(str[i]) == node->next_.end()) {
        node->next_[str[i]] = std::make_shared<Node>(Node{});
      }
      node = node->next_[str[i]];
    }
  }
  void StringInBor(const std::string& string) {
    if (root_ == nullptr) {
      std::cout << "NO\n";
      return;
    }
    std::shared_ptr<Node> node = root_;
    bool is_in_bor = true;
    for (auto& symb : string) {
      if (node->next_.find(symb) == node->next_.end()) {
        is_in_bor = false;
        break;
      }
      node = node->next_[symb];
    }
    if (is_in_bor) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  Trie trie;
  std::string string;
  char c = 'c';
  while (std::cin >> c && c != '#') {
    std::cin >> string;
    if (c == '+') {
      trie.Insert(string);
    } else {
      trie.StringInBor(string);
    }
  }
  return 0;
}*/