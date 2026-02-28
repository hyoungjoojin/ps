#include <iostream>
#include <queue>

const int MAX_N = 55;

struct Fireball {
  int k;
  int m;
  int s;
  int d;

  bool operator<(const Fireball &comp) const { return k > comp.k; }
};

int k;
int N;
std::priority_queue<Fireball> grid[MAX_N][MAX_N];

int directions[8][2] = {
    {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1},
};

void move() {
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      while (!grid[r][c].empty()) {
        Fireball fireball = grid[r][c].top();
        if (fireball.k > k) {
          break;
        }

        grid[r][c].pop();

        int next_r = r + directions[fireball.d][0] * fireball.s,
            next_c = c + directions[fireball.d][1] * fireball.s;

        next_r = ((next_r % N) + N) % N;
        next_c = ((next_c % N) + N) % N;

        grid[next_r][next_c].push({k + 1, fireball.m, fireball.s, fireball.d});
      }
    }
  }
}

void create() {
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (grid[r][c].size() < 2) {
        continue;
      }

      int m = 0, s = 0, count = grid[r][c].size();
      int d = 0;

      while (!grid[r][c].empty()) {
        m += grid[r][c].top().m;
        s += grid[r][c].top().s;
        d += (grid[r][c].top().d % 2);
        grid[r][c].pop();
      }

      m /= 5;
      s /= count;

      if (m > 0) {
        for (int i = ((d == 0 || d == count) ? 0 : 1); i < 8; i += 2) {
          grid[r][c].push({k + 1, m, s, i});
        }
      }
    }
  }
}

int get_sum() {
  int result = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      while (!grid[i][j].empty()) {
        result += grid[i][j].top().m;
        grid[i][j].pop();
      }
    }
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> N;

  int num_fireballs, K;
  std::cin >> num_fireballs >> K;

  int r, c, m, s, d;
  for (int i = 0; i < num_fireballs; i++) {
    std::cin >> r >> c >> m >> s >> d;

    grid[r - 1][c - 1].push({.k = 0, .m = m, .s = s, .d = d});
  }

  for (k = 0; k < K; k++) {
    move();
    create();
  }

  std::cout << get_sum() << '\n';

  return 0;
}
