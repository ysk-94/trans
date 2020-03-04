#include <iostream>
#include "httplib.h"

int main() {
	httplib::Client cli("www.google.com");

	auto res = cli.Get("/");
	if (res && res->status == 200) {
		std::cout << res->body << std::endl;
	}
}
