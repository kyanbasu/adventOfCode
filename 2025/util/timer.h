#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer
{
public:
  Timer() : start(std::chrono::high_resolution_clock::now()) {}

  void reset()
  {
    start = std::chrono::high_resolution_clock::now();
  }

  // Returns time in miliseconds
  double elapsed()
  {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff = end - start;
    return diff.count();
  }

private:
  std::chrono::high_resolution_clock::time_point start;
};

#endif // TIMER_H
