class Borrow: Transaction
{
	public:	
		override void doTransaction(int, char, char, string);
}

override void Borrow::doTransaction(customerID, mediaType, movieType, movieData){	
	access the proper vector based on the media type
	access the vector at the given genre (movieType)
	get the pointer to the head node
	while (current != NULL && movieData != movie){
		move current to next object
	}
	if(current is NULL){
		"movie not found"
	} else if(no copies left){
		if(classic){
			find same movie title
			decrease inventory
		}
		"no copies left"
	} else {
		decrease inventory 
	}
	
	searchIndex = customerId%10;
	access the hashtable at searchIndex
	get the pointer to the first node in the hashtable
	while (current != NULL && current->ID != customer){
		move current to next object
	}
	if(current is NULL){
		"customer not found"
	} else {
		update customer history
	}
}
