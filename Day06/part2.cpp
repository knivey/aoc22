#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream input;
  if (argc > 1)
    input = ifstream(argv[1]);
  else
    input = ifstream("input.txt");
  char chars[14];
  int count = 0;
  char c;
  while (input.get(c)) {
    if (count < sizeof(chars)) {
      chars[count++] = c;
      continue;
    }
    chars[count++ % sizeof(chars)] = c;
    for (int i = 0; i < sizeof(chars); ++i) {
      for (int j = i + 1; j < sizeof(chars); ++j) {
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
