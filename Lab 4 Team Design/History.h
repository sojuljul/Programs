class History: Transaction
{
	public:	
		override void doTransaction(int);
}

override void History::doTransaction(int customer){
	searchIndex = customerId%10;
	access the hashtable at searchIndex (TBD)
	get the pointer to the first node in the hashtable
	while (current != NULL && current-ID != customer){
		move current to next object
	}
	if(current is NULL){
		"customer not found"
	} else {
		display customer's history
	}
}