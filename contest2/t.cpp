/*#include <iostream>
#include <vector>
#include <queue>

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int, int);
  int FindShortestWay(int, int);

 private:
  const int k_max_weight_ = 31;
  const int k_inf_ = k_max_weight_ * 50000;
  std::vector<std::vector<std::pair<int, int>>> list_adjacency_;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  int start_vertex, fin_vertex;
  std::cin >> start_vertex >> fin_vertex;
  start_vertex--;
  fin_vertex--;
  int from, to;
  int weight;
  Graph graph(n);
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to >> weight;
    from--;
    to--;
    graph.AddEdge(from, to, weight);
  }
  int shortest_way = graph.FindShortestWay(start_vertex, fin_vertex);
  std::cout << shortest_way;
  return 0;
}

Graph::Graph(int size) : list_adjacency_(size) {
}
void Graph::AddEdge(int from, int to, int weight) {
  list_adjacency_[from].emplace_back(to, weight);
}
int Graph::FindShortestWay(int from, int to) {
  std::vector<std::queue<int>> queue(k_max_weight_);
  std::vector<bool> used(list_adjacency_.size(), false);
  std::vector<int> dist(list_adjacency_.size(), k_inf_);
  dist[from] = 0;
  queue[0].push(from);
  int number_queue = 0;
  int number_vertices_queue = 1;
  while (number_vertices_queue > 0) {
    while (queue[number_queue % k_max_weight_].empty()) {
      number_queue++;
    }
    int cur = queue[number_queue % k_max_weight_].front();
    number_vertices_queue--;
    queue[number_queue % k_max_weight_].pop();
    if (!used[cur]) {
      used[cur] = true;
      for (auto& i : list_adjacency_[cur]) {
        if (dist[i.first] > dist[cur] + i.second) {
          dist[i.first] = dist[cur] + i.second;
          number_vertices_queue++;
          queue[dist[i.first] % k_max_weight_].push(i.first);
        }
      }
    }
  }
  if (dist[to] == k_inf_) {
    return -1;
  }
  return dist[to];
}*/