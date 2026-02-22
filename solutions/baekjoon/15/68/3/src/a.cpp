#include <algorithm>
#include <iostream>
#include <limits>

const int MAX_R = 9;
const int MAX_C = 9;
const int MAX_CAMERAS = 9;

enum { EMPTY = 1, WALL = 2, FILLED = 3, CAMERA = 4 };

int R;
int C;
int grid[MAX_R][MAX_C];

int empty_spots;
int temp[MAX_R][MAX_C];

struct Camera {
  int type;
  int r;
  int c;
};

int num_cameras;
Camera cameras[MAX_CAMERAS];

int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int camera_directions[6][4][4] = {
    {-1},
    {{0, -1, -1, -1}, {1, -1, -1, -1}, {2, -1, -1, -1}, {3, -1, -1, -1}},
    {{0, 2, -1, -1}, {1, 3, -1, -1}, {-1}, {-1}},
    {{0, 1, -1, -1}, {1, 2, -1, -1}, {2, 3, -1, -1}, {3, 0, -1, -1}},
    {{0, 1, 2, -1}, {1, 2, 3, -1}, {2, 3, 0, -1}, {3, 0, 1, -1}},
    {{0, 1, 2, 3}, {-1}, {-1}, {-1}},
};
int selected_directions[MAX_CAMERAS];

int get_blind_spot_size() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      temp[i][j] = grid[i][j];
    }
  }

  int count = empty_spots;

  for (int i = 0; i < num_cameras; i++) {
    for (int j = 0; j < 4; j++) {
      int d = camera_directions[cameras[i].type][selected_directions[i]][j];
      if (d == -1) {
        break;
      }

      int r = cameras[i].r, c = cameras[i].c;
      while (true) {
        r += directions[d][0], c += directions[d][1];
        if (r < 0 || r >= R || c < 0 || c >= C || temp[r][c] == WALL) {
          break;
        }

        if (temp[r][c] == EMPTY) {
          temp[r][c] = FILLED;
          count--;
        }
      }
    }
  }

  return count;
}

int _get_minimum_blind_spot_size_recursive(int i) {
  if (i == num_cameras) {
    return get_blind_spot_size();
  }

  int result = std::numeric_limits<int>::max();

  for (int di = 0; di < 4; di++) {
    if (camera_directions[cameras[i].type][di][0] == -1) {
      break;
    }

    selected_directions[i] = di;
    result = std::min(result, _get_minimum_blind_spot_size_recursive(i + 1));
  }

  return result;
}

int get_minimum_blind_spot_size() {
  return _get_minimum_blind_spot_size_recursive(0);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> R >> C;

  empty_spots = 0;
  num_cameras = 0;

  int input;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      std::cin >> input;

      if (input == 0) {
        grid[i][j] = EMPTY;
        empty_spots++;
      } else if (input == 6) {
        grid[i][j] = WALL;
      } else {
        cameras[num_cameras++] = {input, i, j};
        grid[i][j] = CAMERA;
      }
    }
  }

  std::cout << get_minimum_blind_spot_size() << '\n';

  return 0;
}
