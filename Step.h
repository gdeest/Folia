#ifndef STEP_H_
#define STEP_H_

class Step
{
public:
	Step();
	Step(int direction, int i, int j);
	virtual ~Step();
	
	//Attributes
	int direction;
	int pos[2];
};

#endif /*STEP_H_*/
