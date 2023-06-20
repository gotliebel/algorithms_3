/*#include <iostream>
#include <set>
#include <vector>

struct Vertex {
  int id;
  int dist;
};
struct CompareVertex {
  bool operator()(const Vertex& from, const Vertex& to) const {
    if (from.dist < to.dist) {
      return true;
    }
    if (from.dist == to.dist) {
      return from.id < to.id;
    }
    return false;
  }
};
class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int, int);
  int FindMinimumSpanningTreePrim();

 private:
  struct Dest {
    int to;
    int weight;
  };

  const int k_inf_ = static_cast<int>(3e9);
  std::vector<std::vector<Dest>> list_adjacency_;
  int size_;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n = 0;
  std::cin >> n;
  int weight = 0;
  Graph graph(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> weight;
      graph.AddEdge(i, j, weight);
    }
  }
  for (int i = 0; i < n; i++) {
    std::cin >> weight;
    graph.AddEdge(n, i, weight);
    graph.AddEdge(i, n, weight);
  }
  int final_weight = graph.FindMinimumSpanningTreePrim();
  std::cout << final_weight;
  return 0;
}

Graph::Graph(int size) : list_adjacency_(size + 1), size_(size + 1) {
}
void Graph::AddEdge(int from, int to, int weight) {
  list_adjacency_[from].push_back({to, weight});
}
int Graph::FindMinimumSpanningTreePrim() {
  std::vector<int> dist(list_adjacency_.size(), k_inf_);
  std::vector<int> prev(list_adjacency_.size(), -1);
  dist[0] = 0;
  std::set<Vertex, CompareVertex> min_dist;
  for (int i = 0; i < size_; i++) {
    min_dist.insert({i, dist[i]});
  }
  int final_weight = 0;
  while (!min_dist.empty()) {
    auto vertex = *min_dist.begin();
    min_dist.erase(vertex);
    if (prev[vertex.id] != -1) {
      final_weight += vertex.dist;
    }
    for (auto& edge : list_adjacency_[vertex.id]) {
      if (min_dist.find({edge.to, dist[edge.to]}) != min_dist.end() && dist[edge.to] > edge.weight) {
        prev[edge.to] = vertex.id;
        min_dist.erase({edge.to, dist[edge.to]});
        dist[edge.to] = edge.weight;
        min_dist.insert({edge.to, dist[edge.to]});
      }
    }
  }
  return final_weight;
}*/