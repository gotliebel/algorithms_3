/*#include <iostream>
#include <vector>

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int, int);
  int Query(int);
 private:
  void MakeSet(int);
  int FindSet(int);
  void Union(int, int, int);

  std::vector<int> parent_;
  std::vector<int> rank_;
  std::vector<int> weight_component_;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n = 0, m = 0;
  std::cin >> n >> m;
  Graph graph(n);
  int operation = 0;
  int from = 0, to = 0;
  int weight = 0;
  int vertex = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> operation;
    if (operation == 2) {
      std::cin >> vertex;
      vertex--;
      std::cout << graph.Query(vertex) << '\n';
    } else {
      std::cin >> from >> to >> weight;
      from--;
      to--;
      graph.AddEdge(from, to, weight);
    }
  }
  return 0;
}
Graph::Graph(int n) : parent_(n), rank_(n), weight_component_(n, 0) {
  for (int i = 0; i < n; i++) {
    MakeSet(i);
  }
}
void Graph::AddEdge(int from, int to, int weight) {
  int component_from = FindSet(from);
  int component_to = FindSet(to);
  if (component_from == component_to) {
    weight_component_[component_from] += weight;
  } else {
    Union(from, to, weight);
  }
}
int Graph::Query(int vertex) {
  return weight_component_[FindSet(vertex)];
}
void Graph::MakeSet(int x) {
  parent_[x] = x;
  rank_[x] = 0;
}
int Graph::FindSet(int x) {
  if (x == parent_[x]) {
    return x;
  }
  return parent_[x] = FindSet(parent_[x]);
}
void Graph::Union(int x, int y, int weight) {
  x = FindSet(x);
  y = FindSet(y);
  if (rank_[x] < rank_[y]) {
    parent_[x] = y;
    weight_component_[y] += weight + weight_component_[x];
  } else if (rank_[y] < rank_[x]) {
    parent_[y] = x;
    weight_component_[x] += weight + weight_component_[y];
  } else {
    parent_[x] = y;
    weight_component_[y] += weight + weight_component_[x];
    rank_[y] += 1;
  }
}*/