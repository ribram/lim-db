#include "boot\boot.hpp"

SectorManager * Boot::sector_manager_ = NULL;

void Boot::StartServer(){
	sector_manager_ = new SectorManager();
}

void Boot::StopServer(){
	delete sector_manager_;
}

SectorManager* Boot::get_sector_manager(){
	return sector_manager_;
}

