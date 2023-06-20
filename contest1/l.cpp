/*#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <queue>

class Trie {
 public:
  explicit Trie(size_t size) : result_(size) {};
  void Insert(std::string& str, int64_t index) {
    if (tree_.empty()) {
      tree_.emplace_back(std::make_shared<Node>(Node{}));
    }
    std::shared_ptr<Node> cur_node = tree_[0];
    for (auto& symb : str) {
      int64_t next_id = cur_node->next[symb];
      if (next_id == 0) {
        tree_.emplace_back(std::make_shared<Node>(Node{}));
        cur_node->next[symb] = tree_.size() - 1;
        next_id = cur_node->next[symb];
      }
      cur_node = tree_[next_id];
    }
    cur_node->is_terminal = true;
    cur_node->index = index;
    cur_node->len = str.size();
  }

  void AhoCorasik(std::string& str) {
    BuildSuffixReference();
    std::shared_ptr<Node> node = tree_[0];
    for (size_t i = 0; i < str.size(); ++i) {
      std::shared_ptr<Node> cur_node = FindRightNode(node, str[i]);
      node = cur_node;
      InsertIndexInResult(i, cur_node);
    }
  }

  void PrintResult() {
    for (size_t i = 0; i < result_.size(); ++i) {
      std::cout << result_[i].size() << " ";
      for (size_t j = 0; j < result_[i].size(); ++j) {
        std::cout << result_[i][j] << " ";
      }
      std::cout << "\n";
    }
  }

 private:
  struct Node {
    bool is_terminal = false;
    std::unordered_map<char, int> next;
    int index;
    int len;
    std::shared_ptr<Node> suff_ref;
  };

  void BuildSuffixReference() {
    tree_[0]->suff_ref = nullptr;
    std::queue<std::pair<std::pair<char, std::shared_ptr<Node>>, int>> queue;
    for (auto& symb : tree_[0]->next) {
      queue.push(std::make_pair(std::make_pair(symb.first, tree_[0]), symb.second));
    }
    while (!queue.empty()) {
      char s = queue.front().first.first;
      std::shared_ptr<Node> parent = queue.front().first.second;
      std::shared_ptr<Node> node = tree_[queue.front().second];
      queue.pop();
      std::shared_ptr<Node> suff = parent->suff_ref;
      while (suff != nullptr && suff->next.find(s) == suff->next.end()) {
        suff = suff->suff_ref;
      }
      node->suff_ref = (suff == nullptr ? tree_[0] : tree_[suff->next[s]]);
      for (auto& symbol : node->next) {
        queue.push(std::make_pair(std::make_pair(symbol.first, node), symbol.second));
      }
    }
  }

  std::shared_ptr<Node> BuildExitReference(std::shared_ptr<Node> node) {
    if (node != nullptr) {
      node = node->suff_ref;
    }
    while (node != nullptr && !node->is_terminal) {
      node = node->suff_ref;
    }
    return node;
  }

  void InsertIndexInResult(int index, std::shared_ptr<Node>& node) {
    if (!node->is_terminal) {
      node = BuildExitReference(node);
    }
    while (node != nullptr) {
      result_[node->index].push_back(index - node->len + 2);
      node = BuildExitReference(node);
    }
  }
  std::shared_ptr<Node> FindRightNode(std::shared_ptr<Node>& node, char s) {
    while (node != nullptr && node->next.find(s) == node->next.end()) {
      node = node->suff_ref;
    }
    return (node == nullptr ? tree_[0] : tree_[node->next[s]]);
  }
  std::vector<std::shared_ptr<Node>> tree_;
  std::vector<std::vector<int>> result_;
};

int main() {
  std::string string_base;
  std::cin >> string_base;
  size_t n = 0;
  std::cin >> n;
  std::string string;
  Trie trie(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> string;
    trie.Insert(string, i);
  }
  trie.AhoCorasik(string_base);
  trie.PrintResult();
  return 0;
}*/