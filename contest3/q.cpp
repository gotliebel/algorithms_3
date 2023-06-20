/*#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int, int);
  int64_t MaxFlow(int, int);

 private:
  bool BfsFindFlow(int, int, std::vector<int>&);
  int64_t DfsFindFlow(int, int, int64_t, std::vector<int>&);
  const int k_max_dist_ = 1e9;
  const int64_t k_max_flow_ = 9e9;
  std::vector<std::unordered_map<int, int64_t>> list_adj_;
};

int main() {
  int n = 0, m = 0;
  std::cin >> n >> m;
  Graph graph(n);
  int from = 0, to = 0, flow = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to >> flow;
    from--;
    to--;
    graph.AddEdge(from, to, flow);
  }
  int64_t max_flow = graph.MaxFlow(0, n - 1);
  std::cout << max_flow;
  return 0;
}

Graph::Graph(int size) : list_adj_(size) {
}

void Graph::AddEdge(int from, int to, int flow) {
  list_adj_[from].insert({to, flow});
}

bool Graph::BfsFindFlow(int start, int finish, std::vector<int>& dist) {
  dist.assign(list_adj_.size(), k_max_dist_);
  dist[start] = 0;
  std::queue<int> bfs_queue;
  bfs_queue.push(start);
  while (!bfs_queue.empty()) {
    auto vertex = bfs_queue.front();
    bfs_queue.pop();
    for (auto& neib : list_adj_[vertex]) {
      if (dist[neib.first] == k_max_dist_ && neib.second > 0) {
        dist[neib.first] = dist[vertex] + 1;
        bfs_queue.push(neib.first);
      }
    }
  }
  return dist[finish] != k_max_dist_;
}

int64_t Graph::DfsFindFlow(int start, int finish, int64_t cur_flow, std::vector<int>& dist) {
  if (start == finish || cur_flow == 0) {
    return cur_flow;
  }
  for (auto& next : list_adj_[start]) {
    if (dist[next.first] != dist[start] + 1) {
      continue;
    }
    int64_t flow = DfsFindFlow(next.first, finish, std::min(cur_flow, next.second), dist);
    if (flow > 0) {
      list_adj_[start][next.first] -= flow;
      list_adj_[next.first][start] += flow;
      return flow;
    }
  }
  return 0;
}

int64_t Graph::MaxFlow(int start, int finish) {
  int64_t max_flow = 0;
  std::vector<int> dist(list_adj_.size());
  while (BfsFindFlow(start, finish, dist)) {
    int64_t cur_flow = DfsFindFlow(start, finish, k_max_flow_, dist);
    while (cur_flow != 0) {
      max_flow += cur_flow;
      cur_flow = DfsFindFlow(start, finish, k_max_flow_, dist);
    }
  }
  return max_flow;
}*/