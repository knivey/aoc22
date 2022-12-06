#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream input("input.txt");
  string line;
  long long score = 0;
  while (getline(input, line)) {
    if (line.length() < 3) {
      cout << "bad input" << endl;
      return -1;
    }
    /*
     * A for Rock, B for Paper, and C for Scissors.
     * X for Rock, Y for Paper, and Z for Scissors.
     */
    switch (line[2]) {
    case 'X':
      score += 1;
      if (line[0] == 'C')
        score += 6;
      if (line[0] == 'A')
        score += 3;
      break;
    case 'Y':
      score += 2;
      if (line[0] == 'A')
        score += 6;
      if (line[0] == 'B')
        score += 3;
      break;
    case 'Z':
      score += 3;
      if (line[0] == 'B')
        score += 6;
      if (line[0] == 'C')
        score += 3;
    }
  }
  cout << score << endl;
  return 0;
}
