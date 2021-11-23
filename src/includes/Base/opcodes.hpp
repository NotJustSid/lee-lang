#ifndef LEE_LANG_OPCODES_HPP
#define LEE_LANG_OPCODES_HPP

#include <cstdint>
#include <vector>
#include <unordered_map>

enum class OpCode : std::uint8_t {
	LOOP_BEGIN,		//(lee) Jump past LEE if 0 value (falsy)
	LOOP_END,		//(LEE) Go back to lee if value non-zero (truthy)

	DEC_VAL,		//(lEe) Decrease value by 1
	INC_VAL,		//(lEE) Increase value by 1

	MV_RIGHT,		//(leE) Move to right by 1
	MV_LEFT,		//(Lee) Move to left by 1

	READ_INT, 		//(LEe) Input int value
	OUT_INT, 		//(LeE) Output int value

	PRINT_CHAR, 	//(croissant) Output ASCII
	INPUT_CHAR 		//(baguette) Input ASCII
};


const std::unordered_map<std::string, OpCode> WORD_OPCODE_MAP = {
		{"lee", OpCode::LOOP_BEGIN},
		{"LEE", OpCode::LOOP_END},

		{"lEe", OpCode::DEC_VAL},
		{"lEE", OpCode::INC_VAL},

		{"leE", OpCode::MV_RIGHT},
		{"Lee", OpCode::MV_LEFT},

		{"LEe", OpCode::READ_INT},
		{"LeE", OpCode::OUT_INT},

		{"baguette", OpCode::INPUT_CHAR},
		{"croissant", OpCode::PRINT_CHAR},
};

using Chunk = std::vector<OpCode>;

#endif //LEE_LANG_OPCODES_HPP
