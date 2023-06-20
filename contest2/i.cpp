#include <algorithm>
#include <iostream>
#include <vector>

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int);
  std::vector<int> FindCycle();

 private:
  enum class Color { WHITE, BLACK, GRAY };
  bool HasCycle();
  bool HasCycleDfs(const int& vertex);

  int begin_cycle_;
  int end_cycle_;
  std::vector<int> parent_;
  std::vector<Color> colors_;
  std::vector<std::vector<int>> list_adjacency_;
  int size_;
};

int main() {
  int n = 0;
  int m = 0;
  int begin = 0, end = 0;
  std::cin >> n >> m;
  Graph graph(n);
  for (int i = 0; i < m; i++) {
    std::cin >> begin >> end;
    begin--;
    end--;
    graph.AddEdge(begin, end);
  }
  std::vector<int> cycle = graph.FindCycle();
  if (cycle.empty()) {
    std::cout << "NO";
  } else {
    std::cout << "YES\n";
    std::reverse(cycle.begin(), cycle.end());
    for (auto vertex : cycle) {
      std::cout << vertex + 1 << ' ';
    }
  }
  return 0;
}

Graph::Graph(int size) : list_adjacency_(size), size_(size) {
}
void Graph::AddEdge(int from, int to) {
  list_adjacency_[from].push_back(to);
}

std::vector<int> Graph::FindCycle() {
  std::vector<int> cycle;
  if (HasCycle()) {
    for (int i = end_cycle_; i != begin_cycle_; i = parent_[i]) {
      cycle.push_back(i);
    }
    cycle.push_back(begin_cycle_);
    return cycle;
  }
  return cycle;
}

bool Graph::HasCycle() {
  colors_.resize(list_adjacency_.size());
  parent_.resize(list_adjacency_.size(), -1);
  for (size_t i = 0; i < list_adjacency_.size(); i++) {
    colors_[i] = Color::WHITE;
  }
  for (int i = 0; i < size_; i++) {
    if (colors_[i] == Color::WHITE) {
      if (HasCycleDfs(i)) {
        return true;
      }
    }
  }
  return false;
}
bool Graph::HasCycleDfs(const int& vertex) {
  colors_[vertex] = Color::GRAY;
  for (auto& to : list_adjacency_[vertex]) {
    if (colors_[to] == Color::WHITE) {
      parent_[to] = vertex;
      if (HasCycleDfs(to)) {
        return true;
      }
    } else if (colors_[to] == Color::GRAY) {
      begin_cycle_ = to;
      end_cycle_ = vertex;
      return true;
    }
  }
  colors_[vertex] = Color::BLACK;
  return false;
}