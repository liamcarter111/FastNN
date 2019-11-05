#include "OutputLayer.h"
#include <Matrix.h>

OutputLayer::OutputLayer(const int size, const int previousLayerSize,
                         Activation *activation)
    : Layer(size), BackwardLayer(size, previousLayerSize, activation) {}