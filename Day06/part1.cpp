#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream input;
  if (argc > 1)
    input = ifstream(argv[1]);
  else
    input = ifstream("input.txt");
  char chars[4];
  int count = 0;
  char c;
  while (input.get(c)) {
    if (count < 4) {
      chars[count++] = c;
      continue;
    }
    chars[count++ % 4] = c;
    for (int i = 0; i < 4; ++i) {
      for (int j = i + 1; j < 4; ++j) {
        if (chars[j] == chars[i])
          goto next;
      }
    }
    cout << count << endl;
    return 0;
  next:
    continue;
  }
  cout << "none" << endl;
  return 0;
}
