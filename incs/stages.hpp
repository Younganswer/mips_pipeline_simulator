#ifndef STAGES_HPP
# define STAGES_HPP

# include "info.hpp"

static bool	isBranch = false;

// fetch.cpp
bool	fetch(Info &info);

// decode.cpp
bool	decode(Info &info);

// execute.cpp
bool	execute(Info &info);

// memory.cpp
bool	memory(Info &info);

// writeback.cpp
bool	writeback(Info &info);

#endif