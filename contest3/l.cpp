/*#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

struct Vertex {
  int id;
  int dist;
};
struct Dest {
  int to;
  int weight;
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
  int Johnson();

 private:
  struct Edge {
    int from;
    int to;
    int weight;
  };
  void Dijkstra(int, std::vector<int>&);
  void FordBellman();
  const int k_max_potential_ = 2009000999;
  const int k_number_vertices_;
  std::vector<std::vector<Dest>> adjacency_list_;
  std::vector<int> potential_;
  std::vector<Edge> edges_;
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0, m = 0;
  std::cin >> n >> m;
  Graph graph(n);
  int from = 0, to = 0, weight = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to >> weight;
    graph.AddEdge(from, to, weight);
  }
  int max_distance = graph.Johnson();
  std::cout << max_distance;
  return 0;
}
Graph::Graph(int number_vertices)
    : k_number_vertices_(number_vertices)
    , adjacency_list_(number_vertices)
    , potential_(k_number_vertices_ + 1, k_max_potential_) {
}
void Graph::AddEdge(int from, int to, int weight) {
  edges_.push_back({from, to, weight});
}
int Graph::Johnson() {
  size_t previous_edges_size = edges_.size();
  for (int i = 0; i < k_number_vertices_; i++) {
    edges_.push_back({k_number_vertices_, i, 0});
  }
  FordBellman();
  for (size_t i = 0; i < previous_edges_size; i++) {
    auto edge = edges_[i];
    adjacency_list_[edge.from].push_back({edge.to, edge.weight + potential_[edge.from] - potential_[edge.to]});
  }
  std::vector<int> dist(adjacency_list_.size(), k_max_potential_);
  int max_dist = -1;
  for (int i = 0; i < k_number_vertices_; i++) {
    if (adjacency_list_[i].empty()) {
      continue;
    }
    Dijkstra(i, dist);
    int max_cur_element = -1;
    size_t max_index = 0;
    for (size_t j = 0; j < dist.size(); j++) {
      if (dist[j] != k_max_potential_ && max_cur_element < dist[j]) {
        max_cur_element = dist[j];
        max_index = j;
      }
      dist[j] = k_max_potential_;
    }
    max_dist = std::max(max_dist, max_cur_element + potential_[max_index] - potential_[i]);
  }
  return max_dist;
}
void Graph::FordBellman() {
  potential_[k_number_vertices_] = 0;
  for (int i = 0; i < k_number_vertices_ - 1; i++) {
    for (auto& edge : edges_) {
      if (potential_[edge.to] > potential_[edge.from] + edge.weight) {
        potential_[edge.to] = potential_[edge.from] + edge.weight;
      }
    }
  }
}
void Graph::Dijkstra(int begin, std::vector<int>& dist) {
  dist[begin] = 0;
  std::set<Vertex, CompareVertex> min_dist;
  for (int i = 0; i < k_number_vertices_; i++) {
    min_dist.insert({i, dist[i]});
  }
  while (!min_dist.empty()) {
    auto min_vertex = *min_dist.begin();
    min_dist.erase(min_dist.begin());
    for (auto& dest : adjacency_list_[min_vertex.id]) {
      if ((min_dist.count({dest.to, dist[dest.to]}) > 0) && dist[dest.to] > dist[min_vertex.id] + dest.weight) {
        min_dist.erase({dest.to, dist[dest.to]});
        dist[dest.to] = dist[min_vertex.id] + dest.weight;
        min_dist.insert({dest.to, dist[dest.to]});
      }
    }
  }
}*/