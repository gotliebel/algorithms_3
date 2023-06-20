/*#include <iostream>
#include <vector>

class Graph {
 public:
  Graph(int, int);
  void AddEdge(int, int, int);
  int FindMinimumSpanningTreeKruskal();

 private:
  struct Edge {
    int from;
    int to;
    int weight_;
  };
  void MakeSet(int);
  int FindSet(int);
  void Union(int, int);

  std::vector<int> parent_;
  std::vector<int> rank_;
  std::vector<Edge> edges_;
  int size_;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n = 0, m = 0;
  std::cin >> n >> m;
  int from = 0, to = 0, weight = 0;
  Graph graph(n, m);
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to >> weight;
    from--;
    to--;
    graph.AddEdge(from, to, weight);
  }
  int final_weight = graph.FindMinimumSpanningTreeKruskal();
  std::cout << final_weight;
  return 0;
}

Graph::Graph(int number_vertices, int number_edges)
    : parent_(number_vertices), rank_(number_vertices), edges_(number_edges), size_(number_vertices) {}
void Graph::AddEdge(int from, int to, int weight) {
  edges_.push_back({from, to, weight});
}
int Graph::FindMinimumSpanningTreeKruskal() {
  int final_weight = 0;
  for (int i = 0; i < size_; i++) {
    MakeSet(i);
  }
  for (auto& edge : edges_) {
    if (FindSet(edge.from) != FindSet(edge.to)) {
      final_weight += edge.weight_;
      Union(edge.from, edge.to);
    }
  }
  return final_weight;
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