#ifndef TABLE_HPP_
#define TABLE_HPP_

#include "storage\sector.hpp"
#include "schema\attribute.hpp"
#include "base\error-codes.hpp"
#include "metadata\sector-group.hpp"
#include "storage\table-data.hpp"

#include <string>
#include <vector>

typedef SectorID TableID;

class Table {
public:
	// Constructors
	Table ();
	Table (SectorID sector_id);

	// Destructor
	~Table ();

	ErrorCode TableToMem ();
	ErrorCode MemToTable ();

	TableID table_id ();
	std::string table_name ();
	int number_of_attributes ();
	std::vector<Attribute> table_attributes ();
	int nr_string ();
	int nr_float ();
	int nr_int ();
	TableData* table_data () { return table_data_; }
	
	void set_table_id (TableID id);
	void set_table_name (std::string table_name);
	void set_nr_string (int nr);
	void set_nr_float (int nr);
	void set_nr_int (int nr);

	ErrorCode AddAttribute (std::string attr_name, DataType attr_type);

private:

	TableID id_;

	std::string name_;

	TableData *table_data_;

	std::vector<Attribute> attributes_;

	int nr_string_;

	int nr_float_;

	int nr_int_;

	int nr_attr_;
};
#endif // TABLE_HPP_