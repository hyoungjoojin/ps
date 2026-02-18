#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int MAX_PEOPLE = 200001;

int num_people;
int start[MAX_PEOPLE];
int end[MAX_PEOPLE];

int rooms[MAX_PEOPLE];

std::priority_queue<std::pair<std::pair<int, int>, int>,
                    std::vector<std::pair<std::pair<int, int>, int>>,
                    std::greater<>>
    next_person;

std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                    std::greater<>>
    current_rooms;

int get_rooms() {
  for (int i = 0; i < num_people; i++) {
    next_person.push({{start[i], end[i]}, i});
  }

  int num_rooms = 0;

  while (!next_person.empty()) {
    int s = next_person.top().first.first, e = next_person.top().first.second,
        id = next_person.top().second;
    next_person.pop();

    int room_index;

    if (!current_rooms.empty() && current_rooms.top().first < s) {
      room_index = current_rooms.top().second;
      current_rooms.pop();
    } else {
      room_index = ++num_rooms;
    }

    rooms[id] = room_index;
    current_rooms.push({e, room_index});
  }

  return num_rooms;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> num_people;

  for (int i = 0; i < num_people; i++) {
    std::cin >> start[i] >> end[i];
  }

  int num_rooms = get_rooms();

  std::cout << num_rooms << '\n';
  for (int i = 0; i < num_people; i++) {
    std::cout << rooms[i] << ' ';
  }

  return 0;
}
