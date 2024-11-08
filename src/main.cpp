#include "Examples/TestExample.h"

int main() {
	TestExampleApp app;

	try {
		app.Run();
	}
	catch (std::exception e) {
		std::cout << e.what() << '\n';
		return 1;
	}

	return 0;
}