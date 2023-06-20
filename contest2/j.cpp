#include <iostream>
#include <vector>

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int);
  int CountCycles();

 private:
  enum class Color { WHITE, BLACK, GRAY };
  void CountDfs(int);
  int counter_ = 0;
  std::vector<Color> colors_;
  std::vector<std::vector<int>> list_adjacency_;
  int size_;
};

int main() {
  int n = 0;
  std::cin >> n;
  Graph graph(n);
  int piggy_bank;
  for (int i = 0; i < n; i++) {
    std::cin >> piggy_bank;
    piggy_bank--;
    graph.AddEdge(piggy_bank, i);
  }
  std::cout << graph.CountCycles();
  return 0;
}
Graph::Graph(int size) : list_adjacency_(size), size_(size) {
}
void Graph::AddEdge(int from, int to) {
  list_adjacency_[from].push_back(to);
}
int Graph::CountCycles() {
  colors_.resize(list_adjacency_.size());
  for (size_t i = 0; i < list_adjacency_.size(); i++) {
    colors_[i] = Color::WHITE;
  }
  for (int i = 0; i < size_; i++) {
    if (colors_[i] == Color::WHITE) {
      CountDfs(i);
    }
  }
  return counter_;
}
void Graph::CountDfs(int vertex) {
  colors_[vertex] = Color::GRAY;
  for (auto& to : list_adjacency_[vertex]) {
    if (colors_[to] == Color::WHITE) {
      CountDfs(to);
    } else if (colors_[to] == Color::GRAY) {
      counter_++;
    }
  }
  colors_[vertex] = Color::BLACK;
}