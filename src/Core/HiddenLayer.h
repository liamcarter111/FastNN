#pragma once
#include "BackwardLayer.h"
#include "ForwardLayer.h"

class HiddenLayer : public ForwardLayer, public BackwardLayer {};