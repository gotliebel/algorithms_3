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
        st_[q].link_ = st_[cur].link_ = copy;
        for (; p != -1 && st_[p].next_[symb] == q; p = st_[p].link_) {
          st_[p].next_[symb] = copy;
        }
      }
    }
    last_ = cur;
  }
  void CountMain() {
    dp_.resize(size_);
    Count(0);
  }
  size_t Count(size_t index) {
    if (dp_[index] > 0) {
      return dp_[index];
    }
    size_t count_path = 1;
    for (auto &i : st_[index].next_) {
      count_path += Count(i.second);
    }
    dp_[index] = count_path;
    return count_path;
  }
  void KthString(std::string& string, int index, int& k) {
    if (k <= 0) {
      return;
    }
    for (auto& i : st_[index].next_) {
      if (dp_[i.second] < k) {
        k -= dp_[i.second];
      } else {
        k--;
        string += i.first;
        KthString(string, i.second, k);
        break;
      }
    }
  }
 private:
  struct State {
    size_t len_ = 0;
    int link_ = -1;
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
  std::string string;
  std::cin >> string;
  int k = 0;
  std::cin >> k;
  SuffixAutomat automat(string);
  automat.CountMain();
  std::string answer;
  automat.KthString(answer, 0, k);
  for (auto& i : answer) {
    std::cout << i;
  }
  return 0;
}*/