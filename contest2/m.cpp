#include <iostream>
#include <vector>

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(size_t, size_t);
  bool HasNoCycle();

 private:
  enum class Color { GRAY, WHITE, BLACK};
  bool HasCycleDfs(size_t);

  std::vector<Color> colors_;
  std::vector<std::vector<size_t>> list_adjacency_;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n = 0;
  std::cin >> n;
  std::string input;
  Graph graph(n);
  for (int i = 0; i < n - 1; i++) {
    std::cin >> input;
    for (size_t j = 0; j < input.size(); j++) {
      if (input[j] == 'R') {
        graph.AddEdge(i, j + i + 1);
      } else {
        graph.AddEdge(j + i + 1, i);
      }
    }
  }
  if (graph.HasNoCycle()) {
    std::cout << "NO";
  } else {
    std::cout << "YES";
  }
}
Graph::Graph(int size) : list_adjacency_(size) {
}
void Graph::AddEdge(size_t from, size_t to) {
  list_adjacency_[from].push_back(to);
}
bool Graph::HasNoCycle() {
  colors_.resize(list_adjacency_.size());
  for (size_t i = 0; i < list_adjacency_.size(); i++) {
    colors_[i] = Color::WHITE;
  }
  for (size_t i = 0; i < list_adjacency_.size(); i++) {
    if (colors_[i] == Color::WHITE) {
      if (HasCycleDfs(i)) {
        return true;
      }
    }
  }
  return false;
}
bool Graph::HasCycleDfs(size_t vertex) {
  colors_[vertex] = Color::GRAY;
  for (auto& to : list_adjacency_[vertex]) {
    if (colors_[to] == Color::WHITE) {
      if (HasCycleDfs(to)) {
        return true;
      }
    } else if (colors_[to] == Color::GRAY) {
      return true;
    }
  }
  colors_[vertex] = Color::BLACK;
  return false;
}