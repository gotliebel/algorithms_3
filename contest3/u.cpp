/*#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int, int, int);
  void Floyd();
  bool FindPath(int, int);
  void PrintPath();

 private:
  struct Parent {
    int from;
    int index;
  };
  const int max_dist_;
  std::vector<std::vector<int>> dist_;
  std::vector<std::vector<Parent>> parent_;
  std::vector<std::vector<int>> path_;
  int count_flights_ = 0;
  int size_;
};

int main() {
  int n = 0, m = 0, k = 0;
  std::cin >> n >> m >> k;
  int from = 0, to = 0, weight = 0;
  Graph graph(n);
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to >> weight;
    from--;
    to--;
    graph.AddEdge(from, to, -weight, i + 1);
  }
  int start = 0, finish = 0;
  graph.Floyd();
  std::cin >> start;
  start--;
  bool is_inf = false;
  for (int i = 0; i < k - 1; i++) {
    std::cin >> finish;
    finish--;
    if (!graph.FindPath(start, finish)) {
      is_inf = true;
      break;
    }
    start = finish;
  }
  if (is_inf) {
    std::cout << "infinitely kind";
  } else {
    graph.PrintPath();
  }
}

Graph::Graph(int size) :
    max_dist_(9000000)
    , dist_(size, std::vector<int>(size, max_dist_))
    , parent_(size, std::vector<Parent>(size, {-1, -1}))
    , size_(size) {
}

void Graph::AddEdge(int from, int to, int weight, int index) {
  if (dist_[from][to] > weight) {
    dist_[from][to] = weight;
    parent_[from][to] = {from, index};
  }
}

void Graph::Floyd() {
  for (int i = 0; i < size_; i++) {
    dist_[i][i] = 0;
  }
  for (int k = 0; k < size_; k++) {
    for (int x = 0; x < size_; x++) {
      for (int y = 0; y < size_; y++) {
        if (dist_[x][k] < max_dist_ && dist_[k][y] < max_dist_ && dist_[x][y] > dist_[x][k] + dist_[k][y]) {
          dist_[x][y] = dist_[x][k] + dist_[k][y];
          parent_[x][y] = parent_[k][y];
        }
      }
    }
  }
}

bool Graph::FindPath(int start, int finish) {
  if (start == finish && dist_[start][start] >= 0) {
    return true;
  }
  if (dist_[start][start] < 0 || dist_[finish][finish] < 0) {
    return false;
  }
  std::vector<int> cur_path;
  int vertex = parent_[start][finish].from;
  int vertex_flight = parent_[start][finish].index;
  while (vertex != start) {
    if (vertex == -1) {
      return false;
    }
    if (dist_[vertex][vertex] < 0) {
      return false;
    }
    if (vertex_flight != -1) {
      cur_path.push_back(vertex_flight);
    }
    vertex_flight = parent_[start][vertex].index;
    vertex = parent_[start][vertex].from;
  }
  cur_path.push_back(vertex_flight);
  std::reverse(cur_path.begin(), cur_path.end());
  count_flights_ += static_cast<int>(cur_path.size());
  path_.emplace_back(std::move(cur_path));
  return true;
}

void Graph::PrintPath() {
  std::cout << count_flights_ << '\n';
  for (auto& path : path_) {
    for (auto vertex : path) {
      std::cout << vertex << ' ';
    }
  }
}*/