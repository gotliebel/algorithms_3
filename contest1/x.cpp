#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>

class SuffixAutomat {
 public:
  SuffixAutomat() : last_(0), size_(1), st_(1) {
    st_[0].len_ = 0;
    st_[0].link_ = -1;
  }
  explicit SuffixAutomat(const std::string& str) : st_(2 * str.size()) {
    st_[0].link_ = -1;
    st_[0].len_ = 0;
    size_ = 1;
    last_ = 0;
    for (auto& symb : str) {
      Insert(symb);
    }
  }
  void Insert(const char& symb) {
    int cur = size_++;
    st_[cur].len_ = st_[last_].len_ + 1;
    int p = last_;
    st_[cur].last_index = static_cast<int>(st_[cur].len_) - 1;
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
        st_[copy].last_index = st_[q].last_index;
        st_[q].link_ = st_[cur].link_ = copy;
        for (; p != -1 && st_[p].next_[symb] == q; p = st_[p].link_) {
          st_[p].next_[symb] = copy;
        }
      }
    }
    last_ = cur;
  }
  void Terminate() {
    int st = last_;
    while (st > 0) {
      st_[st].terminate = true;
      st = st_[st].link_;
    }
  }
  void CountToTerminateMain() {
    dp_.resize(size_, 0);
    CountToTerminate(0);
  }
  int CountToTerminate(size_t index) {
    if (dp_[index] > 0) {
      return dp_[index];
    }
    int count_path = 0;
    if (st_[index].terminate) {
      count_path = 1;
    }
    for (auto& i : st_[index].next_) {
      count_path += CountToTerminate(i.second);
    }
    dp_[index] = count_path;
    return count_path;
  }
  void FindRefrenAndPrint(const std::string& str) {
    int max_refren = 0;
    int max_st = 0;
    for (size_t i = 1; i < dp_.size(); i++) {
      int tmp = max_refren;
      max_refren = std::max(max_refren, static_cast<int>(st_[i].len_ * dp_[i]));
      if (tmp < max_refren) {
        max_st = i;
      }
    }
    std::cout << max_refren << "\n" << st_[max_st].len_ << "\n";
    for (int i = static_cast<int>(st_[max_st].last_index - st_[max_st].len_) + 1; i < st_[max_st].last_index + 1; i++) {
      std::cout << str[i] - '0' + 1 << " ";
    }
  }

 private:
  struct State {
    size_t len_ = 0;
    int link_ = -1;
    int last_index;
    bool terminate = false;
    std::map<char, int> next_;
  };
  int last_ = -1;
  size_t size_ = 1;
  std::vector<State> st_;
  std::vector<int> dp_;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  size_t n = 0;
  int m = 0;
  int value = 0;
  std::string str;
  std::cin >> n >> m;
  for (size_t i = 0; i < n; ++i) {
    std::cin >> value;
    str += ((value - 1) + '0');
  }
  SuffixAutomat automat(str);
  automat.Terminate();
  automat.CountToTerminateMain();
  automat.FindRefrenAndPrint(str);
  return 0;
}