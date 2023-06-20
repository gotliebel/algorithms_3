/*#include <iostream>
#include <set>
#include <vector>
#include <queue>
struct Vertex {
  int x;
  int y;
};
struct CompareVertex {
  bool operator()(const Vertex& first, const Vertex& second) const {
    if (first.x < second.x) {
      return true;
    }
    if (first.x == second.x) {
      return first.y < second.y;
    }
    return false;
  }
};
class Graph {
 public:
  Graph(int, const std::vector<std::vector<char>>&);
  int FindShortestWay(int, int, int, int);

 private:
  void WalkRightUntilYWall(int, int, int, int);
  void WalkLeftUntilYWall(int, int, int, int);
  void WalkDownUntilXWall(int, int, int, int);
  void WalkUpUntilXWall(int, int, int, int);
  void AddEdge(int, int);
  void BFS(int, int);

  std::vector<std::vector<int>> dist_;
  std::vector<std::vector<char>> room_;
  std::vector<std::vector<std::set<Vertex, CompareVertex>>> list_adjacency_;
  int width_;
  int length_;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n = 0, m = 0;
  std::cin >> n >> m;
  std::vector<std::vector<char>> room(n);
  int x_from = 0, y_from = 0;
  int x_to = 0, y_to = 0;
  for (int i = 0; i < n; i++) {
    room[i].resize(m);
    for (int j = 0; j < m; j++) {
      std::cin >> room[i][j];
      if (room[i][j] == 'S') {
        x_from = i;
        y_from = j;
      }
      if (room[i][j] == 'T') {
        x_to = i;
        y_to = j;
      }
    }
  }
  Graph graph(n, room);
  int len = graph.FindShortestWay(x_from, y_from, x_to, y_to);
  std::cout << len;
  return 0;
}

Graph::Graph(int size, const std::vector<std::vector<char>>& room) : room_(room), list_adjacency_(size) {
  for (size_t i = 0; i < list_adjacency_.size(); i++) {
    list_adjacency_[i].resize(room[i].size());
  }
  width_ = static_cast<int>(room_.size());
  length_ = static_cast<int>(room_[0].size());
  for (int i = 0; i < width_; i++) {
    for (int j = 0; j < length_; j++) {
      if (room_[i][j] == '.' || room_[i][j] == 'S') {
        AddEdge(i, j);
      }
    }
  }
}
int Graph::FindShortestWay(int x_from, int y_from, int x_to, int y_to) {
  BFS(x_from, y_from);
  return dist_[x_to][y_to];
}

void Graph::WalkRightUntilYWall(int x_wall, int y_wall, int x, int y) {
  int counter = 0;
  for (int i = y; i < length_; i++) {
    counter++;
    if (room_[x][i] == '#') {
      y_wall = i;
      counter++;
      break;
    }
  }
  if (y_wall - (counter - 1) / 2 >= 0) {
    list_adjacency_[x][y].insert({x_wall, y_wall - (counter - 1) / 2});
  }
}
void Graph::WalkLeftUntilYWall(int x_wall, int y_wall, int x, int y) {
  int counter = 0;
  for (int i = y; i >= 0; i--) {
    counter++;
    if (room_[x][i] == '#') {
      y_wall = i;
      counter++;
      break;
    }
  }
  if (y_wall + (counter - 1) / 2 < length_) {
    list_adjacency_[x][y].insert({x_wall, y_wall + (counter - 1) / 2});
  }
}
void Graph::WalkDownUntilXWall(int x_wall, int y_wall, int x, int y) {
  int counter = 0;
  for (int i = x; i < width_; i++) {
    counter++;
    if (room_[i][y] == '#') {
      x_wall = i;
      counter++;
      break;
    }
  }
  if (x_wall - (counter - 1) / 2 >= 0) {
    list_adjacency_[x][y].insert({x_wall - (counter - 1) / 2, y_wall});
  }
}
void Graph::WalkUpUntilXWall(int x_wall, int y_wall, int x, int y) {
  int counter = 0;
  for (int i = x; i >= 0; i--) {
    counter++;
    if (room_[i][y] == '#') {
      x_wall = i;
      counter++;
      break;
    }
  }
  if (x_wall + (counter - 1) / 2 < width_) {
    list_adjacency_[x][y].insert({x_wall + (counter - 1) / 2, y_wall});
  }
}
void Graph::AddEdge(int x, int y) {
  int x_wall = x;
  int y_wall = length_ - 1;
  WalkRightUntilYWall(x_wall, y_wall, x, y);
  y_wall = 0;
  WalkLeftUntilYWall(x_wall, y_wall, x, y);
  x_wall = width_ - 1;
  y_wall = y;
  WalkDownUntilXWall(x_wall, y_wall, x, y);
  x_wall = 0;
  WalkUpUntilXWall(x_wall, y_wall, x, y);
  if (list_adjacency_[x][y].find({x, y}) != list_adjacency_[x][y].end()) {
    list_adjacency_[x][y].erase({x, y});
  }
}
void Graph::BFS(int x_vertex, int y_vertex) {
  dist_.resize(list_adjacency_.size());
  for (size_t i = 0; i < list_adjacency_.size(); i++) {
    dist_[i].resize(list_adjacency_[i].size(), -1);
  }
  std::queue<Vertex> queue;
  queue.push({x_vertex, y_vertex});
  dist_[x_vertex][y_vertex] = 0;
  while (!queue.empty()) {
    auto cur = queue.front();
    queue.pop();
    for (auto& to : list_adjacency_[cur.x][cur.y]) {
      if (dist_[to.x][to.y] == -1) {
        dist_[to.x][to.y] = dist_[cur.x][cur.y] + 1;
        queue.push({to.x, to.y});
      }
    }
  }
}*/