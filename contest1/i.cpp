/*#include <iostream>
#include <vector>

void ZFunction(const std::vector<size_t>& cubes) {
  std::vector<int> zf(cubes.size());
  zf[0] = cubes.size();
  int left = 0, right = 0;
  for (int i = 1; i < zf[0]; ++i) {
    zf[i] = std::max(0, std::min(right - i, zf[i - left]));
    while (i + zf[i] < zf[0] && cubes[zf[i]] == cubes[i + zf[i]]) {
      ++zf[i];
    }
    if (i + zf[i] > right) {
      right = i + zf[i];
      left = i;
    }
  }
  size_t previous_size = (zf.size() - 1) / 2;
  for (int i = previous_size; i > 0; --i) {
    if (zf[zf.size() - 2 * i] >= i) {
      std::cout << previous_size - i << " ";
    }
  }
  std::cout << previous_size;
}

void CountPossibleCubes(std::vector<size_t> cubes, int m) {
  size_t previous_size = cubes.size();
  cubes.resize(2 * previous_size + 1);
  for (size_t i = 0; i < previous_size; ++i) {
    cubes[2 * previous_size - i] = cubes[i];
  }
  cubes[previous_size] = m + 1;
  ZFunction(cubes);
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<size_t> cubes(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> cubes[i];
  }
  CountPossibleCubes(cubes, m);
  return 0;
}*/