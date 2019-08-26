#pragma once

#include <TktkClassFuncProcessor/ClassFuncProcessor.h>
#include "../Enums/CollisionGroup.h"

// 衝突判定のグループを設定する
struct CollisionGroupSetter
{
	static void set()
	{
		// 衝突判定を設定する
		ClassFuncProcessor::addCollisionGroup(COLLISION_GROUP_NONE);
		ClassFuncProcessor::addCollisionGroup(COLLISION_GROUP_CURSOR);
		ClassFuncProcessor::addCollisionGroup(COLLISION_GROUP_MENU_ITEM);
		ClassFuncProcessor::addCollisionGroup(COLLISION_GROUP_PLAYER);
		ClassFuncProcessor::addCollisionGroup(COLLISION_GROUP_ENEMY);
		ClassFuncProcessor::addCollisionGroup(COLLISION_GROUP_PLAYER_BULLET);
		ClassFuncProcessor::addCollisionGroup(COLLISION_GROUP_ENEMY_BULLET);
		ClassFuncProcessor::addCollisionGroup(COLLISION_GROUP_CORE_BULLET);
		ClassFuncProcessor::addCollisionGroup(COLLISION_GROUP_CORE);


		// 衝突判定を行う組み合わせを設定する
		ClassFuncProcessor::addCollisionGroupPair(COLLISION_GROUP_CURSOR, COLLISION_GROUP_MENU_ITEM);
		ClassFuncProcessor::addCollisionGroupPair(COLLISION_GROUP_PLAYER, COLLISION_GROUP_ENEMY);
		ClassFuncProcessor::addCollisionGroupPair(COLLISION_GROUP_PLAYER, COLLISION_GROUP_ENEMY_BULLET);
		ClassFuncProcessor::addCollisionGroupPair(COLLISION_GROUP_ENEMY, COLLISION_GROUP_PLAYER_BULLET);
		ClassFuncProcessor::addCollisionGroupPair(COLLISION_GROUP_ENEMY, COLLISION_GROUP_CORE_BULLET);
		ClassFuncProcessor::addCollisionGroupPair(COLLISION_GROUP_ENEMY_BULLET, COLLISION_GROUP_CORE);
		ClassFuncProcessor::addCollisionGroupPair(COLLISION_GROUP_ENEMY, COLLISION_GROUP_CORE);
	}
};