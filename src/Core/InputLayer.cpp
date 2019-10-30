#include "InputLayer.h"
#include <cstring>

InputLayer::InputLayer(const int size) : Layer(size), ForwardLayer(size) {}