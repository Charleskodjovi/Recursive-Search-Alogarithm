
#ifndef RESULTS_H
#define RESULTS_H

//****************************************************************************************************

struct Results
{
	int ordCompares;
	int unOrdCompares;
	int revOrdCompares;
	int avgCompares;
	int ordCopies;
	int unOrdCopies;
	int revOrdCopies;
	int avgCopies;
	Results();
};

//****************************************************************************************************

Results::Results()
{
	ordCompares = 0;
	unOrdCompares = 0;
	revOrdCompares = 0;
	avgCompares = 0;
	ordCopies = 0;
	unOrdCopies = 0;
	revOrdCopies = 0;
	avgCopies = 0;
}

//****************************************************************************************************

#endif
