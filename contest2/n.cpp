#include <iostream>
#include <vector>
struct VertexInComponent {
  int vertex;
  int index;
};
class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int);
  std::vector<int> Kosaraju();

 private:
  enum class Color { GRAY, WHITE };
  std::vector<int> DfsInit();
  void Dfs(int, int);
  void Transpose();
  void TopSort();
  void TopSortDfs(int);

  std::vector<VertexInComponent> component_;
  std::vector<int> top_sorted_;
  std::vector<Color> colors_;
  std::vector<std::vector<int>> list_adjacency_;
  int size_;
};

int main() {
  int n = 0, m = 0;
  std::cin >> n >> m;
  Graph graph(n);
  int from = 0, to = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to;
    from--;
    to--;
    graph.AddEdge(from, to);
  }
  std::vector<int> vertices_in_components = graph.Kosaraju();
  auto size_components = static_cast<int>(vertices_in_components.size());
  std::cout << vertices_in_components[vertices_in_components.size() - 1] + 1 << '\n';
  for (int i = 0; i < size_components - 1; i++) {
    std::cout << vertices_in_components[i] + 1 << ' ';
  }
  return 0;
}

Graph::Graph(int size) : list_adjacency_(size), size_(size) {
}
void Graph::AddEdge(int from, int to) {
  list_adjacency_[from].push_back(to);
}
std::vector<int> Graph::Kosaraju() {
  TopSort();
  Transpose();
  return DfsInit();
}

std::vector<int> Graph::DfsInit() {
  for (auto& color : colors_) {
    color = Color::WHITE;
  }
  int counter = -1;
  for (auto& i : top_sorted_) {
    if (colors_[i] == Color::WHITE) {
      Dfs(i, counter);
      counter++;
    }
  }
  std::vector<int> vertices_in_components(top_sorted_.size());
  for (size_t i = 0; i < top_sorted_.size(); i++) {
    vertices_in_components[component_[i].vertex] = component_[i].index + 1;
  }
  vertices_in_components.push_back(counter);
  return vertices_in_components;
}
void Graph::Dfs(int vertex, int index) {
  colors_[vertex] = Color::GRAY;
  component_.push_back({vertex, index});
  for (auto& i : list_adjacency_[vertex]) {
    if (colors_[i] == Color::WHITE) {
      Dfs(i, index);
    }
  }
}
void Graph::Transpose() {
  std::vector<std::vector<int>> vector(list_adjacency_.size());
  for (int i = 0; i < size_; i++) {
    auto size = static_cast<int>(list_adjacency_[i].size());
    for (int j = 0; j < size; j++) {
      vector[list_adjacency_[i][j]].push_back(i);
    }
  }
  list_adjacency_ = vector;
  for (int i = 0; i < size_ / 2; i++) {
    int tmp = top_sorted_[i];
    top_sorted_[i] = top_sorted_[top_sorted_.size() - i - 1];
    top_sorted_[top_sorted_.size() - i - 1] = tmp;
  }
}
void Graph::TopSort() {
  colors_.resize(list_adjacency_.size(), Color::WHITE);
  for (int i = 0; i < size_; i++) {
    if (colors_[i] == Color::WHITE) {
      TopSortDfs(i);
    }
  }
}
void Graph::TopSortDfs(int vertex) {
  colors_[vertex] = Color::GRAY;
  for (auto& to : list_adjacency_[vertex]) {
    if (colors_[to] == Color::WHITE) {
      TopSortDfs(to);
    }
  }
  top_sorted_.push_back(vertex);
}