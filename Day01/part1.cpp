#include <algorithm>
#include <fstream>
#include <iostream>
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

  std::cout << *std::max_element(elves.begin(), elves.end()) << std::endl;

  return 0;
}
