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
  void BuildSuffixAutomatAndCountSubstrings(const std::string& str) {
    st_.resize(2 * str.size());
    st_[0].link_ = -1;
    st_[0].len_ = 0;
    size_ = 1;
    last_ = 0;
    st_[0].count = 1;
    for (auto& symb : str) {
      Insert(symb);
      std::cout << count_all_ << "\n";
    }
  }
 private:
  void Insert(const char& symb) {
    int cur = size_++;
    st_[cur].len_ = st_[last_].len_ + 1;
    int p = last_;
    for (; p != -1 && st_[p].next_.find(symb) == st_[p].next_.end(); p = st_[p].link_) {
      st_[p].next_[symb] = cur;
      st_[st_[p].next_[symb]].count += st_[p].count;
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
          st_[copy].count += st_[p].count;
          st_[q].count -= st_[p].count;
        }
      }
    }
    count_all_ += st_[cur].count;
    last_ = cur;
  }
  struct State {
    size_t len_ = 0;
    int link_ = -1;
    size_t count = 0;
    std::map<char, int> next_;
  };
  int last_ = -1;
  size_t size_ = 1;
  size_t count_all_ = 0;
  std::vector<State> st_;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::string str;
  std::cin >> str;
  SuffixAutomat suffix_automat;
  suffix_automat.BuildSuffixAutomatAndCountSubstrings(str);
  return 0;
}*/