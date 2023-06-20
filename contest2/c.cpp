/*#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

struct Vertex {
  int x;
  int y;
};

class Graph {
 public:
  explicit Graph(const int&);
  void AddEdges(const int&);
  std::vector<Vertex> FindShortestWay(const int&, const int&, const int&, const int&);
  int GetNumberMoves(const int&, const int&);
  
 private:
  void BFS(const int&, const int&);

  std::vector<std::vector<int>> dist_;
  std::vector<std::vector<Vertex>> parent_;
  std::vector<std::vector<std::vector<Vertex>>> list_adjacency_;
};
int main() {
  int n = 0;
  std::cin >> n;
  int x_from, y_from;
  int x_to, y_to;
  std::cin >> x_from >> y_from;
  std::cin >> x_to >> y_to;
  Graph graph(n + 4);
  x_from++;
  y_from++;
  x_to++;
  y_to++;
  graph.AddEdges(n);
  std::vector<Vertex> path = graph.FindShortestWay(x_from, y_from, x_to, y_to);
  if (path.size() == 1) {
    int moves = graph.GetNumberMoves(x_to, y_to);
    std::cout << moves << '\n';
    if (moves != -1) {
      std::cout << path[0].x - 1 << ' ' << path[0].y - 1;
    }
  } else {
    std::cout << graph.GetNumberMoves(x_to, y_to) << '\n';
    std::reverse(path.begin(), path.end());
    for (auto& coordinates : path) {
      std::cout << coordinates.x - 1 << ' ' << coordinates.y - 1 << '\n';
    }
  }
  return 0;
}

Graph::Graph(const int& size) : list_adjacency_(size) {
}
void Graph::AddEdges(const int& n) {
  for (int i = 0; i < n + 4; i++) {
    list_adjacency_[i].resize(n + 4);
    for (int j = 0; j < n + 4; j++) {
      if (i >= 2 && j >= 2 && i <= n + 1 && j <= n + 1) {
        list_adjacency_[i][j].push_back({i - 1, j - 2});
        list_adjacency_[i][j].push_back({i - 1, j + 2});
        list_adjacency_[i][j].push_back({i - 2, j - 1});
        list_adjacency_[i][j].push_back({i - 2, j + 1});
        list_adjacency_[i][j].push_back({i + 1, j - 2});
        list_adjacency_[i][j].push_back({i + 1, j + 2});
        list_adjacency_[i][j].push_back({i + 2, j - 1});
        list_adjacency_[i][j].push_back({i + 2, j + 1});
      }
    }
  }
}
int Graph::GetNumberMoves(const int& x_to, const int& y_to) {
  return dist_[x_to][y_to];
}
std::vector<Vertex> Graph::FindShortestWay(const int& x_begin, const int& y_begin, const int& x_end,
                                                        const int& y_end) {
  BFS(x_begin, y_begin);
  std::vector<Vertex> path;
  Vertex cur = {x_end, y_end};
  if (dist_[cur.x][cur.y] == -1) {
    path.push_back({-1, 0});
    return path;
  }
  while (parent_[cur.x][cur.y].x != -1 &&
      parent_[cur.x][cur.y].y != -1) {
    path.push_back({cur.x, cur.y});
    cur = {parent_[cur.x][cur.y].x,
           parent_[cur.x][cur.y].y};
  }
  path.push_back({x_begin, y_begin});
  return path;
}
void Graph::BFS(const int& x_vertex, const int& y_vertex) {
  dist_.resize(list_adjacency_.size());
  parent_.resize(list_adjacency_.size());
  for (size_t i = 0; i < list_adjacency_.size(); i++) {
    dist_[i].resize(list_adjacency_.size(), -1);
    parent_[i].resize(list_adjacency_.size());
  }
  std::queue<Vertex> queue_vertices;
  queue_vertices.push({x_vertex, y_vertex});
  dist_[x_vertex][y_vertex] = 0;
  parent_[x_vertex][y_vertex].x = -1;
  parent_[x_vertex][y_vertex].y = -1;
  while (!queue_vertices.empty()) {
    auto cur = queue_vertices.front();
    queue_vertices.pop();
    for (auto& to : list_adjacency_[cur.x][cur.y]) {
      if (dist_[to.x][to.y] == -1) {
        dist_[to.x][to.y] = dist_[cur.x][cur.y] + 1;
        parent_[to.x][to.y] = cur;
        queue_vertices.push({to.x, to.y});
      }
    }
  }
}*/