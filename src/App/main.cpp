#include <Cost.h>
#include <Linear.h>
#include <Matrix.h>
#include <Network.h>
#include <ReLU.h>
#include <RootSquaredError.h>
#include <Sigmoid.h>
#include <Tanh.h>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <time.h>
#include <vector>

int main() {
  try {
    srand(time(0));

    RootSquaredError cost;
    Sigmoid hA1;
    Sigmoid oA;

    Layer hL1(4, &hA1);
    Layer oL(1, &oA);

    hL1.Init(2);
    oL.Init(hL1.GetSize());

    std::vector<Layer *> layers;

    layers.push_back(&hL1);
    layers.push_back(&oL);

    Network net(2, layers, &cost);

    std::vector<Matrix> trainingInputs(4);
    std::vector<Matrix> traningExpectations(4);

    // 0 ^ 0 = 0
    trainingInputs[0].Resize(2, 1);
    traningExpectations[0].Resize(1, 1);
    trainingInputs[0](0, 0) = 0;
    trainingInputs[0](1, 0) = 0;
    traningExpectations[0](0, 0) = 0;

    // 0 ^ 1 = 1
    trainingInputs[1].Resize(2, 1);
    traningExpectations[1].Resize(1, 1);
    trainingInputs[1](0, 0) = 0;
    trainingInputs[1](1, 0) = 1;
    traningExpectations[1](0, 0) = 1;

    // 1 ^ 1 = 0
    trainingInputs[2].Resize(2, 1);
    traningExpectations[2].Resize(1, 1);
    trainingInputs[2](0, 0) = 1;
    trainingInputs[2](1, 0) = 1;
    traningExpectations[2](0, 0) = 0;

    // 1 ^ 0 = 1
    trainingInputs[3].Resize(2, 1);
    traningExpectations[3].Resize(1, 1);
    trainingInputs[3](0, 0) = 1;
    trainingInputs[3](1, 0) = 0;
    traningExpectations[3](0, 0) = 1;

    for (size_t i = 0; i < 30000; i++) {
      int iTrainingSet = rand() % 4;
      const Matrix &trainingInput = trainingInputs[iTrainingSet];
      const Matrix &trainingExpected = traningExpectations[iTrainingSet];

      double error = net.Optimize(trainingInput, trainingExpected, 0.1, 0.75);

      if (i % 10000 == 0) {
        std::cout << std::fixed << std::setw(8) << std::right << (i / 1)
                  << std::setfill('0') << std::setprecision(3)
                  << ": ERROR: " << std::round(error * 1000) / 1000 << std::endl
                  << std::setprecision(-1) << std::defaultfloat;
        /*
std::cout << "INPUT:" << std::endl;
trainingInput.Print();
std::cout << "EXPECTED:" << std::endl;
trainingExpected.Print();
std::cout << "OUTPUT:" << std::endl;
oL.GetOutput().Print();
std::cout << std::endl << std::endl;
*/
      }
    }

    return 0;
  } catch (const std::exception &e) {
    std::cout << e.what();
  }
  return 1;
}