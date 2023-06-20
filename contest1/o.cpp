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
  explicit SuffixAutomat(size_t q) {
    st_.resize(2 * q);
    st_[0].link_ = -1;
    st_[0].len_ = 0;
    last_ = 0;
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
  void Query(size_t k) {
    if (st_[st_[last_].link_].len_ < k) {
      std::cout << "+\n";
    } else {
      std::cout << "-\n";
    }
  }
 private:
  struct State {
    size_t len_ = 0;
    int link_ = -1;
    std::map<char, int> next_;
  };
  int last_ = 0;
  size_t size_ = 1;
  std::vector<State> st_;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  size_t q = 0;
  std::cin >> q;
  char command = 0;
  char letter = 0;
  size_t k = 0;
  SuffixAutomat automat(q);
  for (size_t i = 0; i < q; i++) {
    std::cin >> command;
    if (command == '+') {
      std::cin >> letter;
      automat.Insert(letter);
    } else {
      std::cin >> k;
      automat.Query(k);
    }
  }
  return 0;
}*/