#include <iostream>
#include <fstream>
#include "httplib.h"
#include <string>

int main(int args, char* argv[]) {

	if (args < 1) return 1;

	std::ifstream ifs("/Users/uu173225/work/tools/transc/.config");
	std::string apiKey;
	getline(ifs, apiKey);


	httplib::Client cli("api.codic.jp");
	httplib::Headers headers = {
		{ "Authorization", "Bearer " + apiKey }
	};

	char url[] = "/v1/engine/translate.json?text=";

	auto res = cli.Get(strcat(url, argv[1]), headers);
	if (res && res->status == 200) {

		std::string resBody = res->body;
		int s = resBody.find("translated_text");
		std::string res1 = resBody.substr(s, 100);

		int s2 = res1.find(":");
		std::string res2 = res1.substr(++s2, 100);

		int s3 = res2.find(",");
		std::string res3 = res2.substr(0, s3);

		res3.erase(res3.begin());
		res3.erase(--res3.end());

		std::cout << res3 << std::endl;

	}
}


//std::string err;
//		auto json = json11::Json::parse(resBody, err);
//		std::cout << json.dump() << std::endl;
//
//		for (auto &k : json["0"].array_items()) {
//			std::cout << k.dump() << std::endl;
//		}
