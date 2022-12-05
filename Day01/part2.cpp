#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::ifstream input("input.txt");
  std::string line;
  std::vector<int> elves;
  elves.emplace_back(0);
  while (std::getline(input, line)) {
    if (line.empty()) { // next elf
      elves.emplace_back(0);
      continue;
    }
    elves.back() += std::stoi(line);
  }

  std::sort(elves.begin(), elves.end());
  unsigned long long cals = 0;
  for (auto i = elves.end() - 1; i > elves.end() - 4; --i) {
    cals += *i;
  }
  std::cout << cals << std::endl;

  return 0;
}
