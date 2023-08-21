/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2022 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.com/
 */

#ifndef SRC_SERVER_NETWORK_WEBHOOK_WEBHOOK_H_
#define SRC_SERVER_NETWORK_WEBHOOK_WEBHOOK_H_

<<<<<<< HEAD
<<<<<<< HEAD
class WebHook {
	public:
#if defined(WIN32)
		static void closeConnection(HINTERNET hSession = nullptr, HINTERNET hConnect = nullptr, HINTERNET hRequest = nullptr);
#endif
		static void sendMessage(std::string title, std::string message, int color);
		static std::string getPayload(std::string title, std::string message, int color);
};
=======
=======
>>>>>>> ccbca850 (Merge branch 'main' into shared-3)
#include "lib/thread/thread_pool.hpp"

struct WebhookTask {
		std::string payload;
		std::string url;
};

class Webhook {
	public:
		static constexpr size_t DEFAULT_DELAY_MS = 1000;

		explicit Webhook(ThreadPool &threadPool);

		// Singleton - ensures we don't accidentally copy it
		Webhook(const Webhook &) = delete;
		void operator=(const Webhook &) = delete;

		static Webhook &getInstance();

		void run();

		void sendMessage(const std::string payload, std::string url);
		void sendMessage(const std::string title, const std::string message, int color, std::string url = "");

	private:
		std::mutex taskLock;
		ThreadPool &threadPool;
		std::deque<std::shared_ptr<WebhookTask>> webhooks;
		curl_slist* headers = nullptr;

		void sendWebhook();

		int sendRequest(const char* url, const char* payload, std::string* response_body) const;
		static size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp);
		std::string getPayload(const std::string title, const std::string message, int color) const;
};

constexpr auto g_webhook = Webhook::getInstance;
<<<<<<< HEAD
>>>>>>> e5583095 (improve: run webhook within the thread pool (#1384))
=======
>>>>>>> ccbca850 (Merge branch 'main' into shared-3)

#endif // SRC_SERVER_NETWORK_WEBHOOK_WEBHOOK_H_
