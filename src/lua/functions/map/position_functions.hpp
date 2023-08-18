/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2022 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.com/
 */

#ifndef SRC_LUA_FUNCTIONS_MAP_POSITION_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_MAP_POSITION_FUNCTIONS_HPP_

#include "lua/scripts/luascript.h"

class PositionFunctions final : LuaScriptInterface {
	public:
		static void init(lua_State* L) {
			registerClass(L, "Position", "", PositionFunctions::luaPositionCreate);
			registerMetaMethod(L, "Position", "__add", PositionFunctions::luaPositionAdd);
			registerMetaMethod(L, "Position", "__sub", PositionFunctions::luaPositionSub);
			registerMetaMethod(L, "Position", "__eq", PositionFunctions::luaPositionCompare);

			registerMethod(L, "Position", "getDistance", PositionFunctions::luaPositionGetDistance);
			registerMethod(L, "Position", "getPathTo", PositionFunctions::luaPositionGetPathTo);
			registerMethod(L, "Position", "isSightClear", PositionFunctions::luaPositionIsSightClear);

<<<<<<< HEAD
=======
			registerMethod(L, "Position", "getTile", PositionFunctions::luaPositionGetTile);
			registerMethod(L, "Position", "getZones", PositionFunctions::luaPositionGetZones);

>>>>>>> e5f44434 (feat: allow multiple zones per coordinate)
			registerMethod(L, "Position", "sendMagicEffect", PositionFunctions::luaPositionSendMagicEffect);
			registerMethod(L, "Position", "removeMagicEffect", PositionFunctions::luaPositionRemoveMagicEffect);
			registerMethod(L, "Position", "sendDistanceEffect", PositionFunctions::luaPositionSendDistanceEffect);

			registerMethod(L, "Position", "sendSingleSoundEffect", PositionFunctions::luaPositionSendSingleSoundEffect);
			registerMethod(L, "Position", "sendDoubleSoundEffect", PositionFunctions::luaPositionSendDoubleSoundEffect);

			registerMethod(L, "Position", "toString", PositionFunctions::luaPositionToString);
		}

	private:
		static int luaPositionCreate(lua_State* L);
		static int luaPositionAdd(lua_State* L);
		static int luaPositionSub(lua_State* L);
		static int luaPositionCompare(lua_State* L);

		static int luaPositionGetDistance(lua_State* L);
		static int luaPositionGetPathTo(lua_State* L);
		static int luaPositionIsSightClear(lua_State* L);

<<<<<<< HEAD
=======
		static int luaPositionGetTile(lua_State* L);
		static int luaPositionGetZones(lua_State* L);

>>>>>>> e5f44434 (feat: allow multiple zones per coordinate)
		static int luaPositionSendMagicEffect(lua_State* L);
		static int luaPositionRemoveMagicEffect(lua_State* L);
		static int luaPositionSendDistanceEffect(lua_State* L);

		static int luaPositionSendSingleSoundEffect(lua_State* L);
		static int luaPositionSendDoubleSoundEffect(lua_State* L);

		static int luaPositionToString(lua_State* L);
};

#endif
