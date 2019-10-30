#include <Cost.h>
#include <HiddenLayer.h>
#include <InputLayer.h>
#include <Matrix.h>
#include <MeanSquareError.h>
#include <OutputLayer.h>
#include <Sigmoid.h>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  try {

    MeanSquareError mse();
    //  Cost cost = (Cost)mse;
    InputLayer in(2);
    // OutputLayer ot(1, 2, sig);

    return 0;
  } catch (const std::exception &e) {
    std::cout << e.what();
  }
  return 1;
}