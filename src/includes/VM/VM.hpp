#ifndef LEE_LANG_VM_HPP
#define LEE_LANG_VM_HPP

#include "../Base/opcodes.hpp"

#include <string>
#include <array>

#define MEMORY_MAX_SIZE 77'777
using Byte = char;

class VM {
private:
	Chunk m_chunk;
	std::size_t m_memIndex;
	std::array<Byte, MEMORY_MAX_SIZE> m_memory;
	Chunk::iterator m_iptr;
private:
	void execute(OpCode op);
public:
	VM() = delete;
	explicit VM(Chunk&& chunk);
	void run();
	static void error(const std::string&);
};


#endif //LEE_LANG_VM_HPP
