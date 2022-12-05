#include "../../incs/update.hpp"
#include "../../incs/stages.hpp"

bool	update(Info &info) {
	writeback(info);
	memory(info);
	execute(info);
	// decode(info);
	fetch(info);
	return (true);
}