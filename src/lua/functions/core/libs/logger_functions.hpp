/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2022 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.com/
 */

#ifndef SRC_LUA_FUNCTIONS_CORE_LIBS_LOGGER_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_CORE_LIBS_LOGGER_FUNCTIONS_HPP_

#include "lua/scripts/luascript.h"

class LoggerFunctions final : public LuaScriptInterface {
	public:
		static void init(lua_State* L);

	private:
		static int luaSpdlogDebug(lua_State* L);
		static int luaSpdlogError(lua_State* L);
		static int luaSpdlogInfo(lua_State* L);
		static int luaSpdlogWarn(lua_State* L);

		static int luaLoggerDebug(lua_State* L);
		static int luaLoggerError(lua_State* L);
		static int luaLoggerInfo(lua_State* L);
		static int luaLoggerWarn(lua_State* L);
};

#endif // SRC_LUA_FUNCTIONS_CORE_LIBS_LOGGER_FUNCTIONS_HPP_
