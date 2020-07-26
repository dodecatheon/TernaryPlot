#include "OptimalMethod.h"
#include "ApprovalBallot.h"

class PAV : public OptimalMethod<ApprovalBallot, double>
{
public:
	PAV(double oneSeatPerWinner = false);
	double CalculateOutcomeQuality(const std::vector<ApprovalBallot> &ballots, const Outcome &outcome) override;
};