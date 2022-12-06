#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream input;
  if (argc > 1)
    input = ifstream(argv[1]);
  else
    input = ifstream("input.txt");
  string line;
  long long score = 0;
  while (getline(input, line)) {
    if (line.length() < 3) {
      cout << "bad input" << endl;
      return -1;
    }
    /*
     * A for Rock, B for Paper, and C for Scissors.
     * 1 for Rock, 2 for Paper, and 3 for Scissors
     * X means you need to lose
     * Y means you need to end the round in a draw,
     * Z means you need to win.
     */
    switch (line[2]) {
    case 'X':
      //      score += 1;
      score += ((line[0] - 'A') + 2) % 3;
      break;
    case 'Y':
      score += 3;
      score += (line[0] - 'A');
      break;
    case 'Z':
      score += 6;
      score += ((line[0] - 'A') + 1) % 3;
    }
    score++;
  }
  cout << score << endl;
  return 0;
}
