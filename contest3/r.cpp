/*#include <iostream>
#include <vector>

class Graph {
 public:
  Graph(int, int);
  void AddEdge(int, int, int, int);
  std::vector<int> FordBellman(int);

 private:
  struct Edge {
    int from;
    int departure_time;
    int to;
    int arrival_time;
  };
  bool Relax(const Edge&);
  const int k_max_dist_ = 1e9;
  const int k_number_vertices_;
  std::vector<int> dist_;
  std::vector<int> prev_;
  std::vector<Edge> edges_;
};

int main() {
  int n = 0;
  int start_point = 0, finish_point = 0;
  std::cin >> n;
  std::cin >> start_point >> finish_point;
  start_point--;
  finish_point--;
  int k = 0;
  std::cin >> k;
  Graph graph(n, k);
  int from = 0, departure_time = 0, to = 0, arrival_time = 0;
  for (int i = 0; i < k; i++) {
    std::cin >> from >> departure_time >> to >> arrival_time;
    from--;
    to--;
    graph.AddEdge(from, departure_time, to, arrival_time);
  }
  std::vector<int> time = graph.FordBellman(start_point);
  std::cout << time[finish_point];
  return 0;
}

Graph::Graph(int number_vertices, int number_edges) : k_number_vertices_(number_vertices), edges_(number_edges) {
}
void Graph::AddEdge(int from, int departure_time, int to, int arrival_time) {
  edges_.push_back({from, departure_time, to, arrival_time});
}
std::vector<int> Graph::FordBellman(int start) {
  dist_.resize(k_number_vertices_, k_max_dist_);
  prev_.resize(k_number_vertices_, -1);
  dist_[start] = 0;
  bool has_relaxed = false;
  while (true) {
    has_relaxed = false;
    for (auto& edge : edges_) {
      if (Relax(edge)) {
        has_relaxed = true;
      }
    }
    if (!has_relaxed) {
      break;
    }
  }
  return dist_;
}
bool Graph::Relax(const Edge& edge) {
  if (dist_[edge.from] <= edge.departure_time && dist_[edge.to] > edge.arrival_time) {
    dist_[edge.to] = edge.arrival_time;
    return true;
  }
  return false;
}*/