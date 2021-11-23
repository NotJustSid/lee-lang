#include "VM.hpp"

#include <exception>
#include <iostream>

VM::VM(Chunk &&chunk) : m_chunk{std::move(chunk)}, m_memIndex{0}, m_memory{}, m_iptr{m_chunk.begin()} {
	//! Ensure all memory bytes are set to 0
	m_memory.fill(0);
}

void VM::run() {
	while (m_iptr != m_chunk.end()) {
		execute(*m_iptr);
	}
}

void VM::error(const std::string& error) {
	throw std::exception(std::string("(VM) " + error).c_str());
}

void VM::execute(OpCode op) {
	switch (op) {
		case OpCode::LOOP_BEGIN:

			if (m_memory.at(m_memIndex) == 0) {
				int level = 1;

				while (level > 0) {
					m_iptr++;

					if (m_iptr == m_chunk.end()) break;

					if (*m_iptr == OpCode::LOOP_BEGIN) level++;

					if (*m_iptr == OpCode::LOOP_END) level--;
				}

				if (level != 0) error("Unmatched 'lee's and 'LEE's");

				m_iptr++; //Execution starts past 'LEE'
			}
			else m_iptr++;
			break;

		case OpCode::LOOP_END:

			if (m_iptr == m_chunk.begin()) error("Unmatched 'lee's and 'LEE's");

			if (m_memory.at(m_memIndex) != 0) {
				int level = 1;

				while (level > 0) {
					m_iptr--;

					if (*m_iptr == OpCode::LOOP_BEGIN) level--;

					if (*m_iptr == OpCode::LOOP_END) level++;

					if (m_iptr == m_chunk.begin()) break;
				}

				if (level != 0) error("Unmatched 'lee's and 'LEE's");
			}
			else m_iptr++;

			break;
		case OpCode::DEC_VAL:
			m_memory.at(m_memIndex)--;
			m_iptr++;
			break;
		case OpCode::INC_VAL:
			m_memory.at(m_memIndex)++;
			m_iptr++;
			break;
		case OpCode::MV_RIGHT:
			m_memIndex++;
			if(m_memIndex == MEMORY_MAX_SIZE) error("Memory Overflow");
			m_iptr++;
			break;
		case OpCode::MV_LEFT:
			if(m_memIndex != 0) m_memIndex--;
			m_iptr++;
			break;
		case OpCode::READ_INT: {
			int input;
			std::cin >> input;
			if (input > 127 || input < -128) error("Provided integer value cannot be accommodated in a memory unit");
			m_memory.at(m_memIndex) = static_cast<Byte>(input);
			m_iptr++;
			break;
		}
		case OpCode::OUT_INT:
			std::cout << static_cast<int>(m_memory.at(m_memIndex));
			m_iptr++;
			break;
		case OpCode::PRINT_CHAR:
			std::cout << static_cast<char>(m_memory.at(m_memIndex));
			m_iptr++;
			break;
		case OpCode::INPUT_CHAR: {
			char input;
			std::cin >> input;
			m_memory.at(m_memIndex) = input;
			m_iptr++;
			break;
		}
	}
}
