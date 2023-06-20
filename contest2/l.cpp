#include <algorithm>
#include <iostream>
#include <vector>

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int);
  bool TopSort();
  std::vector<size_t> GetTopSorted();
 private:
  enum class Color { GRAY, WHITE, BLACK };
  bool TopSortDfs(size_t);

  std::vector<size_t> top_sorted_;
  std::vector<Color> colors_;
  std::vector<std::vector<int>> list_adjacency_;
};

int main() {
  int n, m;
  std::cin >> n >> m;
  Graph graph(n);
  int from, to;
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to;
    from--;
    to--;
    graph.AddEdge(from, to);
  }
  if (graph.TopSort()) {
    std::vector<size_t> top_sorted = graph.GetTopSorted();
    std::reverse(top_sorted.begin(), top_sorted.end());
    for (auto vertex : top_sorted) {
      std::cout << vertex + 1 << ' ';
    }
  } else {
    std::cout << -1;
  }
}
Graph::Graph(int size) : list_adjacency_(size) {
}
void Graph::AddEdge(int from, int to) {
  list_adjacency_[from].push_back(to);
}
bool Graph::TopSort() {
  colors_.resize(list_adjacency_.size(), Color::WHITE);
  for (size_t i = 0; i < list_adjacency_.size(); i++) {
    if (colors_[i] == Color::WHITE) {
      if (!TopSortDfs(i)) {
        return false;
      }
    }
  }
  return true;
}
std::vector<size_t> Graph::GetTopSorted() {
  return top_sorted_;
}
bool Graph::TopSortDfs(size_t vertex) {
  colors_[vertex] = Color::GRAY;
  for (auto& to : list_adjacency_[vertex]) {
    if (colors_[to] == Color::GRAY) {
      return false;
    }
    if (colors_[to] == Color::WHITE) {
      if (!TopSortDfs(to)) {
        return false;
      }
    }
  }
  colors_[vertex] = Color::BLACK;
  top_sorted_.push_back(vertex);
  return true;
}