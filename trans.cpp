#include <iostream>
#include "httplib.h"

int main() {
	httplib::Client cli("api.codic.jp");
	httplib::Headers headers = {
		{ "Authorization", "Bearer sxvj7zYmzo6OEYfBCgzOGfKoz10XM0bJgz" }
	};

	auto res = cli.Get("/v1/engine/translate.json?text=こんにちは", headers);
	std::cout << res->status << std::endl;
	if (res && res->status == 200) {
		std::cout << res->body << std::endl;
	}
}
