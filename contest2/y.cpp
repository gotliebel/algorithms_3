/*#include <iostream>
#include <vector>

class Graph {
 public:
  explicit Graph(const int& size) : list_adjency_(size) {};
  void AddEdge(const int& begin, const int& end, const int& sum) {
    list_adjency_[begin].emplace_back(end, sum);
    list_adjency_[end].emplace_back(begin, sum);
  }
  void FindBaseGraph() {
    recover_[0] = {0, 1};
    colors_.resize(list_adjency_.size(), WHITE);
    Dfs(0);
    auto max = FindMaxElement();

  }
 private:
  std::pair<int, int> FindMaxElement() {
    int minus_max = -20000000;
    int plus_max = -20000000;
    for (int i = 0; i < list_adjency_.size(); i++) {
      if (recover_[i].second == 1) {
        plus_max = std::max(plus_max, recover_[i].first);
      } else {
        minus_max = std::max(minus_max, recover_[i].first);
      }
    }
    return {plus_max, minus_max};
  }
  void Dfs(const int& vertex) {
    colors_[vertex] = GRAY;
    for (auto& i : list_adjency_[vertex]) {
      if (colors_[i.first] == WHITE) {
        recover_[i.first] = {i.second - recover_[i.first].first, -recover_[i.first].second};
        Dfs(i.first);
      }
    }
    colors_[vertex] = BLACK;
  }
  enum Color { WHITE, GRAY, BLACK};
  std::vector<std::pair<int, int>> recover_;
  std::vector<int> permutation_;
  std::vector<Color> colors_;
  std::vector<std::vector<std::pair<int, int>>> list_adjency_;
};
int main() {
  int n, m;
  std::cin >> n >> m;
  int begin, end, sum;
  Graph graph(n);
  for (int i = 0; i < m; i++) {
    std::cin >> begin >> end >> sum;
    graph.AddEdge(begin, end, sum);
  }
  graph.FindBaseGraph();
}*/