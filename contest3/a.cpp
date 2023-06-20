/*#include <iostream>
#include <vector>

class Graph {
 public:
  explicit Graph(int);
  bool AddEdge(int, int);
 private:
  void MakeSet(int);
  int FindSet(int);
  void Union(int, int);

  std::vector<int> parent_;
  std::vector<int> rank_;
  int size_;
};

int main() {
  int n = 0, m = 0;
  std::cin >> n >> m;
  Graph graph(n);
  int from = 0, to = 0;
  int min_edges = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to;
    if (graph.AddEdge(from, to)) {
      min_edges = i + 1;
      break;
    }
  }
  std::cout << min_edges;
}
Graph::Graph(int n) : parent_(n), rank_(n), size_(n) {
  for (int i = 0; i < n; i++) {
    MakeSet(i);
  }
}
bool Graph::AddEdge(int from, int to) {
  Union(from, to);
  int number_component = FindSet(0);
  for (int i = 1; i < size_; i++) {
    if (number_component != FindSet(i)) {
      return false;
    }
  }
  return true;
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
void Graph::Union(int x, int y) {
  x = FindSet(x);
  y = FindSet(y);
  if (rank_[x] < rank_[y]) {
    parent_[x] = y;
  } else if (rank_[y] < rank_[x]) {
    parent_[y] = x;
  } else {
    parent_[x] = y;
    rank_[y] += 1;
  }
}*/
