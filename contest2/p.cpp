#include <iostream>
#include <set>
#include <vector>

struct Dest {
  int vertex;
  int index;
};
class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int, int);
  std::set<int> FindBridges();

 private:
  enum class Color { WHITE, GRAY };
  void Dfs(int, int);

  int time_ = 0;
  std::vector<int> fup_;
  std::vector<int> time_in_;
  std::vector<Color> colors_;
  std::set<int> bridges_indexes_;
  std::vector<std::vector<Dest>> list_adjacency_;
  int size_;
};

int main() {
  int n = 0, m = 0;
  std::cin >> n >> m;
  Graph graph(n);
  int from = 0, to = 0;
  for (int i = 0; i < m; ++i) {
    std::cin >> from >> to;
    from--;
    to--;
    graph.AddEdge(from, to, i + 1);
  }
  std::set<int> bridges = graph.FindBridges();
  std::cout << bridges.size() << '\n';
  for (auto& element : bridges) {
    std::cout << element << ' ';
  }
  return 0;
}

Graph::Graph(int size) : list_adjacency_(size), size_(size) {
}
void Graph::AddEdge(int from, int to, int index) {
  list_adjacency_[from].push_back({to, index});
  list_adjacency_[to].push_back({from, index});
}
std::set<int> Graph::FindBridges() {
  colors_.resize(list_adjacency_.size(), Color::WHITE);
  time_in_.resize(list_adjacency_.size(), 0);
  fup_.resize(list_adjacency_.size(), 0);
  time_ = 0;
  for (int i = 0; i < size_; i++) {
    if (colors_[i] == Color::WHITE) {
      Dfs(i, -1);
    }
  }
  return bridges_indexes_;
}

void Graph::Dfs(int vertex, int parent) {
  colors_[vertex] = Color::GRAY;
  time_in_[vertex] = time_;
  fup_[vertex] = time_;
  time_++;
  for (auto& to : list_adjacency_[vertex]) {
    if (to.vertex == parent) {
      continue;
    }
    if (colors_[to.vertex] == Color::GRAY) {
      fup_[vertex] = std::min(fup_[vertex], time_in_[to.vertex]);
    }
    if (colors_[to.vertex] == Color::WHITE) {
      Dfs(to.vertex, vertex);
      fup_[vertex] = std::min(fup_[vertex], fup_[to.vertex]);
      if (fup_[to.vertex] > time_in_[vertex]) {
        bool is_multiple = false;
        for (auto& j : list_adjacency_[vertex]) {
          if (to.vertex == j.vertex && to.index != j.index) {
            is_multiple = true;
            break;
          }
        }
        if (!is_multiple) {
          bridges_indexes_.insert(to.index);
        }
      }
    }
  }
}