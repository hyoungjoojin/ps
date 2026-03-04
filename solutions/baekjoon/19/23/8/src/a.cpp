#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>

const int MAX_N = 21;
const int MAX_M = 401;
const int INF = std::numeric_limits<int>::max();

enum { WALL = 1, EMPTY = 0 };

int N;
int grid[MAX_N][MAX_N];

struct Customer {
  int sr;
  int sc;
  int er;
  int ec;
  bool processed;
};

int M;
Customer customers[MAX_M];

int distance[MAX_M][MAX_N][MAX_N];
int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int current_r, current_c;
int fuel;

std::queue<std::pair<int, int>> queue;

void compute_distance(int i) {
  int sr = customers[i].sr, sc = customers[i].sc;

  distance[i][sr][sc] = 0;
  queue.push({sr, sc});

  while (!queue.empty()) {
    int r = queue.front().first, c = queue.front().second;
    queue.pop();

    for (int di = 0; di < 4; di++) {
      int next_r = r + directions[di][0], next_c = c + directions[di][1];
      if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= N ||
          grid[next_r][next_c] == WALL || distance[i][next_r][next_c] != -1) {
        continue;
      }

      distance[i][next_r][next_c] = distance[i][r][c] + 1;
      queue.push({next_r, next_c});
    }
  }
}

void init() {
  std::sort(customers, customers + M,
            [](const Customer &c1, const Customer &c2) {
              if (c1.sr == c2.sr) {
                return c1.sc < c2.sc;
              } else {
                return c1.sr < c2.sr;
              }
            });

  for (int i = 0; i < M; i++) {
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < N; c++) {
        distance[i][r][c] = -1;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    compute_distance(i);
  }
}

bool move() {
  int customer = -1;
  int min_distance = INF;

  for (int i = 0; i < M; i++) {
    if (customers[i].processed || distance[i][current_r][current_c] == -1) {
      continue;
    }

    if (distance[i][current_r][current_c] < min_distance) {
      customer = i;
      min_distance = distance[i][current_r][current_c];
    }
  }

  if (customer == -1) {
    return false;
  }

  int destination_r = customers[customer].er,
      destination_c = customers[customer].ec;

  if (distance[customer][destination_r][destination_c] == -1) {
    return false;
  }

  int required_fuel = (distance[customer][current_r][current_c] +
                       distance[customer][destination_r][destination_c]);

  if (required_fuel > fuel) {
    return false;
  }

  fuel -= required_fuel;
  fuel += (distance[customer][destination_r][destination_c] * 2);

  current_r = destination_r;
  current_c = destination_c;

  customers[customer].processed = true;
  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N >> M >> fuel;

  int input;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> input;
      grid[i][j] = (input == 1 ? WALL : EMPTY);
    }
  }

  std::cin >> current_r >> current_c;
  current_r--;
  current_c--;

  int sr, sc, er, ec;
  for (int i = 0; i < M; i++) {
    std::cin >> sr >> sc >> er >> ec;
    customers[i] = {sr - 1, sc - 1, er - 1, ec - 1};
  }

  init();

  bool success = true;
  for (int i = 0; i < M; i++) {
    success = move();

    if (!success) {
      break;
    }
  }

  if (success) {
    std::cout << fuel << '\n';
  } else {
    std::cout << "-1\n";
  }

  return 0;
}
