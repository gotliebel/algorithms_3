/*#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int);
  std::vector<int> FindShortestWay(int, int);
  int GetDistanceToVertex(int);

 private:
  void BFS(int);

  std::vector<int> dist_;
  std::vector<int> parent_;
  std::vector<std::vector<int>> list_adjacency_;
};

int main() {
  int n = 0, m;
  std::cin >> n >> m;
  int start, finish;
  std::cin >> start >> finish;
  start--;
  finish--;
  int from, to;
  Graph graph(n);
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to;
    from--;
    to--;
    graph.AddEdge(from, to);
  }
  std::vector<int> path = graph.FindShortestWay(start, finish);
  if (path.size() == 1) {
    int distance = graph.GetDistanceToVertex(finish);
    std::cout << distance << '\n';
    if (distance != -1) {
      std::cout << path[0] + 1;
    }
  } else {
    std::cout << graph.GetDistanceToVertex(finish) << '\n';
    std::reverse(path.begin(), path.end());
    for (auto& vertex : path) {
      std::cout << vertex + 1 << ' ';
    }
  }
  return 0;
}

Graph::Graph(int size) : list_adjacency_(size) {
}
void Graph::AddEdge(int from, int to) {
  list_adjacency_[from].push_back(to);
  list_adjacency_[to].push_back(from);
}
std::vector<int> Graph::FindShortestWay(int start, int finish) {
  BFS(start);
  std::vector<int> path;
  int cur = finish;
  if (dist_[finish] == -1) {
    path.push_back(-1);
    return path;
  }
  while (parent_[cur] != -1) {
    path.push_back(cur);
    cur = parent_[cur];
  }
  path.push_back(start);
  return path;
}
int Graph::GetDistanceToVertex(int finish) {
  return dist_[finish];
}
void Graph::BFS(int vertex) {
  dist_.resize(list_adjacency_.size(), -1);
  parent_.resize(list_adjacency_.size());
  std::queue<int> queue_vertices;
  queue_vertices.push(vertex);
  dist_[vertex] = 0;
  parent_[vertex] = -1;
  while (!queue_vertices.empty()) {
    int cur = queue_vertices.front();
    queue_vertices.pop();
    for (auto& to : list_adjacency_[cur]) {
      if (dist_[to] == -1) {
        dist_[to] = dist_[cur] + 1;
        parent_[to] = cur;
        queue_vertices.push(to);
      }
    }
  }
}*/