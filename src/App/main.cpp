#include <Cost.h>
#include <HalfSquaredError.h>
#include <HiddenLayer.h>
#include <InputLayer.h>
#include <Linear.h>
#include <Matrix.h>
#include <Network.h>
#include <OutputLayer.h>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  try {
    Cost cost = HalfSquaredError();
    Activation hA = Linear();
    Activation oA = Linear();
    InputLayer iL(2);
    HiddenLayer hL(2, 2, hA);
    OutputLayer oL(1, 2, oA);

    std::vector<HiddenLayer> hiddenLayers({hL});

    Network net(iL, hiddenLayers, oL, cost);

    int iterations = 1000;

    while (--iterations) {
      // net.ForwardProp();
    }

    return 0;
  } catch (const std::exception &e) {
    std::cout << e.what();
  }
  return 1;
}