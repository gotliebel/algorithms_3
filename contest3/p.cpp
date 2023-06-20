/*#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

struct FlowElement {
  int vertex;
  int64_t flow;
};

class Graph {
 public:
  Graph(int, int);
  void SetElement(int, int, char);
  bool MaxFlow(int start, int finish);
  void AddEdges();

 private:
  void AddEdge(int, int, int);
  int64_t FindFlow(int start, int finish);
  int GetValence(char);
  const int k_num_vertices_;
  const int height_;
  const int width_;
  std::vector<std::unordered_map<int, int64_t>> list_adj_;
  std::vector<int> parent_;
  std::vector<std::vector<char>> map_;
  int first_color_sum_ = 0;
  int second_color_sum_ = 0;
  const int64_t k_max_flow_ = 9e9;
};

int main() {
  int n = 0, m = 0;
  std::cin >> n >> m;
  Graph graph(n, m);
  char element = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> element;
      graph.SetElement(i, j, element);
    }
  }
  graph.AddEdges();
  bool is_valid = graph.MaxFlow(0, n * m + 1);
  if (is_valid) {
    std::cout << "Valid";
  } else {
    std::cout << "Invalid";
  }
  return 0;
}

Graph::Graph(int n, int m)
    : k_num_vertices_(n * m + 2), height_(n), width_(m), list_adj_(n * m + 2), parent_(n * m + 2) {
  map_.resize(n, std::vector<char>(m));
}

void Graph::SetElement(int i, int j, char element) {
  map_[i][j] = element;
}
void Graph::AddEdge(int from, int to, int flow) {
  list_adj_[from].insert({to, flow});
}

void Graph::AddEdges() {
  for (int i = 0; i < height_; i++) {
    for (int j = 0; j < width_; j++) {
      int base_vertex = i * width_ + j + 1;
      int valence = GetValence(map_[i][j]);
      if ((i + j) % 2 == 0) {
        first_color_sum_ += valence;
        if (i != 0) {
          AddEdge(base_vertex, (i - 1) * width_ + j + 1, 1);
        }
        if (j != 0) {
          AddEdge(base_vertex, i * width_ + j, 1);
        }
        if (i != height_ - 1) {
          AddEdge(base_vertex, (i + 1) * width_ + j + 1, 1);
        }
        if (j != width_ - 1) {
          AddEdge(base_vertex, i * width_ + j + 2, 1);
        }
        AddEdge(0, base_vertex, valence);
      } else {
        second_color_sum_ += valence;
        AddEdge(base_vertex, k_num_vertices_ - 1, valence);
      }
    }
  }
}

int Graph::GetValence(char element) {
  if (element == 'H') {
    return 1;
  }
  if (element == 'O') {
    return 2;
  }
  if (element == 'N') {
    return 3;
  }
  if (element == 'C') {
    return 4;
  }
  return 0;
}
int64_t Graph::FindFlow(int start, int finish) {
  parent_.resize(list_adj_.size());
  for (int& i : parent_) {
    i = -1;
  }
  std::queue<FlowElement> flow_queue;
  flow_queue.push({start, k_max_flow_});
  parent_[start] = -2;
  while (!flow_queue.empty()) {
    auto flow_element = flow_queue.front();
    flow_queue.pop();
    for (auto next : list_adj_[flow_element.vertex]) {
      if (parent_[next.first] == -1 && next.second != 0) {
        parent_[next.first] = flow_element.vertex;
        auto new_flow = std::min(flow_element.flow, next.second);
        if (next.first == finish) {
          return new_flow;
        }
        flow_queue.push({next.first, new_flow});
      }
    }
  }
  return 0;
}
bool Graph::MaxFlow(int start, int finish) {
  int64_t cur_flow = 0;
  int64_t max_flow = 0;
  cur_flow = FindFlow(start, finish);
  while (cur_flow > 0) {
    max_flow += cur_flow;
    int top = finish;
    while (top != start) {
      int prev = parent_[top];
      list_adj_[prev][top] -= cur_flow;
      list_adj_[top][prev] += cur_flow;
      top = prev;
    }
    cur_flow = FindFlow(start, finish);
  }
  return max_flow == first_color_sum_ && max_flow != 0 && max_flow == second_color_sum_;
}*/