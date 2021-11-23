#ifndef LEE_LANG_COMPILER_HPP
#define LEE_LANG_COMPILER_HPP

#include <fstream>
#include "../Base/opcodes.hpp"

class Compiler {
private:
	std::fstream file;
	Chunk m_chunk;
public:
	Compiler() = delete;

	explicit Compiler(const char* filename);

	Chunk compile();
};


#endif //LEE_LANG_COMPILER_HPP
