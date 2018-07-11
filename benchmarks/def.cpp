#include <ctime>
#include <iostream>

using time_type = std::clock_t;

class Benchmark {
  time_type start, end;
protected:
  void timer_start() { start = std::clock(); }
  void timer_stop() { end = std::clock(); }
  virtual void benchmark() = 0;
public:
  void exec() {
    benchmark();
    double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "elapsed_time: " << elapsed_time * 1000 << " ms" << std::endl;
  }
  Benchmark() : start{}, end{} { ; }
};

template<class BenchmarkClass>
void run_benchmark() { BenchmarkClass b; b.exec(); }
