#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int);
  std::set<int> FindArticulationPoints();

 private:
  enum class Color { WHITE, GRAY };
  void Dfs(int, int);

  int time_ = 0;
  std::vector<int> fup_;
  std::vector<int> time_in_;
  std::vector<Color> colors_;
  std::set<int> dots_articulation_;
  std::vector<std::vector<int>> list_adjacency_;
  int size_;
};

int main() {
  int n = 0, m = 0;
  std::cin >> n >> m;
  Graph graph(n);
  int from = 0, to = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to;
    from--;
    to--;
    graph.AddEdge(from, to);
  }
  std::set<int> articulation_points = graph.FindArticulationPoints();
  std::cout << articulation_points.size() << '\n';
  for (auto& element : articulation_points) {
    std::cout << element + 1 << '\n';
  }
  return 0;
}

Graph::Graph(int size) : list_adjacency_(size), size_(size) {
}
void Graph::AddEdge(int from, int to) {
  list_adjacency_[from].push_back(to);
  list_adjacency_[to].push_back(from);
}
std::set<int> Graph::FindArticulationPoints() {
  colors_.resize(list_adjacency_.size(), Color::WHITE);
  time_in_.resize(list_adjacency_.size(), 0);
  fup_.resize(list_adjacency_.size());
  time_ = 0;
  for (int i = 0; i < size_; i++) {
    if (colors_[i] == Color::WHITE) {
      Dfs(i, -1);
    }
  }
  return dots_articulation_;
}

void Graph::Dfs(int vertex, int parent) {
  colors_[vertex] = Color::GRAY;
  time_in_[vertex] = time_;
  fup_[vertex] = time_;
  time_++;
  int children = 0;
  for (auto& to : list_adjacency_[vertex]) {
    if (to == parent) {
      continue;
    }
    if (colors_[to] == Color::GRAY) {
      fup_[vertex] = std::min(fup_[vertex], time_in_[to]);
    } else {
      Dfs(to, vertex);
      children++;
      fup_[vertex] = std::min(fup_[vertex], fup_[to]);
      if (fup_[to] >= time_in_[vertex] && parent != -1) {
        dots_articulation_.insert(vertex);
      }
    }
  }
  if (parent == -1 && children > 1) {
    dots_articulation_.insert(vertex);
  }
}