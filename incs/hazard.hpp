#ifndef HAZARD_HPP
# define HAZARD_HPP

// Hazard detection unit
class Hazard {
	private:
		bool	_pcWrite;
		bool	_instructionWrite;
		bool	_memRead;
		int		_rs;
		int		_rt;
		int		_prevRd;

	public:
		Hazard(void);
		~Hazard(void);

		// Getters
		bool	getPcWrite(void);
		bool	getInstructionWrite(void);
		bool	getMemRead(void);
		int		getRs(void);
		int		getRt(void);
		int		getPrevRd(void);
		
		// Setters
		void	setPcWrite(bool pcWrite);
		void	setInstructionWrite(bool instructionWrite);
		void	setMemRead(bool memRead);
		void	setRs(int rs);
		void	setRt(int rt);
		void	setPrevRd(int prevRd);
};