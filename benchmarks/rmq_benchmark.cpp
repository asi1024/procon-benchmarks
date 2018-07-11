#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

#include "rmq.cpp"
#include "def.cpp"

class RMQ_bench : public Benchmark {
  void benchmark() override {
    std::mt19937 mt(0);
    const uint32_t size = 1 << 20;
    const uint32_t query_num = 1 << 24;
    const uint32_t mask = size - 1;
    uint32_t res = 0;

    timer_start();

    RangeMinimumQuery rmq(size);

    for (std::uint32_t i = 0; i < query_num; ++i) {
      if (mt() & 1) {
        uint32_t pos = mt() & mask;
        int32_t value = mt();
        rmq.update(pos, value);
      }
      else {
        uint32_t l = mt() & mask;
        uint32_t r = mt() & mask;
        if (l > r) std::swap(l, r);
        ++r;
        res ^= rmq.query(l, r);
      }
    }

    timer_stop();
    assert(res == 76257153);
  }
};
