/*#include <iostream>
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
  std::vector<int> FindAllDist(int);

 private:
  std::vector<int> Dijkstra(int);
  std::vector<std::vector<Dest>> adjacency_list_;
  int size_;
  const int k_max_dist_ = 2009000999;
};

int main() {
  int num = 0;
  std::cin >> num;
  int n = 0, m = 0;
  for (int i = 0; i < num; i++) {
    std::cin >> n >> m;
    Graph graph(n);
    int from = 0, to = 0;
    int weight = 0;
    int start = 0;
    for (int j = 0; j < m; j++) {
      std::cin >> from >> to >> weight;
      graph.AddEdge(from, to, weight);
    }
    std::cin >> start;
    std::vector<int> distance = graph.FindAllDist(start);
    for (auto& dist : distance) {
      std::cout << dist << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
Graph::Graph(int size) : adjacency_list_(size), size_(size) {
}
void Graph::AddEdge(int from, int to, int weight) {
  adjacency_list_[from].push_back({to, weight});
  adjacency_list_[to].push_back({from, weight});
}
std::vector<int> Graph::FindAllDist(int begin) {
  return Dijkstra(begin);
}
std::vector<int> Graph::Dijkstra(int begin) {
  std::vector<int> dist(adjacency_list_.size(), k_max_dist_);
  dist[begin] = 0;
  std::set<Vertex, CompareVertex> min_dist;
  for (int i = 0; i < size_; i++) {
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
  return dist;
}*/