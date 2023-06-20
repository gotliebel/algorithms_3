/*#include <iostream>
#include <vector>

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int, size_t);
  size_t FindMinimumSpanningTreeBoruvka(int);
  struct Edge {
    int from;
    int to;
    size_t weight_;
    friend bool operator==(const Edge& first, const Edge& second);
    friend bool operator!=(const Edge& first, const Edge& second);
  };

 private:
  void MakeSet(int);
  int FindSet(int);
  void Union(int, int);

  const Edge edge_none_ = {-1, -1, static_cast<int>(1e9) + 1};
  std::vector<int> parent_;
  std::vector<int> rank_;
  std::vector<Edge> edges_;
};
bool operator==(const Graph::Edge& first, const Graph::Edge& second) {
  return first.from == second.from && first.to == second.to &&
         first.weight_ == second.weight_;
}
bool operator!=(const Graph::Edge& first, const Graph::Edge& second) {
  return !(first == second);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n = 0, m = 0;
  std::cin >> n >> m;
  int begin = 0, end = 0, weight = 0;
  Graph graph(n);
  for (int i = 0; i < m; i++) {
    std::cin >> begin >> end >> weight;
    begin--;
    end--;
    graph.AddEdge(begin, end, weight);
  }
  size_t final_weight = graph.FindMinimumSpanningTreeBoruvka(n);
  std::cout << final_weight;
  return 0;
}

Graph::Graph(int number_vertices) : parent_(number_vertices), rank_(number_vertices) {
}
void Graph::AddEdge(int begin, int end, size_t weight) {
  edges_.push_back({begin, end, weight});
  edges_.push_back({end, begin, weight});
}
size_t Graph::FindMinimumSpanningTreeBoruvka(int number_vertices) {
  size_t final_weight = 0;
  for (int i = 0; i < number_vertices; i++) {
    MakeSet(i);
  }
  int number_trees = number_vertices;
  while (number_trees > 1) {
    std::vector<Edge> min_edge(parent_.size(), edge_none_);
    for (auto& edge : edges_) {
      int component_begin = FindSet(edge.from);
      int component_end = FindSet(edge.to);
      if (component_begin != component_end) {
        if (edge.weight_ < min_edge[component_begin].weight_) {
          min_edge[component_begin] = edge;
        }
        if (edge.weight_ < min_edge[component_end].weight_) {
          min_edge[component_end] = edge;
        }
      }
    }
    for (auto& edge : min_edge) {
      if (edge != edge_none_) {
        int component_begin = FindSet(edge.from);
        int component_end = FindSet(edge.to);
        if (component_end != component_begin) {
          final_weight += edge.weight_;
          number_trees--;
          Union(edge.from, edge.to);
        }
      }
    }
  }
  return final_weight;
}

void Graph::MakeSet(int x) {
  parent_[x] = x;
  rank_[x] = 0;
}
int Graph::FindSet(int x) {
  if (x == parent_[x]) {
    return x;
  }
  return parent_[x] = FindSet(parent_[x]);
}
void Graph::Union(int x, int y) {
  x = FindSet(x);
  y = FindSet(y);
  if (rank_[x] < rank_[y]) {
    parent_[x] = y;
  } else if (rank_[y] < rank_[x]) {
    parent_[y] = x;
  } else {
    parent_[x] = y;
    rank_[y] += 1;
  }
}*/