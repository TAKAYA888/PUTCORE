#ifndef GAME_OBJECT_PTR_H_
#define GAME_OBJECT_PTR_H_

#include <memory>

class GameObject;
using GameObjectPtr = std::weak_ptr<GameObject>;

const GameObjectPtr NULL_GAME_OBJECT = GameObjectPtr();

#endif // !GAME_OBJECT_PTR_H_