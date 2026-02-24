#include <iostream>
#include <string>
#include <utility>

const int MAX_R = 26;
const int MAX_C = 26;

enum {
  BLOCK_CROSS = 0,
  BLOCK_VERTICAL = 5,
  BLOCK_HORIZONTAL = 6,
  EMPTY = 8,
  START = 9,
  END = 10
};

char BLOCKS[7] = {'+', '1', '2', '3', '4', '|', '-'};

int R;
int C;
int num_pipes;
int grid[MAX_R][MAX_C];

int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

std::pair<int, int> start;

struct Result {
  int r;
  int c;
  int block;
};

int get_output_dir(int type, int input_dir) {
  if (type == BLOCK_CROSS) {
    return input_dir;
  }

  if (type == BLOCK_VERTICAL) {
    if (input_dir == 1 || input_dir == 3) {
      return -1;
    } else {
      return input_dir;
    }
  }

  if (type == BLOCK_HORIZONTAL) {
    if (input_dir == 0 || input_dir == 2) {
      return -1;
    } else {
      return input_dir;
    }
  }

  switch (type) {
  case 1:
    return (input_dir == 0 ? 1 : input_dir == 3 ? 2 : -1);

  case 2:
    return (input_dir == 2 ? 1 : input_dir == 3 ? 0 : -1);

  case 3:
    return (input_dir == 1 ? 0 : input_dir == 2 ? 3 : -1);

  case 4:
    return (input_dir == 1 ? 2 : input_dir == 0 ? 3 : -1);

  default:
    return -1;
  }
}

bool test() {
  for (int di = 0; di < 4; di++) {
    int x = start.first, y = start.second, d = di;
    int found_pipes = 0;

    while (true) {
      int next_x = x + directions[d][0], next_y = y + directions[d][1];
      if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C) {
        break;
      }

      x = next_x, y = next_y;

      if (grid[x][y] == END && found_pipes == num_pipes) {
        return true;
      }

      found_pipes++;

      d = get_output_dir(grid[x][y], d);
      if (d == -1) {
        break;
      }
    }
  }

  return false;
}

Result get_missing_block() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      int current = grid[i][j];
      if (current != EMPTY) {
        continue;
      }

      for (int t = 0; t < 7; t++) {
        if (t == BLOCK_CROSS) {
          num_pipes++;
        }

        grid[i][j] = t;
        if (test()) {
          return {i, j, t};
        }

        if (t == BLOCK_CROSS) {
          num_pipes--;
        }
      }

      grid[i][j] = current;
    }
  }

  return {-1, -1};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> R >> C;
  num_pipes = 1;

  std::string line;

  for (int i = 0; i < R; i++) {
    std::cin >> line;

    for (int j = 0; j < C; j++) {
      switch (line[j]) {
      case 'M':
        start = {i, j};
        grid[i][j] = START;
        break;

      case 'Z':
        grid[i][j] = END;
        break;

      case '.':
        grid[i][j] = EMPTY;
        break;

      case '|':
        grid[i][j] = BLOCK_VERTICAL;
        break;

      case '-':
        grid[i][j] = BLOCK_HORIZONTAL;
        break;

      case '+':
        grid[i][j] = BLOCK_CROSS;
        break;

      default:
        grid[i][j] = line[j] - '0';
        break;
      }

      if (grid[i][j] == BLOCK_CROSS) {
        num_pipes += 2;
      } else if (grid[i][j] != EMPTY && grid[i][j] != START &&
                 grid[i][j] != END) {
        num_pipes++;
      }
    }
  }

  Result result = get_missing_block();
  std::cout << result.r + 1 << ' ' << result.c + 1 << ' '
            << BLOCKS[result.block] << '\n';

  return 0;
}
