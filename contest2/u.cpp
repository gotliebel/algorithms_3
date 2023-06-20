/*#include <iostream>
#include <set>
#include <vector>

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int);
  int Cluster();

 private:
  enum class Color { WHITE, GRAY, BLACK };
  void Dfs(int, int);
  void DfsBridges(int, int);

  int time_ = 0;
  std::vector<std::pair<int, int>> component_;
  std::vector<int> fup_;
  std::vector<int> time_in_;
  std::vector<Color> colors_;
  std::set<std::pair<int, int>> bridges_indexes_;
  std::vector<std::vector<int>> list_adjacency_;
};

int main() {
  int n, m;
  std::cin >> n >> m;
  Graph graph(n);
  int from, to;
  for (int i = 0; i < m; ++i) {
    std::cin >> from >> to;
    from--;
    to--;
    graph.AddEdge(from, to);
  }
  int tunnels = graph.Cluster();
  std::cout << tunnels;
}

Graph::Graph(int size) : list_adjacency_(size) {
}
void Graph::AddEdge(int from, int to) {
  list_adjacency_[from].push_back(to);
  list_adjacency_[to].push_back(from);
}
int Graph::Cluster() {
  colors_.resize(list_adjacency_.size(), Color::WHITE);
  time_in_.resize(list_adjacency_.size(), 0);
  fup_.resize(list_adjacency_.size(), 0);
  time_ = 0;
  for (int i = 0; i < static_cast<int>(list_adjacency_.size()); i++) {
    if (colors_[i] == Color::WHITE) {
      DfsBridges(i, -1);
    }
  }
  for (int i = 0; i < static_cast<int>(list_adjacency_.size()); i++) {
    colors_[i] = Color::WHITE;
  }
  int index = -1;
  for (int i = 0; i < static_cast<int>(list_adjacency_.size()); i++) {
    if (colors_[i] == Color::WHITE) {
      Dfs(i, index);
      index++;
    }
  }
  int number_one_bridge_components = 0;
  std::vector<int> vector(list_adjacency_.size());
  int number_components = 0;
  for (size_t i = 0; i < list_adjacency_.size(); i++) {
    vector[component_[i].first] = component_[i].second + 1;
    number_components = component_[i].second + 1;
  }
  number_components++;
  std::vector<int> number_bridges_for_components(number_components, 0);
  for (auto& i : bridges_indexes_) {
    number_bridges_for_components[vector[i.first]] += 1;
    number_bridges_for_components[vector[i.second]] += 1;
  }
  for (int i = 0; i < number_components; i++) {
    number_bridges_for_components[i] /= 2;
    if (number_bridges_for_components[i] == 1) {
      number_one_bridge_components++;
    }
  }
  return (number_one_bridge_components + 1) / 2;
}

void Graph::Dfs(int vertex, int index) {
  colors_[vertex] = Color::GRAY;
  component_.emplace_back(vertex, index);
  for (auto& i : list_adjacency_[vertex]) {
    if (bridges_indexes_.find({vertex, i}) == bridges_indexes_.end()) {
      if (colors_[i] == Color::WHITE) {
        Dfs(i, index);
      }
    }
  }
}
void Graph::DfsBridges(int vertex, int parent) {
  colors_[vertex] = Color::GRAY;
  time_in_[vertex] = time_;
  fup_[vertex] = time_;
  time_++;
  for (auto& i : list_adjacency_[vertex]) {
    if (i == parent) {
      continue;
    }
    if (colors_[i] == Color::GRAY) {
      fup_[vertex] = std::min(fup_[vertex], time_in_[i]);
    }
    if (colors_[i] == Color::WHITE) {
      DfsBridges(i, vertex);
      fup_[vertex] = std::min(fup_[vertex], fup_[i]);
      if (fup_[i] > time_in_[vertex]) {
        bridges_indexes_.insert({vertex, i});
        bridges_indexes_.insert({i, vertex});
      }
    }
  }
}*/