/*#include <iostream>
#include <vector>

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int);
  bool IsDividedIntoTwoGroups();

 private:
  enum class Color { WHITE, BLACK, GRAY, BLUE, RED };
  struct VertexColor {
    Color color_for_dfs;
    Color color_for_graph;
  };
  bool Check();
  void Dfs(const size_t&, Color);

  std::vector<VertexColor> colors_;
  std::vector<std::vector<int>> list_adjacency_;
};

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  int from = 0;
  int to = 0;
  Graph graph(n);
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to;
    from--;
    to--;
    graph.AddEdge(from, to);
  }
  if (graph.IsDividedIntoTwoGroups()) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}

Graph::Graph(int size) : list_adjacency_(size) {}
void Graph::AddEdge(int from, int to) {
  list_adjacency_[from].push_back(to);
  list_adjacency_[to].push_back(from);
}
bool Graph::IsDividedIntoTwoGroups() {
  colors_.resize(list_adjacency_.size());
  for (auto& color : colors_) {
    color.color_for_dfs = Color::WHITE;
    color.color_for_graph = Color::BLUE;
  }
  for (size_t i = 0; i < list_adjacency_.size(); i++) {
    if (colors_[i].color_for_dfs == Color::WHITE) {
      Dfs(i, Color::BLUE);
    }
  }
  return Check();
}
bool Graph::Check() {
  for (size_t i = 0; i < list_adjacency_.size(); i++) {
    for (size_t j = 0; j < list_adjacency_[i].size(); j++) {
      if (colors_[i].color_for_graph == colors_[list_adjacency_[i][j]].color_for_graph) {
        return false;
      }
    }
  }
  return true;
}
void Graph::Dfs(const size_t& vertex, Color previous_color) {
  if (previous_color == Color::BLUE) {
    colors_[vertex] = {Color::GRAY, Color::RED};
  } else {
    colors_[vertex] = {Color::GRAY, Color::BLUE};
  }
  for (auto& edge : list_adjacency_[vertex]) {
    if (colors_[edge].color_for_dfs == Color::WHITE) {
      if (colors_[vertex].color_for_graph == Color::BLUE) {
        Dfs(edge, Color::BLUE);
      } else {
        Dfs(edge, Color::RED);
      }
    }
  }
  colors_[vertex].color_for_dfs = Color::BLACK;
}*/