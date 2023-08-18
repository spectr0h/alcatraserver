/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2022 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.com/
 */

#ifndef SRC_CONFIG_CONFIG_DEFINITIONS_HPP_
#define SRC_CONFIG_CONFIG_DEFINITIONS_HPP_

// Enum
enum booleanConfig_t {
	ALLOW_CHANGEOUTFIT,
	ONE_PLAYER_ON_ACCOUNT,
	AIMBOT_HOTKEY_ENABLED,
	REMOVE_RUNE_CHARGES,
	EXPERIENCE_FROM_PLAYERS,
	FREE_PREMIUM,
	REPLACE_KICK_ON_LOGIN,
	BIND_ONLY_GLOBAL_ADDRESS,
	OPTIMIZE_DATABASE,
	MARKET_PREMIUM,
	EMOTE_SPELLS,
	STAMINA_SYSTEM,
	WARN_UNSAFE_SCRIPTS,
	CONVERT_UNSAFE_SCRIPTS,
	CLASSIC_ATTACK_SPEED,
	SCRIPTS_CONSOLE_LOGS,
	REMOVE_WEAPON_AMMO,
	REMOVE_WEAPON_CHARGES,
	REMOVE_POTION_CHARGES,
	GLOBAL_SERVER_SAVE_NOTIFY_MESSAGE,
	GLOBAL_SERVER_SAVE_CLEAN_MAP,
	GLOBAL_SERVER_SAVE_CLOSE,
	GLOBAL_SERVER_SAVE_SHUTDOWN,
	FORCE_MONSTERTYPE_LOAD,
	HOUSE_OWNED_BY_ACCOUNT,
	CLEAN_PROTECTION_ZONES,
	ALLOW_BLOCK_SPAWN,
	ONLY_INVITED_CAN_MOVE_HOUSE_ITEMS,
	WEATHER_RAIN,
	WEATHER_THUNDER,
	TOGGLE_FREE_QUEST,
	ONLY_PREMIUM_ACCOUNT,
	TOGGLE_MAP_CUSTOM,
	ALL_CONSOLE_LOG,
	STAMINA_TRAINER,
	STAMINA_PZ,
	PUSH_WHEN_ATTACKING,
	SORT_LOOT_BY_CHANCE,
	TOGGLE_SAVE_INTERVAL,
	TOGGLE_SAVE_INTERVAL_CLEAN_MAP,
	PREY_ENABLED,
	PREY_FREE_THIRD_SLOT,
	TASK_HUNTING_ENABLED,
	TASK_HUNTING_FREE_THIRD_SLOT,
	STASH_MOVING,
	TOGGLE_IMBUEMENT_SHRINE_STORAGE,
	AUTOLOOT,
	AUTOBANK,
	RATE_USE_STAGES,
	INVENTORY_GLOW,
	TELEPORT_SUMMONS,
	TOGGLE_DOWNLOAD_MAP,
	USE_ANY_DATAPACK_FOLDER,
	ALLOW_RELOAD,
	BOOSTED_BOSS_SLOT,
	XP_DISPLAY_MODE,
	TOGGLE_GOLD_POUCH_ALLOW_ANYTHING,
	TOGGLE_GOLD_POUCH_QUICKLOOT_ONLY,
	TOGGLE_SERVER_IS_RETRO,
	TOGGLE_TRAVELS_FREE,
	OLD_PROTOCOL,
	TOGGLE_HAZARDSYSTEM,
	LOYALTY_ENABLED,
	PARTY_SHARE_LOOT_BOOSTS,
	RESET_SESSIONS_ON_STARTUP,
	TOGGLE_WHEELSYSTEM,
	TOGGLE_ATTACK_SPEED_ONFIST,

	VIP_SYSTEM_ENABLED,
	VIP_AUTOLOOT_VIP_ONLY,
	VIP_STAY_ONLINE,

	REWARD_CHEST_COLLECT_ENABLED,

	LAST_BOOLEAN_CONFIG
};

enum stringConfig_t {
	MAP_NAME,
	MAP_DOWNLOAD_URL,
	MAP_AUTHOR,
	HOUSE_RENT_PERIOD,
	SERVER_NAME,
	SERVER_MOTD,
	OWNER_NAME,
	OWNER_EMAIL,
	URL,
	LOCATION,
	IP,
	WORLD_TYPE,
	MYSQL_HOST,
	MYSQL_USER,
	MYSQL_PASS,
	MYSQL_DB,
	MYSQL_SOCK,
	AUTH_TYPE,
	DEFAULT_PRIORITY,
	STORE_IMAGES_URL,
	MAP_CUSTOM_NAME,
	MAP_CUSTOM_AUTHOR,
	DISCORD_WEBHOOK_URL,
	DISCORD_WEBHOOK_LOGO_URL,
	SAVE_INTERVAL_TYPE,
	GLOBAL_SERVER_SAVE_TIME,
	DATA_DIRECTORY,
	CORE_DIRECTORY,
	FORGE_FIENDISH_INTERVAL_TYPE,
	FORGE_FIENDISH_INTERVAL_TIME,
	TIBIADROME_CONCOCTION_TICK_TYPE,
	M_CONST,

	LAST_STRING_CONFIG
};

enum integerConfig_t {
	SQL_PORT,
	MAX_PLAYERS,
	PZ_LOCKED,
	DEFAULT_DESPAWNRANGE,
	DEFAULT_DESPAWNRADIUS,
	RATE_EXPERIENCE,
	RATE_SKILL,
	RATE_LOOT,
	RATE_MAGIC,
	RATE_SPAWN,
	RATE_KILLING_IN_THE_NAME_OF_POINTS,
	HOUSE_PRICE,
	HOUSE_BUY_LEVEL,
	MAX_MESSAGEBUFFER,
	ACTIONS_DELAY_INTERVAL,
	EX_ACTIONS_DELAY_INTERVAL,
	KICK_AFTER_MINUTES,
	PROTECTION_LEVEL,
	DEATH_LOSE_PERCENT,
	STATUSQUERY_TIMEOUT,
	FRAG_TIME,
	WHITE_SKULL_TIME,
	GAME_PORT,
	LOGIN_PORT,
	STATUS_PORT,
	STAIRHOP_DELAY,
	MAX_CONTAINER,
	MAX_ITEM,
	MARKET_OFFER_DURATION,
	DEPOT_BOXES,
	FREE_DEPOT_LIMIT,
	PREMIUM_DEPOT_LIMIT,
	CHECK_EXPIRED_MARKET_OFFERS_EACH_MINUTES,
	MAX_MARKET_OFFERS_AT_A_TIME_PER_PLAYER,
	EXP_FROM_PLAYERS_LEVEL_RANGE,
	MAX_PACKETS_PER_SECOND,
	COMPRESSION_LEVEL,
	STORE_COIN_PACKET,
	DAY_KILLS_TO_RED,
	WEEK_KILLS_TO_RED,
	MONTH_KILLS_TO_RED,
	RED_SKULL_DURATION,
	BLACK_SKULL_DURATION,
	ORANGE_SKULL_DURATION,
	GLOBAL_SERVER_SAVE_NOTIFY_DURATION,
	PUSH_DELAY,
	PUSH_DISTANCE_DELAY,
	STASH_ITEMS,
	PARTY_LIST_MAX_DISTANCE,
	STAMINA_ORANGE_DELAY,
	STAMINA_GREEN_DELAY,
	STAMINA_TRAINER_DELAY,
	STAMINA_PZ_GAIN,
	STAMINA_TRAINER_GAIN,
	SAVE_INTERVAL_TIME,
	PREY_REROLL_PRICE_LEVEL,
	PREY_SELECTION_LIST_PRICE,
	PREY_BONUS_TIME,
	PREY_BONUS_REROLL_PRICE,
	PREY_FREE_REROLL_TIME,
	TASK_HUNTING_LIMIT_EXHAUST,
	TASK_HUNTING_REROLL_PRICE_LEVEL,
	TASK_HUNTING_SELECTION_LIST_PRICE,
	TASK_HUNTING_BONUS_REROLL_PRICE,
	TASK_HUNTING_FREE_REROLL_TIME,
	MAX_ALLOWED_ON_A_DUMMY,
	FREE_QUEST_STAGE,
	DEPOTCHEST,
	CRITICALCHANCE,
	ADVENTURERSBLESSING_LEVEL,
	FORGE_MAX_ITEM_TIER,
	FORGE_COST_ONE_SLIVER,
	FORGE_SLIVER_AMOUNT,
	FORGE_CORE_COST,
	FORGE_MAX_DUST,
	FORGE_FUSION_DUST_COST,
	FORGE_TRANSFER_DUST_COST,
	FORGE_BASE_SUCCESS_RATE,
	FORGE_BONUS_SUCCESS_RATE,
	FORGE_TIER_LOSS_REDUCTION,
	FORGE_AMOUNT_MULTIPLIER,
	FORGE_MIN_SLIVERS,
	FORGE_MAX_SLIVERS,
	FORGE_INFLUENCED_CREATURES_LIMIT,
	FORGE_FIENDISH_CREATURES_LIMIT,
	BESTIARY_KILL_MULTIPLIER,
	BOSSTIARY_KILL_MULTIPLIER,
	BOOSTED_BOSS_LOOT_BONUS,
	BOOSTED_BOSS_KILL_BONUS,
	FAMILIAR_TIME,
	BUY_AOL_COMMAND_FEE,
	BUY_BLESS_COMMAND_FEE,
	HAZARD_CRITICAL_INTERVAL,
	HAZARD_CRITICAL_CHANCE,
	HAZARD_CRITICAL_MULTIPLIER,
	HAZARD_DAMAGE_MULTIPLIER,
	HAZARD_DODGE_MULTIPLIER,
	HAZARD_PODS_DROP_MULTIPLIER,
	HAZARD_PODS_TIME_TO_DAMAGE,
	HAZARD_EXP_BONUS_MULTIPLIER,
	HAZARD_LOOT_BONUS_MULTIPLIER,
	HAZARD_PODS_DAMAGE,
	HAZARD_PODS_TIME_TO_SPAWN,
	HAZARD_SPAWN_PLUNDER_MULTIPLIER,
	LOW_LEVEL_BONUS_EXP,
	LOYALTY_POINTS_PER_CREATION_DAY,
	LOYALTY_POINTS_PER_PREMIUM_DAY_SPENT,
	LOYALTY_POINTS_PER_PREMIUM_DAY_PURCHASED,
	WHEEL_POINTS_PER_LEVEL,
	MULTIPLIER_ATTACKONFIST,
	MAX_SPEED_ATTACKONFIST,
	TIBIADROME_CONCOCTION_COOLDOWN,
	TIBIADROME_CONCOCTION_DURATION,
	T_CONST,
	PARALLELISM,
	BOSS_DEFAULT_TIME_TO_FIGHT_AGAIN,
	BOSS_DEFAULT_TIME_TO_DEFEAT,

	VIP_BONUS_EXP,
	VIP_BONUS_LOOT,
	VIP_BONUS_SKILL,
	VIP_FAMILIAR_TIME_COOLDOWN_REDUCTION,

	REWARD_CHEST_MAX_COLLECT_ITEMS,
	DISCORD_WEBHOOK_DELAY_MS,

	LAST_INTEGER_CONFIG
};

enum floatingConfig_t {
	BESTIARY_RATE_CHARM_SHOP_PRICE,

	RATE_HEALTH_REGEN,
	RATE_HEALTH_REGEN_SPEED,
	RATE_MANA_REGEN,
	RATE_MANA_REGEN_SPEED,
	RATE_SOUL_REGEN,
	RATE_SOUL_REGEN_SPEED,

	RATE_SPELL_COOLDOWN,
	RATE_ATTACK_SPEED,
	RATE_OFFLINE_TRAINING_SPEED,
	RATE_EXERCISE_TRAINING_SPEED,

	RATE_MONSTER_HEALTH,
	RATE_MONSTER_ATTACK,
	RATE_MONSTER_DEFENSE,
	RATE_BOSS_HEALTH,
	RATE_BOSS_ATTACK,
	RATE_BOSS_DEFENSE,

	RATE_NPC_HEALTH,
	RATE_NPC_ATTACK,
	RATE_NPC_DEFENSE,
	LOYALTY_BONUS_PERCENTAGE_MULTIPLIER,
	PARTY_SHARE_LOOT_BOOSTS_DIMINISHING_FACTOR,

	LAST_FLOATING_CONFIG
};

#endif // SRC_CONFIG_CONFIG_DEFINITIONS_HPP_
