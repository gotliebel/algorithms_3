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
  struct Edge {
    int vertex_;
    int weight_;
  };

  const int k_inf_ = static_cast<int>(3e9);
  std::vector<std::vector<Edge>> list_adjacency_;
  int size_;
};

int main() {
  int n = 0, m = 0;
  std::cin >> n >> m;
  int from = 0, to = 0, weight = 0;
  Graph graph(n);
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to >> weight;
    from--;
    to--;
    graph.AddEdge(from, to, weight);
  }
  int final_weight = graph.FindMinimumSpanningTreePrim();
  std::cout << final_weight;
  return 0;
}

Graph::Graph(int size) : list_adjacency_(size), size_(size) {
}
void Graph::AddEdge(int from, int to, int weight) {
  list_adjacency_[from].push_back({to, weight});
  list_adjacency_[to].push_back({from, weight});
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
      if (min_dist.find({edge.vertex_, dist[edge.vertex_]}) != min_dist.end() && dist[edge.vertex_] > edge.weight_) {
        prev[edge.vertex_] = vertex.id;
        min_dist.erase({edge.vertex_, dist[edge.vertex_]});
        dist[edge.vertex_] = edge.weight_;
        min_dist.insert({edge.vertex_, dist[edge.vertex_]});
      }
    }
  }
  return final_weight;
}*/