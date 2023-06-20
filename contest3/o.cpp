/*#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

struct FlowElement {
  int vertex;
  int64_t flow;
};
class Graph {
 public:
  explicit Graph(int n);
  void AddEdge(int, int, int);
  int64_t MaxFlow(int start, int finish);

 private:
  int64_t FindFlow(int start, int finish);
  std::vector<std::unordered_map<int, int64_t>> list_adj_;
  std::vector<int> parent_;
  const int64_t k_max_flow_ = 9e9;
};

int main() {
  int n = 0, m = 0;
  std::cin >> n >> m;
  int from = 0, to = 0, flow = 0;
  Graph graph(n);
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to >> flow;
    from--;
    to--;
    graph.AddEdge(from, to, flow);
  }
  int64_t max_flow = graph.MaxFlow(0, n - 1);
  std::cout << max_flow;
  return 0;
}

Graph::Graph(int n) : list_adj_(n) {
}

void Graph::AddEdge(int from, int to, int flow) {
  list_adj_[from].insert({to, flow});
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
int64_t Graph::MaxFlow(int start, int finish) {
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

  return max_flow;
}*/