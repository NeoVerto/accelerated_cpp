#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool test_condition(int x) { return x <= 5; }

int main() {
  vector<int> test{1, 2, 3, 4, 5, 6, 7, 8, 9};

  auto i = remove_if(test.begin(), test.end(), test_condition);
  for (auto t : test)
    cout << t << " ";
  cout << endl;

  test.erase(i, test.end());
  for (auto t : test)
    cout << t << " ";
  cout << endl;

  return 0;
}