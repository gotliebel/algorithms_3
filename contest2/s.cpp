#include <iostream>
#include <vector>

struct EulerCycle {
  int euler_start;
  int count_edges;

};
class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int);
  std::vector<int> FindWay();

 private:
  enum class Color { WHITE, BLACK, GRAY };
  EulerCycle IsEulerGraph();
  void Euler(int);
  void Dfs(int);
  
  std::vector<Color> colors_;
  std::vector<int> go_;
  std::vector<int> cycle_;
  std::vector<std::vector<int>> list_adjacency_;
  int size_;
};

int main() {
  int n = 0, m = 0;
  std::cin >> n >> m;
  Graph graph(m);
  int k = 0;
  int from = 0, to = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> k;
    std::cin >> from >> to;
    from--;
    to--;
    graph.AddEdge(from, to);
    from = to;
    for (int j = 0; j < k - 1; j++) {
      std::cin >> to;
      to--;
      graph.AddEdge(from, to);
      from = to;
    }
  }
  std::vector<int> cycle = graph.FindWay();
  if (cycle.size() == 1) {
    std::cout << 0;
  } else {
    std::cout << cycle.size() << ' ';
    for (auto& element : cycle) {
      std::cout << element + 1 << ' ';
    }
  }
  return 0;
}

Graph::Graph(int size) : list_adjacency_(size), size_(size) {
}
void Graph::AddEdge(int from, int to) {
  list_adjacency_[from].push_back(to);
}
std::vector<int> Graph::FindWay() {
  EulerCycle is_euler = IsEulerGraph();
  int euler_start = is_euler.euler_start;
  int count_edges = is_euler.count_edges;
  if (euler_start != -1) {
    go_.resize(list_adjacency_.size());
    Euler(euler_start);
    if (count_edges + 1 == (int)cycle_.size()) {
      return cycle_;
    }
    return {0};
  }
  return {0};
}

EulerCycle Graph::IsEulerGraph() {
  colors_.resize(list_adjacency_.size(), Color::WHITE);
  for (int i = 0; i < size_; i++) {
    if (!list_adjacency_[i].empty()) {
      Dfs(i);
    }
  }
  int euler_start = -1;
  for (int i = 0; i < size_; ++i) {
    if (!list_adjacency_[i].empty()) {
      if (colors_[i] == Color::WHITE) {
        return {-1, -1};
      }
      if (euler_start == -1) {
        euler_start = i;
      }
    }
  }
  int count_edges = 0;
  for (auto& degree_vertex : list_adjacency_) {
    count_edges += (int)degree_vertex.size();
  }
  return {euler_start, count_edges};
}
void Graph::Euler(int vertex) {
  auto size = static_cast<int>(list_adjacency_[vertex].size());
  while (go_[vertex] != size) {
    Euler(list_adjacency_[vertex][go_[vertex]++]);
  }
  cycle_.push_back(vertex);
}
void Graph::Dfs(int vertex) {
  colors_[vertex] = Color::GRAY;
  for (auto& to : list_adjacency_[vertex]) {
    if (colors_[to] == Color::WHITE) {
      Dfs(to);
    }
  }
  colors_[vertex] = Color::BLACK;
}