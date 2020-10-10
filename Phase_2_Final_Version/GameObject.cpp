#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

bool GameObject::IsOverLapping(GameObject *newObj)const
{
	return 1;
}
GameObject::~GameObject()
{
}

