#include <iostream>
#include <queue>
#include <utility>

const int MAX_N = 51;
const int MAX_M = 101;

enum { NOT_DELETED = 0, DELETED = 1 };

int N;
int grid[MAX_N][MAX_N];
int cloud_map[MAX_N][MAX_N];

int directions[8][2] = {
    {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1},
};

int M;
int m;
int d[MAX_M];
int s[MAX_M];

int total_water;
std::queue<std::pair<int, int>> cloud_queue;
std::queue<std::pair<int, int>> wet_queue;
std::queue<std::pair<int, std::pair<int, int>>> increment_queue;

void init() {
  total_water = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      total_water += grid[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cloud_map[i][j] = NOT_DELETED;
    }
  }

  cloud_queue.push({N - 2, 0});
  cloud_queue.push({N - 2, 1});
  cloud_queue.push({N - 1, 0});
  cloud_queue.push({N - 1, 1});
}

void move_and_rain() {
  while (!cloud_queue.empty()) {
    int r = cloud_queue.front().first, c = cloud_queue.front().second;
    cloud_queue.pop();

    int next_r = (((r + directions[d[m]][0] * s[m]) % N) + N) % N,
        next_c = (((c + directions[d[m]][1] * s[m]) % N) + N) % N;

    grid[next_r][next_c]++;
    total_water++;
    wet_queue.push({next_r, next_c});
    cloud_map[next_r][next_c] = DELETED;
  }
}

void duplicate_water() {
  while (!wet_queue.empty()) {
    int r = wet_queue.front().first, c = wet_queue.front().second;
    wet_queue.pop();

    int count = 0;
    for (int di = 1; di < 8; di += 2) {
      int next_r = r + directions[di][0], next_c = c + directions[di][1];
      if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= N) {
        continue;
      }

      if (grid[next_r][next_c] > 0) {
        count++;
      }
    }

    increment_queue.push({count, {r, c}});
  }

  while (!increment_queue.empty()) {
    int i = increment_queue.front().first,
        r = increment_queue.front().second.first,
        c = increment_queue.front().second.second;
    grid[r][c] += i;
    total_water += i;
    increment_queue.pop();
  }
}

void create_cloud() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (cloud_map[i][j] == DELETED) {
        cloud_map[i][j] = NOT_DELETED;
        continue;
      }

      if (grid[i][j] >= 2) {
        grid[i][j] -= 2;
        total_water -= 2;
        cloud_queue.push({i, j});
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> grid[i][j];
    }
  }

  for (int i = 0; i < M; i++) {
    std::cin >> d[i] >> s[i];
    d[i]--;
  }

  init();

  for (m = 0; m < M; m++) {
    move_and_rain();
    duplicate_water();
    create_cloud();
  }

  std::cout << total_water << '\n';

  return 0;
}
