#include "Compiler.hpp"

#include <string>

Compiler::Compiler(const char* filename) : file{filename} {
	if(!file) throw std::exception("Couldn't open file.");
}

Chunk Compiler::compile() {

	std::string word;

	bool inComment = false;

	while (file >> word) {

		if (word == "wee") {
			inComment = !inComment;
			continue;
		}

		if (inComment) continue;

		if (WORD_OPCODE_MAP.find(word) == WORD_OPCODE_MAP.end())
			throw std::exception(std::string("Unidentified token '" + word + "'").c_str());

		m_chunk.push_back(WORD_OPCODE_MAP.at(word));
	}

	return m_chunk;
}
