/*#include <iostream>
#include <set>
#include <vector>

struct Vertex {
  int64_t id;
  int64_t dist;
};
struct Dest {
  int64_t to;
  int64_t weight;
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
  explicit Graph(int64_t);
  void AddEdge(int64_t, int64_t, int64_t);
  int64_t FindDist(int64_t, int64_t);
  void AddSickCountry(int64_t);

 private:
  std::vector<int64_t> Dijkstra(int64_t);
  std::vector<std::vector<Dest>> adjacency_list_;
  std::vector<int64_t> sick_countries_;
  int64_t size_;
  const int64_t k_max_dist_ = INT64_MAX;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int64_t n = 0, m = 0, k = 0;
  std::cin >> n >> m >> k;
  int64_t number_sick_country = 0;
  Graph graph(n);
  for (int64_t i = 0; i < k; i++) {
    std::cin >> number_sick_country;
    number_sick_country--;
    graph.AddSickCountry(number_sick_country);
  }
  int64_t from = 0, to = 0, length = 0;
  for (int64_t i = 0; i < m; i++) {
    std::cin >> from >> to >> length;
    from--;
    to--;
    graph.AddEdge(from, to, length);
  }
  int64_t start_country = 0, finish_country = 0;
  std::cin >> start_country >> finish_country;
  start_country--;
  finish_country--;
  std::cout << graph.FindDist(start_country, finish_country);
  return 0;
}

Graph::Graph(int64_t size) : adjacency_list_(size), size_(size) {
}
void Graph::AddEdge(int64_t from, int64_t to, int64_t weight) {
  adjacency_list_[from].push_back({to, weight});
  adjacency_list_[to].push_back({from, weight});
}
void Graph::AddSickCountry(int64_t sick_country) {
  sick_countries_.push_back(sick_country);
}
int64_t Graph::FindDist(int64_t start_country, int64_t finish_country) {
  std::vector<int64_t> distance = Dijkstra(finish_country);
  for (auto& sick_country : sick_countries_) {
    if (distance[sick_country] <= distance[start_country]) {
      return -1;
    }
  }
  return distance[start_country];
}
std::vector<int64_t> Graph::Dijkstra(int64_t begin) {
  std::vector<int64_t> dist(adjacency_list_.size(), k_max_dist_);
  dist[begin] = 0;
  std::set<Vertex, CompareVertex> min_dist;
  min_dist.insert({begin, dist[begin]});
  std::vector<bool> used(adjacency_list_.size(), false);
  used[begin] = true;
  while (!min_dist.empty()) {
    auto min_vertex = *min_dist.begin();
    min_dist.erase(min_dist.begin());
    for (auto& dest : adjacency_list_[min_vertex.id]) {
      if ((!used[dest.to]) && dist[dest.to] > dist[min_vertex.id] + dest.weight) {
        min_dist.erase({dest.to, dist[dest.to]});
        dist[dest.to] = dist[min_vertex.id] + dest.weight;
        min_dist.insert({dest.to, dist[dest.to]});
      }
    }
  }
  return dist;
}*/