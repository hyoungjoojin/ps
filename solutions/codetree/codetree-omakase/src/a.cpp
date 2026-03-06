#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

const int MAX_N = 100001;

int L;

int N;
int current_sushi_count;
int current_customer_count;

std::unordered_map<std::string, int> name_dictionary;
int customer_position[MAX_N];
int required_sushi[MAX_N];
std::unordered_map<int, int> current_sushi[MAX_N];

std::priority_queue<std::pair<int, std::pair<int, int>>,
                    std::vector<std::pair<int, std::pair<int, int>>>,
                    std::greater<>>
    deletion_queue;

int get_name_index(std::string &name) {
  if (name_dictionary.find(name) == name_dictionary.end()) {
    name_dictionary[name] = N++;
    return name_dictionary[name];
  } else {
    return name_dictionary[name];
  }
}

void init() {
  N = 0;
  current_sushi_count = 0;
}

void turn_table(int t) {
  while (!deletion_queue.empty()) {
    int time = deletion_queue.top().first;
    if (time > t) {
      break;
    }

    int customer = deletion_queue.top().second.first,
        count = deletion_queue.top().second.second;
    deletion_queue.pop();

    required_sushi[customer] -= count;
    current_sushi_count -= count;
    if (required_sushi[customer] == 0) {
      current_customer_count--;
    }
  }
}

void insert_sushi(int t, int x, std::string &name) {
  turn_table(t);

  current_sushi_count++;

  int index = get_name_index(name);
  if (required_sushi[index] == 0) {
    int pos = (x - t + L) % L;
    current_sushi[index][pos]++;
  } else {
    deletion_queue.push(
        {t + (customer_position[index] - x + L) % L, {index, 1}});
  }
}

void insert_customer(int t, int x, std::string &name, int n) {
  turn_table(t);

  int index = get_name_index(name);
  current_customer_count++;
  customer_position[index] = x;
  required_sushi[index] = n;

  for (auto it = current_sushi[index].begin(); it != current_sushi[index].end();
       it++) {
    int initial_position = it->first, count = it->second;
    int current_location = (initial_position + t) % L;

    deletion_queue.push({t + (x - current_location + L) % L, {index, count}});
  }
}

std::pair<int, int> take_picture(int t) {
  turn_table(t);
  return {current_customer_count, current_sushi_count};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int num_queries;
  std::cin >> L >> num_queries;

  init();

  int command;
  for (int q = 1; q <= num_queries; q++) {
    std::cin >> command;

    if (command == 100) {
      int t, x;
      std::string name;
      std::cin >> t >> x >> name;
      insert_sushi(t, x, name);
    } else if (command == 200) {
      int t, x, n;
      std::string name;
      std::cin >> t >> x >> name >> n;
      insert_customer(t, x, name, n);
    } else if (command == 300) {
      int t;
      std::cin >> t;
      std::pair<int, int> result = take_picture(t);
      std::cout << result.first << ' ' << result.second << '\n';
    }
  }

  return 0;
}
