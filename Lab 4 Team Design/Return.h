class Return: Transaction
{
	public:		
		override void doTransaction(int, char, char, string);
}

override void Return::doTransaction(customerID, mediaType, movieType, movieData){
	searchIndex = customerId%10;	
	access the customer hashtable at searchIndex
	get the pointer to the first node in the hashtable
	while (current != NULL && current-ID != customer){
		move current to next object
	}
	if(current is NULL){
		"customer not found"
	} else {
		if(customer borrowed movie)
			update customer history
		else {
			"error"
			exit
		}
	}
	
	access the proper vector based on the media type
	access the vector at the given genre (movieType)
	get the pointer to the head node
	while (current != NULL && movieData != movie){
		move current to next object
	}
	if(current is NULL){
		"movie not found"
	} else {
		increase inventory 
	}
}