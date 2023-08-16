/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (©) 2019-2022 OpenTibiaBR <opentibiabr@outlook.com>
 * Repository: https://github.com/opentibiabr/canary
 * License: https://github.com/opentibiabr/canary/blob/main/LICENSE
 * Contributors: https://github.com/opentibiabr/canary/graphs/contributors
 * Website: https://docs.opentibiabr.com/
 */

#include "pch.hpp"

#include "server/network/webhook/webhook.h"
#include "config/configmanager.h"
#include "core.hpp"

#ifdef _MSC_VER
void WebHook::closeConnection(HINTERNET hSession /* = nullptr*/, HINTERNET hConnect /* = nullptr*/, HINTERNET hRequest /* = nullptr*/) {
	InternetCloseHandle(hSession);
	InternetCloseHandle(hConnect);
	InternetCloseHandle(hRequest);
}
#endif

<<<<<<< HEAD
void WebHook::sendMessage(std::string title, std::string message, int color) {
	std::string webhookUrl = g_configManager().getString(DISCORD_WEBHOOK_URL);
	std::string payload = getPayload(title, message, color);
	// Break empty informations
	if (title.empty() || message.empty() || webhookUrl.empty() || payload.empty()) {
		return;
	}

#ifdef _MSC_VER
	HINTERNET hSession = InternetOpenA((LPCSTR)STATUS_SERVER_NAME, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
	if (!hSession) {
		SPDLOG_ERROR("Failed to create WinHTTP session");
=======
static bool init = false;
static curl_slist* headers = NULL;

void webhook_init() {
	if (curl_global_init(CURL_GLOBAL_ALL) != 0) {
		g_logger().error("Failed to init curl, no webhook messages may be sent");
		return;
	}

	headers = curl_slist_append(headers, "content-type: application/json");
	headers = curl_slist_append(headers, "accept: application/json");
	if (headers == NULL) {
		g_logger().error("Failed to init curl, appending request headers failed");
>>>>>>> 3398efe8 (Merge branch 'main' into luan/boos-cooldowns)
		return;
	}

	HINTERNET hConnect = InternetConnectA(hSession, "discordapp.com", INTERNET_DEFAULT_HTTPS_PORT, 0, 0, INTERNET_SERVICE_HTTP, 0, 0);
	if (!hConnect) {
		closeConnection(hSession);
		SPDLOG_ERROR("[WebHook] Failed to connect to Discord");
		return;
	}

	HINTERNET hRequest = HttpOpenRequestA(hConnect, "POST", webhookUrl.c_str(), 0, 0, 0, INTERNET_FLAG_SECURE, 0);
	if (!hRequest) {
		closeConnection(hSession, hConnect);
		SPDLOG_ERROR("[WebHook] Failed to create HTTP request");
		return;
	}

	std::string contentTypeHeader = "Content-Type: application/json";
	if (!HttpAddRequestHeadersA(hRequest, contentTypeHeader.c_str(), contentTypeHeader.length(), HTTP_ADDREQ_FLAG_REPLACE)) {
		closeConnection(hSession, hConnect, hRequest);
		SPDLOG_ERROR("[WebHook] Failed to set request headers");
		return;
	}

	// Try to send message
	DWORD dataSize = static_cast<DWORD>(payload.length());
	if (!HttpSendRequestA(hRequest, 0, 0, (LPVOID)payload.c_str(), dataSize)) {
		closeConnection(hSession, hConnect, hRequest);
		SPDLOG_ERROR("[WebHook] Failed to send HTTP request");
		return;
	}

	DWORD statusCode = 0;
	DWORD statusCodeSize = sizeof(statusCode);
	HttpQueryInfoA(hRequest, HTTP_QUERY_STATUS_CODE | HTTP_QUERY_FLAG_NUMBER, &statusCode, &statusCodeSize, 0);

	if (statusCode < 200 || statusCode >= 300) {
		closeConnection(hSession, hConnect, hRequest);
		SPDLOG_ERROR("[WebHook] Received unsuccessful HTTP status code {}", statusCode);
		return;
	}

	closeConnection(hSession, hConnect, hRequest);
#else
	dpp::cluster bot("");

	bot.on_log(dpp::utility::cout_logger());

	// Construct a webhook object using the URL you got from Discord
	dpp::webhook wh("https://discord.com/" + webhookUrl);

	dpp::embed dppEmbed;
	dppEmbed.set_title(title);
	dppEmbed.set_description(message);
	if (color >= 0) {
		dppEmbed.set_color(color);
	}
	std::string iconUrl = g_configManager().getString(DISCORD_WEBHOOK_LOGO_URL);
	dppEmbed.set_footer(dpp::embed_footer().set_text(getCurrentUTCTimeString()).set_icon(iconUrl)).set_timestamp(time(0));

	dpp::message msg;
	msg.add_embed(dppEmbed);

	bot.execute_webhook_sync(wh, msg);
#endif
}

<<<<<<< HEAD
std::string WebHook::getPayload(std::string title, std::string message, int color) {
=======
static int webhook_send_message_(const char* url, const char* payload, std::string* response_body);
static std::string get_payload(std::string title, std::string message, int color);

void webhook_send_message(std::string title, std::string message, int color, std::string url) {
	if (url.empty()) {
		return;
	}

	if (!init) {
		g_logger().error("Failed to send webhook message; Did not (successfully) init");
		return;
	}

	if (title.empty() || message.empty()) {
		g_logger().error("Failed to send webhook message; "
						 "title or message to send was empty");
		return;
	}

	std::string payload = get_payload(title, message, color);
	std::string response_body = "";
	int response_code = webhook_send_message_(url.c_str(), payload.c_str(), &response_body);

	if (response_code != 204 && response_code != -1) {
		g_logger().error("Failed to send webhook message; "
						 "HTTP request failed with code: {}"
						 "response body: {} request body: {}",
						 response_code, response_body, payload);
	}
}

static std::string get_payload(std::string title, std::string message, int color) {
>>>>>>> 3398efe8 (Merge branch 'main' into luan/boos-cooldowns)
	time_t now;
	time(&now);
	struct tm tm;

#ifdef _MSC_VER
	gmtime_s(&tm, &now);
#else
	gmtime_r(&now, &tm);
#endif

	char time_buf[sizeof "00:00"];
	strftime(time_buf, sizeof time_buf, "%R", &tm);

	std::stringstream footer_text;
	footer_text
		<< g_configManager().getString(IP) << ":"
		<< g_configManager().getNumber(GAME_PORT) << " | "
		<< time_buf << " UTC";

	Json::Value footer(Json::objectValue);
	footer["text"] = Json::Value(footer_text.str());

	Json::Value embed(Json::objectValue);
	embed["title"] = Json::Value(title);
	embed["description"] = Json::Value(message);
	embed["footer"] = footer;
	if (color >= 0) {
		embed["color"] = color;
	}

	Json::Value embeds(Json::arrayValue);
	embeds.append(embed);

	Json::Value payload(Json::objectValue);
	payload["embeds"] = embeds;

	Json::StreamWriterBuilder builder;
	builder["commentSyle"] = "None";
	builder["indentation"] = "";

	std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
	std::stringstream out;
	writer->write(payload, &out);
	return out.str();
}
<<<<<<< HEAD
=======

static int webhook_send_message_(const char* url, const char* payload, std::string* response_body) {
	CURL* curl = curl_easy_init();
	if (!curl) {
		g_logger().error("Failed to send webhook message; curl_easy_init failed");
		return -1;
	}

	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_SSLVERSION, CURL_SSLVERSION_TLSv1_2);
	curl_easy_setopt(curl, CURLOPT_POST, 1L);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, reinterpret_cast<void*>(&response_body));
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(curl, CURLOPT_USERAGENT, "canary (https://github.com/Hydractify/canary)");

	CURLcode res = curl_easy_perform(curl);

	int response_code = -1;
	if (res == CURLE_OK) {
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
	} else {
		g_logger().error("Failed to send webhook message with the error: {}", curl_easy_strerror(res));
	}

	curl_easy_cleanup(curl);

	return response_code;
}
>>>>>>> 3398efe8 (Merge branch 'main' into luan/boos-cooldowns)
