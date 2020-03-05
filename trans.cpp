#include <iostream>
#include <fstream>
#include "httplib.h"
#include <string>

int main(int args, char* argv[]) {

	if (args < 1) return 1;

	// Read api key.
	std::ifstream ifs("/Users/yosuke/Work/tools/trans/.config");
	std::string apiKey;
	getline(ifs, apiKey);

	// Generate http client. 
	httplib::Client cli("api.codic.jp");
	httplib::Headers headers = {
		{ "Authorization", "Bearer " + apiKey }
	};

	// GET request.
	char url[] = "/v1/engine/translate.json?text=";
	auto res = cli.Get(strcat(url, argv[1]), headers);


	// Parse response.
	int buf = 100;
	std::string key = "translated_text";
	if (res && res->status == 200) {

		std::string resBody = res->body;
		int s = resBody.find(key);
		std::string fullKey = "\"" + key + "\"";
		int lng = fullKey.length();
		std::string res1 = resBody.substr(s + lng , buf);

		int s2 = res1.find(",");
		std::string res2 = res1.substr(0, s2);

		res2.erase(res2.begin());
		res2.erase(--res2.end());

		std::cout << res2 << std::endl;

	}
}

