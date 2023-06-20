#include <iostream>
#include <vector>

struct Atom {
  char symbol;
  std::vector<int> connections;
};
class Graph {
 public:
  explicit Graph(int);
  void AddEdge(int, int);
  void MakeAtoms(const char&, int);
  bool IsAlcane();

 private:
  enum class Color { GRAY, WHITE };
  int Dfs(int);
  bool HasCycle();
  bool HasCycleDfs(int, int);

  std::vector<bool> visited_;
  std::vector<Color> colors_;
  std::vector<Atom> list_adjacency_;
  int size_;
};

int main() {
  int n = 0, m = 0;
  std::cin >> n >> m;
  Graph graph(n);
  std::string molecule;
  std::cin >> molecule;
  for (int i = 0; i < int(molecule.size()); i++) {
    graph.MakeAtoms(molecule[i], i);
  }
  int from, to;
  for (int i = 0; i < m; i++) {
    std::cin >> from >> to;
    from--;
    to--;
    graph.AddEdge(from, to);
  }
  if (graph.IsAlcane()) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
}

Graph::Graph(int size) : list_adjacency_(size), size_(size) {
}
void Graph::AddEdge(int from, int to) {
  list_adjacency_[from].connections.push_back(to);
  list_adjacency_[to].connections.push_back(from);
}
void Graph::MakeAtoms(const char& c, int index) {
  list_adjacency_[index].symbol = c;
}
bool Graph::IsAlcane() {
  visited_.resize(list_adjacency_.size(), false);
  if (Dfs(0) == size_) {
    if (!HasCycle()) {
      for (auto& i : list_adjacency_) {
        if (i.symbol == 'H') {
          if (i.connections.size() != 1) {
            return false;
          }
          if (list_adjacency_[i.connections[0]].symbol == 'H') {
            return false;
          }
        } else {
          if (i.connections.size() != 4) {
            return false;
          }
        }
      }
      return true;
    }
  }
  return false;
}

int Graph::Dfs(int vertex) {
  visited_[vertex] = true;
  int visited_vertices = 1;
  for (auto& to : list_adjacency_[vertex].connections) {
    if (!visited_[to]) {
      visited_vertices += Dfs(to);
    }
  }
  return visited_vertices;
}
bool Graph::HasCycle() {
  colors_.resize(list_adjacency_.size(), Color::WHITE);
  for (size_t i = 0; i < list_adjacency_.size(); i++) {
    colors_[i] = Color::WHITE;
  }
  for (int i = 0; i < size_; i++) {
    if (colors_[i] == Color::WHITE) {
      if (HasCycleDfs(i, -1)) {
        return true;
      }
    }
  }
  return false;
}
bool Graph::HasCycleDfs(int vertex, int parent) {
  colors_[vertex] = Color::GRAY;
  for (auto& to : list_adjacency_[vertex].connections) {
    if (colors_[to] == Color::WHITE) {
      if (HasCycleDfs(to, vertex)) {
        return true;
      }
    } else if (to != parent) {
      return true;
    }
  }
  return false;
}