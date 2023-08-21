/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2022 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.com/
 */

#ifndef SRC_CANARY_SERVER_HPP_
#define SRC_CANARY_SERVER_HPP_

#include "security/rsa.h"
#include "server/server.h"

class Logger;

class FailedToInitializeCanary : public std::exception {
	private:
		std::string message;

	public:
		// Constructor accepts a specific message
		explicit FailedToInitializeCanary(const std::string &msg) :
			message("Canary load couldn't be completed. " + msg) { }

		// Override the what() method from std::exception
		const char* what() const noexcept override {
			return message.c_str();
		}
};

class CanaryServer {
	public:
		explicit CanaryServer(
			Logger &logger,
			RSA &rsa,
			ServiceManager &serviceManager
		);

		int run();

	private:
		RSA &rsa;
		Logger &logger;
		ServiceManager &serviceManager;

		std::mutex loaderLock;
		std::condition_variable loaderSignal;
		std::unique_lock<std::mutex> loaderUniqueLock;

		bool loaderDone = false;
		bool loadFailed = false;

		void logInfos();

		static void toggleForceCloseButton();

		static void badAllocationHandler();

		static void shutdown();

		static std::string getCompiler();

		static std::string getPlatform();

		void loadConfigLua();

		void initializeDatabase();

		void loadModules();

		void setWorldType();

		void loadMaps();

		void setupHousesRent();

		void modulesLoadHelper(bool loaded, std::string moduleName);
};

#endif // SRC_CANARY_SERVER_HPP_
