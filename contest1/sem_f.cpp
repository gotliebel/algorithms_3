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
    for (auto& symb : s) {
      Insert(symb);
    }
  }
  void Insert(char symb) {
    int cur = size_++;
    st_[cur].len_ = st_[last_].len_ + 1;
    int p = last_;
    for (; p != -1 && st_[p].next_.find(symb) == st_[p].next_.end(); p = st_[p].link_) {
      st_[p].next_[symb] = cur;
    }
    if (p == -1) {
      st_[cur].link_ = 0;
    } else {
      int q = st_[p].next_[symb];
      if (st_[q].len_ == st_[p].len_ + 1) {
        st_[cur].link_ = q;
      } else {
        int copy = size_++;
        st_[copy].len_ = st_[p].len_ + 1;
        st_[copy].next_ = st_[q].next_;
        st_[copy].link_ = st_[q].link_;
        st_[copy].copy = true;
        st_[q].link_ = st_[cur].link_ = copy;
        for (; p != -1 && st_[p].next_[symb] == q; p = st_[p].link_) {
          st_[p].next_[symb] = copy;
        }
      }
    }
    last_ = cur;
  }
  void CountEndPos() {
    for (int i = 1; i < size_; i++) {
      st_[st_[i].link_].end_pos.push_back(i);
    }
  }
  void NumberOcurrences(int index, int& ocurrences) {
    if (index == 0) {
      return;
    }
    if (!st_[index].copy) {
      ocurrences++;
    }
    for (size_t i = 0; i < st_[index].end_pos.size(); i++) {
      NumberOcurrences(st_[index].end_pos[i], ocurrences);
    }
  }
  int FirstOcurrence(const std::string& string) {
    int st = 0;
    for (auto& i : string) {
      if (st_[st].next_.find(i) == st_[st].next_.end()) {
        st = 0;
        break;
      }
      st = st_[st].next_[i];
    }
    return st;
  }
 private:
  struct State {
    size_t len_ = 0;
    int link_ = -1;
    std::vector<int> end_pos;
    bool copy = false;
    std::map<char, int> next_;
  };
  int last_ = -1;
  size_t size_ = 1;
  std::vector<State> st_;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::string string;
  std::cin >> string;
  SuffixAutomat automat(string);
  size_t n = 0;
  std::cin >> n;
  automat.CountEndPos();
  for (size_t i = 0; i < n; ++i) {
    std::cin >> string;
    int ocurrences = 0;
    int index = 0;
    index = automat.FirstOcurrence(string);
    automat.NumberOcurrences(index, ocurrences);
    std::cout << ocurrences << "\n";
  }
  return 0;
}*/