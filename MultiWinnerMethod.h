#include "VotingMethod.h"

#pragma once

template<typename BallotType = CardinalBallot>
class MultiWinnerMethod : public VotingMethod<BallotType>
{
public:
	MultiWinnerMethod(unsigned seats = 2, bool oneSeatPerWinner = false);

	void SetNumSeats(int numSeats);
	unsigned GetNumSeats();

	void SetOneSeatPerWinner(bool oneSeatPerWinner);
	bool IsOneSeatPerWinner();

	Outcome &CalculateResults(std::vector<BallotType> &ballots) override;

protected:
	virtual Outcome &CalculateResults(std::vector<BallotType> &ballots, unsigned seats, bool oneSeatPerWinner) = 0;

	virtual void OnNumSeatsChange();
	virtual void OnNumSeatsPerWinnerChange();

private:
	unsigned _numSeats;
	bool _oneSeatPerWinner;
};

// If I wasn't working in Visual Studios, I would just include all of this code in the cpp file 
// (and include the cpp file in this header), but because VS loves to make it harder to use templates, 
// the code is here instead:

template<typename BallotType>
MultiWinnerMethod<BallotType>::MultiWinnerMethod(unsigned seats, bool oneSeatPerWinner)
	: _numSeats(seats), _oneSeatPerWinner(oneSeatPerWinner) {}

template<typename BallotType>
void MultiWinnerMethod<BallotType>::SetNumSeats(int numSeats)
{
	_numSeats = numSeats;
	OnNumSeatsChange();
}

template<typename BallotType>
unsigned MultiWinnerMethod<BallotType>::GetNumSeats()
{
	return _numSeats;
}

template<typename BallotType>
void MultiWinnerMethod<BallotType>::SetOneSeatPerWinner(bool oneSeatPerWinner)
{
	_oneSeatPerWinner = oneSeatPerWinner;
	OnNumSeatsPerWinnerChange();
}

template<typename BallotType>
bool MultiWinnerMethod<BallotType>::IsOneSeatPerWinner()
{
	return _oneSeatPerWinner;
}

template<typename BallotType>
Outcome &MultiWinnerMethod<BallotType>::CalculateResults(std::vector<BallotType> &ballots)
{
	return CalculateResults(ballots, _numSeats, _oneSeatPerWinner);
}

template<typename BallotType>
void MultiWinnerMethod<BallotType>::OnNumSeatsChange() {}

template<typename BallotType>
void MultiWinnerMethod<BallotType>::OnNumSeatsPerWinnerChange() {}