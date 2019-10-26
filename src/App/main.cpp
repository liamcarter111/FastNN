#include <ForwardLayer.h>
#include <InputLayer.h>
#include <Matrix.h>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  try {
    std::vector<float> test;

    InputLayer layer(test);

    return 0;
  } catch (const std::exception &e) {
    std::cout << e.what();
  }
  return 1;
}