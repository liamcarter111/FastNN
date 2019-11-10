#include <Matrix.h>
#include <Network.h>
#include <Sigmoid.h>
#include <SquaredError.h>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <time.h>
#include <vector>

int main() {
  try {
    srand(time(0));

    SquaredError cost;
    Sigmoid hA1;
    Sigmoid oA;

    Layer hL1(2, &hA1);
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

    double accumulated_error = 0.0;
    double error_threshold = 1e-5;

    size_t i;

    auto start = std::chrono::system_clock::now();

    for (i = 0; i < 100000; ++i) {
      int iTrainingSet = rand() % 4;
      const Matrix &trainingInput = trainingInputs[iTrainingSet];
      const Matrix &trainingExpected = traningExpectations[iTrainingSet];

      const float error =
          net.Optimize(trainingInput, trainingExpected, 0.1, 0.5);
      accumulated_error += error;
    }

    auto now = std::chrono::system_clock::now();

    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(now - start)
            .count();

    std::cout << std::endl
              << std::endl
              << std::endl
              << "Iterations:" << i << std::endl
              << "FINAL MODDEL ERROR: " << accumulated_error / i << std::endl
              << " Took: " << duration << "ms";

    return 0;
  } catch (const std::exception &e) {
    std::cout << e.what();
  }
  return 1;
}