#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

class Graph {
 public:
  Graph(int, int);
  void AddEdge(int, int, int, int);
  std::set<int> FindDotsArticulation();
  int GetSkyScrapersSize() const;

 private:
  enum class Color { WHITE, GRAY };
  void Dfs(int, int);

  int size_skyscrapers_;
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
  Graph graph(n, n + m);
  int first = 0, second = 0, third = 0;
  for (int i = 0; i < m; i++) {
    std::cin >> first >> second >> third;
    first--;
    second--;
    third--;
    graph.AddEdge(first, second, third, i);
  }
  std::set<int> dots = graph.FindDotsArticulation();
  std::cout << dots.size() << '\n';
  int sky_scrapers_size = graph.GetSkyScrapersSize();
  for (auto& element : dots) {
    std::cout << element - sky_scrapers_size + 1 << '\n';
  }
  return 0;
}

Graph::Graph(int n, int size) : size_skyscrapers_(n), list_adjacency_(size), size_(size) {
}
void Graph::AddEdge(int first, int second, int third, int index) {
  list_adjacency_[size_skyscrapers_ + index].push_back(first);
  list_adjacency_[size_skyscrapers_ + index].push_back(second);
  list_adjacency_[size_skyscrapers_ + index].push_back(third);
  list_adjacency_[first].push_back(size_skyscrapers_ + index);
  list_adjacency_[second].push_back(size_skyscrapers_ + index);
  list_adjacency_[third].push_back(size_skyscrapers_ + index);
}
std::set<int> Graph::FindDotsArticulation() {
  colors_.resize(list_adjacency_.size(), Color::WHITE);
  time_in_.resize(list_adjacency_.size(), 0);
  fup_.resize(list_adjacency_.size());
  time_ = 0;
  for (int i = size_skyscrapers_; i < size_; i++) {
    if (colors_[i] == Color::WHITE) {
      Dfs(i, -1);
    }
  }
  return dots_articulation_;
}
int Graph::GetSkyScrapersSize() const {
  return size_skyscrapers_;
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
        if (vertex >= size_skyscrapers_) {
          dots_articulation_.insert(vertex);
        }
      }
    }
  }
  if (parent == -1 && children > 1) {
    dots_articulation_.insert(vertex);
  }
}