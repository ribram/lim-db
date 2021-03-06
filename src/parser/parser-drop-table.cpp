#include "parser\parser-drop-table.hpp"
#include "schema\table.hpp"
#include "schema\schema-manager.hpp"
#include "boot\boot.hpp"
#include "base\generic-operations.hpp"

ParserDropTableStatement::~ParserDropTableStatement () {
	delete table_;
}

// Compile conditions:
// 1. Table exists
ErrorCode ParserDropTableStatement::Compile () {
	Table *tableSchema = NULL;
	std::string table_name;

	// We need lowercase table name
	table_name = table_->name ();
	STRING_TO_LOWER (table_name);
	table_->set_name (table_name);
	
	// Find table by name
	tableSchema = GET_SCHEMA_MANAGER ()->FindTable (table_->name());
	if (tableSchema == NULL) {
		// Not found
		return ErrorManager::error (__HERE__, ER_TABLE_DOES_NOT_EXIST,
									table_->name ());
	}

	// All good
	return NO_ERROR;
}

// Execute drop table
ErrorCode ParserDropTableStatement::Execute () {
	return GET_SCHEMA_MANAGER ()->DropTable (table_->name ());
}

std::string ParserDropTableStatement::Print () {
	assert (table_ != NULL);

	return
		std::string ("DROP TABLE ")
		+ (table_ != NULL ? table_->name () : "(unknown)");
}

void ParserDropTableStatement::GetChildren (std::vector<ParserNode *>* children) {
	children->push_back (table_);
}