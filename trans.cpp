#include <iostream>
#include "httplib.h"
#include "json11.hpp"
#include <string>

int main(int args, char* argv[]) {
	std::cout << argv[1] << std::endl;

	if (args < 1) return 1;

	httplib::Client cli("api.codic.jp");
	httplib::Headers headers = {
		{ "Authorization", "Bearer sxvj7zYmzo6OEYfBCgzOGfKoz10XM0bJgz" }
	};

	char url[] = "/v1/engine/translate.json?text=";

	auto res = cli.Get(strcat(url, argv[1]), headers);
	std::cout << res->status << std::endl;
	if (res && res->status == 200) {
		std::string resBody = res->body;
		std::string err;
		auto json = json11::Json::parse(resBody, err);
		std::cout << json << std::endl;
	}
}

