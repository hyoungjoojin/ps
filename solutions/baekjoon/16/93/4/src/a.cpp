#include <iostream>
#include <string>

struct Trie {
  Trie *children[26];
  int count;
  bool terminal;

  Trie() {
    count = 0;
    terminal = false;

    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }

  ~Trie() {
    for (int i = 0; i < 26; i++) {
      if (children[i] != nullptr) {
        delete children[i];
      }
    }
  }

  void _get_nickname_recursive(std::string &name, int start,
                               std::string &result, bool finished) {
    if (start == name.size()) {
      this->count++;
      if (this->count > 1) {
        result += std::to_string(this->count);
      }

      return;
    }

    int next = name[start] - 'a';
    if (this->children[next] == nullptr) {
      this->children[next] = new Trie();

      if (!finished) {
        result += name[start];
        finished = true;
      }
    }

    if (!finished) {
      result += name[start];
    }

    this->children[next]->_get_nickname_recursive(name, start + 1, result,
                                                  finished);
  }

  std::string get_nickname(std::string &name) {
    std::string result = "";
    _get_nickname_recursive(name, 0, result, false);
    return result;
  }
};

Trie trie;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N;
  std::cin >> N;

  std::string name;
  for (int i = 0; i < N; i++) {
    std::cin >> name;
    std::cout << trie.get_nickname(name) << '\n';
  }

  return 0;
}
