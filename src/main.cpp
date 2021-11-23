#include <iostream>
#include <cstdlib>
#include <exception>

#include "includes/Compiler/Compiler.hpp"
#include "includes/VM/VM.hpp"

int main(int argc, char** argv) {
	
	try {
		if (argc != 2) {
			throw std::exception("Usage: leepls <file.lee>");
		}

		Compiler compiler{argv[1]};
		VM program{compiler.compile()};
		program.run();
	}
	catch (const std::exception& error) {
		std::cerr << "Error: " << error.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}

    return 0;
}
