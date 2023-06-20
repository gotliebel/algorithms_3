/*#include <algorithm>
#include <iostream>
#include <vector>

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int, int);
  bool FordBellman(int);
  std::vector<int> GetCycle();

 private:
  struct Edge {
    int from;
    int to;
    int weight;
  };
  bool Relax(const Edge&, std::vector<int>&);
  const int k_max_dist_ = 1000000;
  const int k_number_vertices_;
  int begin_cycle_ = -1;
  std::vector<int> prev_;
  std::vector<Edge> edges_;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0;
  std::cin >> n;
  size_t cl = clock();
  int weight = 0;
  Graph graph(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> weight;
      if (weight != 100000) {
        graph.AddEdge(i, j, weight);
      }
    }
  }
  bool has_negative_cycle = graph.FordBellman(0);
  if (has_negative_cycle) {
    std::cout << "YES\n";
    std::vector<int> cycle = graph.GetCycle();
    std::cout << cycle.size() << '\n';
    for (auto iterator = cycle.end() - 1; iterator != cycle.begin(); iterator--) {
      std::cout << *iterator + 1 << ' ';
    }
    std::cout << *(cycle.end() - 1) + 1;
  } else {
    std::cout << "NO";
  }
  std::cout << ' ' << clock() - cl;
  return 0;
}

Graph::Graph(int number_vertices) : k_number_vertices_(number_vertices) {
}
void Graph::AddEdge(int from, int to, int weight) {
  edges_.push_back({from, to, weight});
}
std::vector<int> Graph::GetCycle() {
  std::vector<int> cycle;
  int cur = -1;
  for (int i = 0; i < k_number_vertices_; i++) {
    begin_cycle_ = prev_[begin_cycle_];
  }
  cycle.push_back(begin_cycle_);
  cur = prev_[begin_cycle_];
  while (cur != begin_cycle_) {
    cycle.push_back(cur);
    cur = prev_[cur];
  }
  cycle.push_back(begin_cycle_);
  return cycle;
}
bool Graph::FordBellman(int start) {
  std::vector<int> dist(k_number_vertices_, k_max_dist_);
  prev_.resize(k_number_vertices_, -1);
  dist[start] = 0;
  for (int i = 0; i < k_number_vertices_; i++) {
    for (auto& edge : edges_) {
      Relax(edge, dist);
    }
  }
  bool has_negative_cycle = false;
  for (auto& edge : edges_) {
    if (Relax(edge, dist)) {
      has_negative_cycle = true;
    }
  }
  return has_negative_cycle;
}
bool Graph::Relax(const Edge& edge, std::vector<int>& dist) {
  if (dist[edge.to] > dist[edge.from] + edge.weight) {
    dist[edge.to] = dist[edge.from] + edge.weight;
    prev_[edge.to] = edge.from;
    begin_cycle_ = edge.to;
    return true;
  }
  return false;
}*/