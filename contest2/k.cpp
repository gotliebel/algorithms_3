#include <iostream>
#include <vector>

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int);
  std::vector<std::vector<int>> Chatics();
  
 private:
  enum class Color { WHITE, BLACK, GRAY };
  void Dfs(int, int);

  std::vector<Color> colors_;
  std::vector<std::vector<int>> components_;
  std::vector<std::vector<int>> list_adjacency_;
  int size_;
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
  std::vector<std::vector<int>> components = graph.Chatics();
  std::cout << components.size();
  for (auto& component : components) {
    std::cout << '\n' << component.size() << '\n';
    for (int element : component) {
      std::cout << element + 1 << ' ';
    }
  }
  return 0;
}

Graph::Graph(int size) : list_adjacency_(size), size_(size) {
}
void Graph::AddEdge(int from, int to) {
  list_adjacency_[from].push_back(to);
  list_adjacency_[to].push_back(from);
}
std::vector<std::vector<int>> Graph::Chatics() {
  colors_.resize(list_adjacency_.size(), Color::WHITE);
  int counter = 0;
  for (int i = 0; i < size_; i++) {
    if (colors_[i] == Color::WHITE) {
      components_.resize(counter + 1);
      Dfs(i, counter);
      counter++;
    }
  }
  return components_;
}

void Graph::Dfs(int vertex, int index) {
  colors_[vertex] = Color::GRAY;
  for (auto& to : list_adjacency_[vertex]) {
    if (colors_[to] == Color::WHITE) {
      Dfs(to, index);
    }
  }
  components_[index].push_back(vertex);
  colors_[vertex] = Color::BLACK;
}