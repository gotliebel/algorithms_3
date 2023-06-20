/*#include <iostream>
#include <string>
#include <ctime>
#include <map>
#include <vector>

class SuffixAutomat {
 public:
  SuffixAutomat() : last_(0), size_(1), st_(1) {
    st_[0].len_ = 0;
    st_[0].link_ = -1;
  }
  explicit SuffixAutomat(const std::string& s) : st_(2 * s.size()) {
    st_[0].last_index_ = -1;
    st_[0].link_ = -1;
    st_[0].len_ = 0;
    size_ = 1;
    last_ = 0;
    for (auto& symb : s) {
      Insert(symb);
    }
    for (size_t i = 1; i < size_; i++) {
      st_[st_[i].link_].links_.push_back(i);
    }
  }
  void Insert(const char& symb) {
    int cur = size_++;
    st_[cur].len_ = st_[last_].len_ + 1;
    int p = last_;
    st_[cur].last_index_ = static_cast<int>(st_[cur].len_) - 1;
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
        st_[copy].last_index_ = st_[q].last_index_;
        st_[q].link_ = st_[cur].link_ = copy;
        for (; p != -1 && st_[p].next_[symb] == q; p = st_[p].link_) {
          st_[p].next_[symb] = copy;
        }
      }
    }
    last_ = cur;
  }

  void CheckAllOcurrences(const int& st, const int& length, const int& index, bool& is_found, const int& left, const int& right) {
    if (st != 0) {
      if (!st_[st].copy) {
        if (st_[st].last_index_ - length + 2 >= left
            && st_[st].last_index_ + 1 <= right) {
          is_found = true;
          return;
        }
      }
      if (!is_found) {
        for (auto& link : st_[st].links_) {
          if (is_found) {
            break;
          }
          CheckAllOcurrences(link, length, index, is_found, left, right);
        }
      }
    }
  }
  void FirstOcurrence(const std::string& string, const int& index, const int& left, const int& right) {
    int st = 0;
    for (auto& i : string) {
      if (st_[st].next_.find(i) != st_[st].next_.end()) {
        st = st_[st].next_[i];
      } else {
        st = 0;
        break;
      }
    }
    bool is_found = false;
    CheckAllOcurrences(st, string.size(), index, is_found, left, right);
    if (is_found) {
      std::cout << "+";
    } else {
      std::cout << "-";
    }
  }
 private:
  struct State {
    size_t len_ = 0;
    int link_ = -1;
    int last_index_;
    bool copy = false;
    std::vector<int> links_;
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
  int left = 0;
  int right = 0;
  std::string check;
  for (size_t i = 0; i < n; ++i) {
    std::cin >> left >> right >> check;
    automat.FirstOcurrence(check, i, left, right);
  }
  return 0;
}*/