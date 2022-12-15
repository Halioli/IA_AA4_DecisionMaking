#pragma once
class Agent;
class Vector2D;

class DecisionMakingAlgorithm
{
public:
	virtual void Update(Agent* agent, float dTime, Vector2D _randomPos);
};

