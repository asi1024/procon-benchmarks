#include <algorithm>
#include <climits>
#include <vector>

class RangeMinimumQuery {
  std::vector<int> data;
public:
  RangeMinimumQuery(int size) : data(size, INT_MAX) { ; }
  void update(int pos, int value) { data[pos] = value; }
  int query(int l, int r) const {
    return *std::min_element(begin(data) + l, begin(data) + r);
  }
};
