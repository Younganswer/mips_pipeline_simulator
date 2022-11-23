#include "../../incs/hazard.hpp"

Hazard::Hazard(void) {}

Hazard::~Hazard(void) {}

// Getters
bool	Hazard::getPcWrite(void) { return this->_pcWrite; }
bool	Hazard::getInstructionWrite(void) { return this->_instructionWrite; }
bool	Hazard::getMemRead(void) { return this->_memRead; }
int		Hazard::getRs(void) { return this->_rs; }
int		Hazard::getRt(void) { return this->_rt; }
int		Hazard::getPrevRd(void) { return this->_prevRd; }

// Setters
void	Hazard::setPcWrite(bool pcWrite) { this->_pcWrite = pcWrite; }
void	Hazard::setInstructionWrite(bool instructionWrite) { this->_instructionWrite = instructionWrite; }
void	Hazard::setMemRead(bool memRead) { this->_memRead = memRead; }
void	Hazard::setRs(int rs) { this->_rs = rs; }
void	Hazard::setRt(int rt) { this->_rt = rt; }
void	Hazard::setPrevRd(int prevRd) { this->_prevRd = prevRd; }