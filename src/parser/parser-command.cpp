#include "parser\parser-command.hpp"
#include "boot\boot.hpp"

#include <cassert>

ErrorCode ParserCommand::Execute ()
{
	switch (type_) {
	case PT_COMMAND_EXIT:
		REQUEST_SERVER_SHUTDOWN ();
		return NO_ERROR;

	default:
		assert (false);
		return ER_FAILED;
	}
}

std::string ParserCommand::Print ()
{
	return std::string("EXIT");
}