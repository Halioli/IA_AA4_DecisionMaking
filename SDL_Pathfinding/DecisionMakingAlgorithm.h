#pragma once
class Agent;
class Grid;

class DecisionMakingAlgorithm
{
public:
	virtual void Update(Agent* agent, float dTime, Grid* _maze);
};

