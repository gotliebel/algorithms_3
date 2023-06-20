/*#include <iostream>
#include <set>
#include <vector>
#pragma GCC optimize("O3")

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
  Graph(int, int, int);
  void AddEdges(const std::vector<std::vector<int>>&, int, int, int, int);
  int FindPrice();

 private:
  void AddEdge(int, int, int, int);
  void AddStairs(int, int);
  int Dijkstra(int, int);
  const int k_max_dist_ = static_cast<int>(1e9);
  std::vector<std::vector<Dest>> list_adjacency_;
  const int k_number_floors_;
  int max_floor_;
  std::set<int> used_vertices_;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n = 0, u = 0, d = 0, i = 0, j = 0, l = 0;
  std::cin >> n >> u >> d >> i >> j >> l;
  int k = 0;
  int floor = 0;
  int max_floor = n;
  std::vector<std::vector<int>> all_lifts_floors(l);
  for (int m = 0; m < l; m++) {
    std::cin >> k;
    for (int h = 0; h < k; h++) {
      std::cin >> floor;
      floor--;
      all_lifts_floors[m].push_back(floor);
    }
    max_floor = std::max(max_floor, floor);
  }
  Graph graph(max_floor, l, n);
  graph.AddEdges(all_lifts_floors, i, j, u, d);
  int price = graph.FindPrice();
  std::cout << price;
  return 0;
}
Graph::Graph(int max_floor, int number_lifts, int n)
    : list_adjacency_(max_floor + number_lifts), k_number_floors_(n), max_floor_(max_floor) {
}
void Graph::AddEdges(const std::vector<std::vector<int>>& all_lifts, int input_cost, int output_cost, int up_price,
                     int down_price) {
  max_floor_ = std::max(max_floor_, k_number_floors_);
  int index = 0;
  for (const auto& all_lift : all_lifts) {
    for (auto& floor : all_lift) {
      used_vertices_.insert(floor);
      AddEdge(floor, max_floor_ + index, input_cost, output_cost);
    }
    index++;
  }
  used_vertices_.insert(k_number_floors_ - 1);
  AddStairs(up_price, down_price);
}

void Graph::AddEdge(int from, int to, int weight_first, int weight_second) {
  list_adjacency_[from].push_back({to, weight_first});
  list_adjacency_[to].push_back({from, weight_second});
}

void Graph::AddStairs(int up_price, int down_price) {
  int from = 0;
  for (auto& floor : used_vertices_) {
    AddEdge(from, floor, (floor - from) * up_price, (floor - from) * down_price);
    from = floor;
  }
}
int Graph::FindPrice() {
  return Dijkstra(0, k_number_floors_ - 1);
}
int Graph::Dijkstra(int begin, int end) {
  std::vector<int> dist(list_adjacency_.size(), k_max_dist_);
  dist[begin] = 0;
  std::set<Vertex, CompareVertex> min_dist;
  min_dist.insert({begin, dist[begin]});
  std::vector<bool> used(list_adjacency_.size(), false);
  used[begin] = true;
  while (!min_dist.empty()) {
    auto min_vertex = *min_dist.begin();
    min_dist.erase(min_dist.begin());
    for (auto& dest : list_adjacency_[min_vertex.id]) {
      if ((!used[dest.to]) && dist[dest.to] > dist[min_vertex.id] + dest.weight) {
        min_dist.erase({dest.to, dist[dest.to]});
        dist[dest.to] = dist[min_vertex.id] + dest.weight;
        min_dist.insert({dest.to, dist[dest.to]});
      }
    }
  }
  return dist[end];
}*/