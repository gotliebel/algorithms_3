/*#include <iostream>
#include <vector>

struct Edge {
  int to;
  int flow = 0;
  int capacity;
};
class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int, int);
  int FordFulkerson();

 private:
  int Dfs(int, int);
  std::vector<std::vector<Edge>> list_adjacency_;
  std::vector<bool> visited_;
  const int k_max_capacity_ = static_cast<int>(9e8);
  int source_;
  int sink_;
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n = 0, m = 0;
  std::cin >> n >> m;
  int from = 0, to = 0, throughput = 0;
  Graph graph(n);
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to >> throughput;
    from--;
    to--;
    graph.AddEdge(from, to, throughput);
  }
  int max_flow = graph.FordFulkerson();
  std::cout << max_flow;
  return 0;
}

Graph::Graph(int size) : list_adjacency_(2 * size), visited_(2 * size), source_(0), sink_(size - 1) {
}
void Graph::AddEdge(int from, int to, int throughput) {
  list_adjacency_[from].push_back({to, 0, throughput});
  list_adjacency_[to].push_back({from, 0, 0});
}
int Graph::Dfs(int vertex, int min_capacity) {
  if (vertex == sink_) {
    return min_capacity;
  }
  visited_[vertex] = true;
  for (auto& edge : list_adjacency_[vertex]) {
    if (edge.capacity - edge.flow == 0) {
      continue;
    }
    if (!visited_[edge.to] && edge.flow < edge.capacity) {
      int delta = Dfs(edge.to, std::min(min_capacity, edge.capacity - edge.flow));
      if (delta > 0) {
        edge.flow += delta;
        for (auto& back_edge : list_adjacency_[edge.to]) {
          if (back_edge.to == vertex) {
            back_edge.flow -= delta;
            break;
          }
        }
        return delta;
      }
    }
  }
  return 0;
}
int Graph::FordFulkerson() {
  while (true) {
    if (!Dfs(source_, k_max_capacity_)) {
      break;
    }
    for (auto&& i : visited_) {
      i = false;
    }
  }
  int flow = 0;
  for (auto& edge : list_adjacency_[source_]) {
    flow += edge.flow;
  }
  return flow;
}*/