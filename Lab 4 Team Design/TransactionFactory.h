class TransactionFactory
{
	public:
		TransactionFactory(char, int, char, char, string);
		~TransactionFactory();
}

TransactionFactory::TransactionFactory(char action, int customerID, char mediaType, char movieType, string movieData)
{
	switch (action)
	case(B)
		creates a new Borrow typr
		call doTransaction using customerID, mediaType, movieType, and movieData
	case(R)
		creates a new ReturnMedia type 
	case(I)
		creates a new Inventory type
		call doTransaction using customerID, mediaType, movieType, and movieData
	case(H)
		creates a new History type
		call doTransaction using the customerID
}

TransactionFactory::~TransactionFactory()
{
	if(Borrow was created)
		then delete Borrow
	else if(Return was created)
		then delete Return
	else if(Inventory was created)
		then delete Inventory
	else if(History was created)
		then delete History
}