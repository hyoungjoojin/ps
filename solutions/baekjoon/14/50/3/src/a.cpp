#include <iostream>

const int MAX_R = 51;
const int MAX_C = 51;

enum { WALL = 1, DIRTY = 0, CLEAN = 2 };

int R;
int C;
int grid[MAX_R][MAX_C];

int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int current_direction;
int current_r;
int current_c;

bool clean_current() {
  if (grid[current_r][current_c] == DIRTY) {
    grid[current_r][current_c] = CLEAN;
    return true;
  } else {
    return false;
  }
}

bool is_surrounding_dirty() {
  for (int di = 0; di < 4; di++) {
    int next_r = current_r + directions[di][0],
        next_c = current_c + directions[di][1];

    if (grid[next_r][next_c] == DIRTY) {
      return true;
    }
  }

  return false;
}

bool go_back() {
  int opposite_direction = (current_direction + 2) % 4;

  int next_r = current_r + directions[opposite_direction][0],
      next_c = current_c + directions[opposite_direction][1];

  if (grid[next_r][next_c] == WALL) {
    return false;
  }

  current_r = next_r;
  current_c = next_c;
  return true;
}

void turn_and_move() {
  for (int di = 1; di <= 4; di++) {
    int d = (current_direction - di + 4) % 4;

    int next_r = current_r + directions[d][0],
        next_c = current_c + directions[d][1];

    if (grid[next_r][next_c] == DIRTY) {
      current_r = next_r;
      current_c = next_c;
      current_direction = d;
      return;
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> R >> C;

  std::cin >> current_r >> current_c >> current_direction;

  int input;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      std::cin >> input;
      grid[i][j] = (input == 1 ? WALL : DIRTY);
    }
  }

  int num_cleaned = 0;
  while (true) {
    if (clean_current()) {
      num_cleaned++;
    }

    if (is_surrounding_dirty()) {
      turn_and_move();
      continue;
    }

    bool can_move = go_back();
    if (!can_move) {
      break;
    }
  }

  std::cout << num_cleaned << '\n';

  return 0;
}
