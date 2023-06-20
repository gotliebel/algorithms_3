#include <deque>
#include <iostream>
#include <vector>

struct Vertex {
  int x;
  int y;
};

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int);
  int Query(int, int);
  
 private:
  void BFS(int);

  std::vector<int> fines_;
  std::vector<std::vector<Vertex>> list_adjacency_;
  int size_;
};

int main() {
  int n, m;
  std::cin >> n >> m;
  int from, to;
  Graph graph(n);
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to;
    from--;
    to--;
    graph.AddEdge(from, to);
  }
  int k;
  std::cin >> k;
  int fine = 0;
  for (int i = 0; i < k; i++) {
    std::cin >> from >> to;
    from--;
    to--;
    fine = graph.Query(from, to);
    std::cout << fine << '\n';
  }
}

Graph::Graph(int n) : fines_(n), list_adjacency_(n), size_(n) {
}
void Graph::AddEdge(int from, int to) {
  list_adjacency_[from].push_back({to, 0});
  list_adjacency_[to].push_back({from, 1});
}
int Graph::Query(int from, int to) {
  BFS(from);
  if (fines_[to] == size_) {
    return -1;
  }
  return fines_[to];
}

void Graph::BFS(int vertex) {
  for (size_t i = 0; i < list_adjacency_.size(); i++) {
    fines_[i] = size_;
  }
  std::deque<int> deque;
  deque.push_back(vertex);
  fines_[vertex] = 0;
  while (!deque.empty()) {
    int cur = deque.front();
    deque.pop_front();
    for (auto& to : list_adjacency_[cur]) {
      if (fines_[cur] + to.y < fines_[to.x]) {
        fines_[to.x] = fines_[cur] + to.y;
        if (to.y == 1) {
          deque.push_back(to.x);
        } else {
          deque.push_front(to.x);
        }
      }
    }
  }
}