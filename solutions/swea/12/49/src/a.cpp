#include <cstdio>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

int size = 0;
int grid[101][101];
int distance[101][101];

std::priority_queue<std::pair<int, std::pair<int, int>>,
                    std::vector<std::pair<int, std::pair<int, int>>>,
                    std::greater<>>
    pq;

int solution() {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      distance[i][j] = std::numeric_limits<int>::max();
    }
  }

  distance[0][0] = 0;
  pq.push({0, {0, 0}});

  int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  while (!pq.empty()) {
    int d_x = pq.top().first;
    std::pair<int, int> x = pq.top().second;
    pq.pop();

    if (d_x > distance[x.first][x.second]) {
      continue;
    }

    for (int i = 0; i < 4; i++) {
      int next_r = x.first + d[i][0], next_c = x.second + d[i][1];
      if (next_r < 0 || next_r >= size || next_c < 0 || next_c >= size) {
        continue;
      }

      if (distance[next_r][next_c] >
          distance[x.first][x.second] + grid[next_r][next_c]) {
        distance[next_r][next_c] =
            distance[x.first][x.second] + grid[next_r][next_c];
        pq.push({distance[next_r][next_c], {next_r, next_c}});
      }
    }
  }

  return distance[size - 1][size - 1];
}

int main() {
  int T = 0;
  scanf("%d", &T);

  char input[101];

  for (int t = 1; t <= T; t++) {
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
      scanf("%s", input);

      for (int j = 0; j < size; j++) {
        grid[i][j] = (input[j] - '0');
      }
    }

    printf("#%d %d\n", t, solution());
  }

  return 0;
}
