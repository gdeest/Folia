#include "Step.h"

Step::Step()
{
}

Step::Step(int i, int j, int direction)
{
	this->direction = direction;
	this->pos[0] = i;
	this->pos[1] = i;
}

Step::~Step()
{
	delete this;
}
