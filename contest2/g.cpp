#include <iostream>
#include <vector>
#include <queue>

class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int, int);
  int FindShortestWay(int, int);

 private:
  void BFS(int);
  
  std::vector<int> dist_;
  std::vector<std::vector<int>> list_adjacency_;
};

int main() {
  int n, m;
  std::cin >> n >> m;
  int start_vertex, final_vertex;
  std::cin >> start_vertex >> final_vertex;
  start_vertex--;
  final_vertex--;
  int from, to;
  int weight;
  Graph graph(n);
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to >> weight;
    from--;
    to--;
    graph.AddEdge(from, to, weight);
  }
  int distance = graph.FindShortestWay(start_vertex, final_vertex);
  std::cout << distance;
}

Graph::Graph(int size) : list_adjacency_(size) {
}
void Graph::AddEdge(int from, int to, int weight) {
  if (weight == 1) {
    list_adjacency_[from].push_back(to);
  } else {
    auto previous_size = static_cast<int>(list_adjacency_.size());
    list_adjacency_[from].push_back(previous_size);
    list_adjacency_.resize(previous_size + weight - 1);
    while (previous_size != static_cast<int>(list_adjacency_.size()) - 1) {
      list_adjacency_[previous_size].push_back(previous_size + 1);
      previous_size++;
    }
    list_adjacency_[list_adjacency_.size() - 1].push_back(to);
  }
}
int Graph::FindShortestWay(int from, int to) {
  BFS(from);
  return dist_[to];
}

void Graph::BFS(int vertex) {
  dist_.resize(list_adjacency_.size(), -1);
  std::queue<int> queue;
  queue.push(vertex);
  dist_[vertex] = 0;
  while (!queue.empty()) {
    int cur = queue.front();
    queue.pop();
    for (auto& to : list_adjacency_[cur]) {
      if (dist_[to] == -1) {
        dist_[to] = dist_[cur] + 1;
        queue.push(to);
      }
    }
  }
}