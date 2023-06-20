/*#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

class Graph {
 public:
  Graph() = default;
  void MakeEdges();
  std::vector<int> FindShortestWay(const int&, const int&);
  int GetNumberOperations(const int&);

 private:
  void BFS(const int&);

  const int k_max_size_ = 10000;
  const int k_one_thousand_ = 1000;
  const int k_one_hundred_ = 100;
  const int k_ten_ = 10;
  std::vector<int> dist_;
  std::vector<int> parent_;
  std::vector<std::vector<int>> list_adjacency_;
};

int main() {
  int begin_number = 0, end_number = 0;
  std::cin >> begin_number >> end_number;
  Graph graph;
  graph.MakeEdges();
  std::vector<int> path = graph.FindShortestWay(begin_number, end_number);
  int operations = graph.GetNumberOperations(end_number);
  if (path.size() == 1) {
    std::cout << operations + 1 << '\n';
    if (operations != -1) {
      std::cout << path[0];
    }
  } else {
    std::reverse(path.begin(), path.end());
    std::cout << operations + 1 << '\n';
    for (auto& numbers : path) {
      std::cout << numbers << '\n';
    }
  }
  return 0;
}

void Graph::MakeEdges() {
  list_adjacency_.resize(k_max_size_);
  for (int i = k_one_thousand_; i < k_max_size_; i++) {
    int first_digit = i / k_one_thousand_;
    int second_digit = (i / k_one_hundred_) % k_ten_;
    int third_digit = (i / k_ten_) % k_ten_;
    int fourth_digit = i % k_ten_;
    if (first_digit != 9) {
      list_adjacency_[i].push_back(i + k_one_thousand_);
    }
    if (fourth_digit != 0) {
      list_adjacency_[i].push_back(i - 1);
    }
    list_adjacency_[i].push_back(fourth_digit * k_one_thousand_ + first_digit * k_one_hundred_ + second_digit * k_ten_ +
        third_digit);
    list_adjacency_[i].push_back(second_digit * k_one_thousand_ + third_digit * k_one_hundred_ + fourth_digit * k_ten_ +
        first_digit);
  }
}
int Graph::GetNumberOperations(const int& end_number) {
  return dist_[end_number];
}
std::vector<int> Graph::FindShortestWay(const int& begin_number, const int& end_number) {
  BFS(begin_number);
  std::vector<int> path;
  int cur = end_number;
  if (dist_[end_number] == -1) {
    path.push_back(-1);
    return path;
  }
  while (parent_[cur] != -1) {
    path.push_back(cur);
    cur = parent_[cur];
  }
  path.push_back(begin_number);
  return path;
}

void Graph::BFS(const int& vertex) {
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