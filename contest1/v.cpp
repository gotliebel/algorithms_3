/*#include <iostream>
#include <string>
#include <map>
#include <vector>

class SuffixAutomat {
 public:
  SuffixAutomat() : last_(0), size_(1), st_(1) {
    st_[0].len_ = 0;
    st_[0].link_ = -1;
  }
  explicit SuffixAutomat(const std::string& s) : st_(2 * s.size()) {
    st_[0].link_ = -1;
    st_[0].len_ = 0;
    size_ = 1;
    last_ = 0;
    str_ = s;
    for (auto& symb : s) {
      Insert(symb);
    }
  }
  void Insert(char symb) {
    int cur = size_++;
    st_[cur].len_ = st_[last_].len_ + 1;
    int p = last_;
    st_[cur].end_pos_ = st_[last_].end_pos_ + 1;
    for (; p != -1 && st_[p].next_.find(symb) == st_[p].next_.end(); p = st_[p].link_) {
      st_[p].next_[symb] = cur;
    }
    if (p == -1) {
      st_[cur].link_ = 0;
    } else {
      int q  = st_[p].next_[symb];
      if (st_[q].len_ == st_[p].len_ + 1) {
        st_[cur].link_ = q;
      } else {
        int copy = size_++;
        st_[copy].len_ = st_[p].len_ + 1;
        st_[copy].next_ = st_[q].next_;
        st_[copy].link_ = st_[q].link_;
        st_[q].link_ = st_[cur].link_ = copy;
        for (; p != -1 && st_[p].next_[symb] == q; p = st_[p].link_) {
          st_[p].next_[symb] = copy;
        }
      }
    }
    last_ = cur;
  }
  void ExtractTransitions(const int& node_id) {
    int suffix_id = st_[node_id].link_;
    uint32_t char_index = st_[node_id].end_pos_  - st_[suffix_id].len_ - 1;
    nodes_[suffix_id][str_[char_index]].length_edge_ = st_[node_id].len_ - st_[suffix_id].len_;
    nodes_[suffix_id][str_[char_index]].begin_ = node_id;
  }
  void CompressedTrie() {
    nodes_.resize(size_);
    for (size_t i = 1; i < size_; i++) {
      ExtractTransitions(i);
    }
  }
  void Print() const {
    std::cout << size_ << "\n";
    for (size_t i = 0; i < size_; ++i) {
      for (auto & pair : nodes_[i]) {
        std::cout << i << " " << pair.first << " " << pair.second.length_edge_ << " " << pair.second.begin_ << "\n";
      }
    }
  }
 private:
  struct State {
    size_t len_ = 0;
    size_t begin_ = 0;
    int link_ = -1;
    int length_edge_ = 1;
    int end_pos_;
    std::map<char, int> next_;
  };
  int last_ = -1;
  size_t size_ = 1;
  std::vector<State> st_;
  std::string str_;
  std::vector<std::map<char, State>> nodes_;
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::string string;
  std::cin >> string;
  for (size_t i = 0; i < string.size() / 2; i++) {
    char tmp = string[i];
    string[i] = string[string.size() - i - 1];
    string[string.size() - i - 1] = tmp;
  }
  std::string final = "#";
  final += string;
  SuffixAutomat automat(final);
  automat.CompressedTrie();
  automat.Print();
  return 0;
}*/