#include <deque>
#include <iostream>
#include <utility>

const int MAX_N = 51;

int N;
int grid[MAX_N][MAX_N];
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int B;
int MAX_B;
int balls[MAX_N * MAX_N];
std::deque<std::pair<int, int>> ball_queue, temp_ball_queue;

int destroyed_balls[4];

int M;

void init() {
  MAX_B = N * N - 1;
  B = 0;

  int r = N / 2, c = N / 2;
  int d[4] = {2, 1, 3, 0};

  for (int l = 1, li = 2, di = 0;;) {
    for (int j = 0; j < l; j++) {
      if (r == 0 && c == 0) {
        break;
      }

      r += directions[d[di]][0], c += directions[d[di]][1];

      if (grid[r][c] != 0) {
        balls[B++] = grid[r][c];
      }
    }

    if (r == 0 && c == 0) {
      break;
    }

    if (grid[r][c] == 0) {
      break;
    }

    di = (di + 1) % 4;
    if (--li == 0) {
      li = 2;
      l++;
    }
  }

  for (int i = 1; i <= 3; i++) {
    destroyed_balls[i] = 0;
  }
}

int get_next_coordinate(int d, int s) {
  switch (d) {
  case 0:
    return (2 * s + 1) * (2 * s + 1) - (s + 1);

  case 1:
    return 4 * s * s - s;

  case 2:
    return (2 * s - 1) * (2 * s - 1) + (s - 1);

  case 3:
    return 4 * s * s + s;
  }

  return 0;
}

void remove(int d, int s) {
  for (int i = 1; i <= s; i++) {
    balls[get_next_coordinate(d, i) - 1] = 0;
  }
}

void explode() {
  for (int i = 0; i < B; i++) {
    if (balls[i] == 0) {
      continue;
    }

    if (ball_queue.empty()) {
      ball_queue.push_back({balls[i], 1});
      continue;
    }

    int value = ball_queue.back().first, count = ball_queue.back().second;
    if (value != balls[i]) {
      ball_queue.push_back({balls[i], 1});
    } else {
      ball_queue.pop_back();
      ball_queue.push_back({balls[i], count + 1});
    }
  }

  bool exploded = true;
  while (exploded) {
    exploded = false;

    while (!ball_queue.empty()) {
      int value = ball_queue.front().first, count = ball_queue.front().second;
      ball_queue.pop_front();

      if (count >= 4) {
        destroyed_balls[value] += count;
        exploded = true;
      } else {
        temp_ball_queue.push_back({value, count});
      }
    }

    while (!temp_ball_queue.empty()) {
      int value = temp_ball_queue.front().first,
          count = temp_ball_queue.front().second;
      temp_ball_queue.pop_front();

      if (ball_queue.empty()) {
        ball_queue.push_back({value, count});
        continue;
      }

      if (value == ball_queue.back().first) {
        count += ball_queue.back().second;
        ball_queue.pop_back();
        ball_queue.push_back({value, count});
      } else {
        ball_queue.push_back({value, count});
      }
    }
  }

  B = 0;
  while (!ball_queue.empty()) {
    int value = ball_queue.front().first, count = ball_queue.front().second;
    ball_queue.pop_front();

    balls[B++] = count;
    if (B == MAX_B) {
      break;
    }

    balls[B++] = value;
    if (B == MAX_B) {
      break;
    }
  }

  while (!ball_queue.empty()) {
    ball_queue.pop_back();
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

  init();

  int d, s;
  for (int m = 0; m < M; m++) {
    std::cin >> d >> s;
    remove(d - 1, s);
    explode();
  }

  int result = 0;
  for (int i = 1; i <= 3; i++) {
    result += (i * destroyed_balls[i]);
  }

  std::cout << result << '\n';

  return 0;
}
