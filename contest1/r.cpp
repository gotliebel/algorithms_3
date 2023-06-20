/*#include <cmath>
#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>
#include <vector>

class Trie {
 public:
  void Insert(const std::string& str, const size_t& index) {
    if (root_ == nullptr) {
      root_ = std::make_shared<Node>(Node{});
      root_->length = 0;
    }
    std::shared_ptr<Node> node = root_;
    for (size_t i = 0; i < str.size(); ++i) {
      if (node->next_.find(str[i]) == node->next_.end()) {
        node->next_[str[i]] = std::make_shared<Node>(Node{});
        node->next_[str[i]]->length = node->length + 1;
        max_length_ = std::max(max_length_, node->length + 1);
      }
      node = node->next_[str[i]];
    }
    node->terminal = true;
    node->index = index;
  }
  struct Node {
    std::unordered_map<char, std::shared_ptr<Node>> next_;
    size_t length = 0;
    bool terminal = false;
    int index = 0;
  };
  size_t CountCakes(const std::shared_ptr<Node>& node, const int& m) {
    if (node->terminal) {
      answer_[node->index] = powl(10, m - node->length);
    }
    size_t recur_dif = 0;
    for (auto& i : node->next_) {
      size_t recur = CountCakes(i.second, m);
      if (node->terminal) {
        if (i.second->terminal) {
          answer_[node->index] -= powl(10, m - i.second->length);
        } else {
          recur_dif += recur;
        }
      } else {
        if (i.second->terminal) {
          recur_dif += powl(10, m - i.second->length);
        } else {
          recur_dif += recur;
        }
      }
    }
    if (node->terminal) {
      answer_[node->index] -= recur_dif;
    }
    return recur_dif;
  }
  auto& GetAnswer() {
    return answer_;
  }
  auto GetRoot() {
    return root_;
  }
 private:
  std::shared_ptr<Node> root_ = nullptr;
  std::vector<size_t> answer_;
  size_t max_length_ = 0;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  Trie trie;
  std::string index_city;
  std::string name;
  size_t n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<std::string> names(n);
  trie.GetAnswer().resize(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> index_city;
    std::cin >> name;
    if (index_city.size() > static_cast<size_t>(m)) {
      trie.GetAnswer()[i] = 0;
    } else {
      trie.Insert(index_city, i);
    }
    names[i] = name;
  }
  trie.CountCakes(trie.GetRoot(), m);
  for (size_t i = 0; i < n; ++i) {
    std::cout << names[i] << " " << trie.GetAnswer()[i] << "\n";
  }
  return 0;
}*/