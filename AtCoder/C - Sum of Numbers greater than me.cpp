#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int int_result = max(10, 20);
  cout << "Maximum is: " << int_result << endl;

  char char_result = max('a', 'b');
  cout << "Maximum is: " << char_result;
  return 0;
}
