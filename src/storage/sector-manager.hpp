#ifndef SECTOR_MANAGER_HPP_
#define SECTOR_MANAGER_HPP_

#include "base\bitmap.hpp"
#include "base\error-codes.hpp"
#include "base\error-manager.hpp"
#include "base\generic-type-definitions.hpp"
#include "storage\sector.hpp"

class SectorManager {
	public:
		//Constructor
		SectorManager ();

		//Destructor
		~SectorManager ();

		//Finds and returns ID to a free sector
		ErrorCode AllocateSector (SectorID *sector_id);

		//Deallocates a sector
		ErrorCode DeallocateSector (SectorID sector_id);

		//Checks wether a sector is free ot not
		bool IsSectorAllocated (SectorID sector_id);

		//Returns a pointer to the beggining of the requested sector
		BYTE* GetSectorPointer (SectorID sector_id);
	protected:
	private:
		//Instance of Bitmap for tracking usage of sectors
		Bitmap *allocation_table_;
		//Keeps record of the size of one sector
		int sector_size_;
		//Pointer to the last sector used
		SectorID last_used_;
		//Points to the start of the memory allocated
		BYTE *storage_pointer_;
};
#endif