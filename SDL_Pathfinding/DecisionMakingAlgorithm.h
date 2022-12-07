#pragma once
class Agent;

class DecisionMakingAlgorithm
{
public:
	virtual void Update(Agent* agent, float dTime);
};

