/*#include <iostream>
#include <vector>
#include <queue>

struct Vertex {
  int x;
  int y;
};

class Graph {
 public:
  Graph() = default;
  void MakeEdges(const std::vector<std::vector<int>>&);
  std::vector<std::vector<int>> FindShortestWay(const int&, const int&);

 private:
  void BFS(const int&, const int&);

  std::vector<std::vector<int>> dist_;
  std::queue<Vertex> queue_;
};
int main() {
  int n = 0, m = 0;
  std::cin >> n >> m;
  Graph graph;
  std::vector<std::vector<int>> new_york(n);
  for (int i = 0; i < n; i++) {
    new_york[i].resize(m);
    for (int j = 0; j < m; j++) {
      std::cin >> new_york[i][j];
    }
  }
  graph.MakeEdges(new_york);
  std::vector<std::vector<int>> distance = graph.FindShortestWay(n, m);
  for (auto& line : distance) {
    for (auto& element : line) {
      std::cout << element << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}

void Graph::MakeEdges(const std::vector<std::vector<int>>& new_york) {
  dist_.resize(new_york.size());
  auto width = static_cast<int>(new_york.size());
  auto length = static_cast<int>(new_york[0].size());
  for (int i = 0; i < width; i++) {
    dist_[i].resize(length, -1);
  }
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < length; j++) {
      if (new_york[i][j] == 1) {
        dist_[i][j] = 0;
        queue_.push({i, j});
      }
    }
  }
}
std::vector<std::vector<int>> Graph::FindShortestWay(const int& n, const int& m) {
  BFS(n, m);
  return dist_;
}

void Graph::BFS(const int& n, const int& m) {
  while (!queue_.empty()) {
    auto cur = queue_.front();
    queue_.pop();
    std::vector<Vertex> ways = {{cur.x + 1, cur.y}, {cur.x - 1, cur.y}, {cur.x, cur.y + 1}, {cur.x, cur.y - 1}};
    for (auto& to : ways) {
      if (to.x >= 0 && to.x < n && to.y >= 0 && to.y < m) {
        if (dist_[to.x][to.y] == -1) {
          dist_[to.x][to.y] = dist_[cur.x][cur.y] + 1;
          queue_.push({to.x, to.y});
        }
      }
    }
  }
}*/