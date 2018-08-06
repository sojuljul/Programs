class Inventory: Transaction
{
	public:	
		override void doTransaction();
}

override void Inventory::doTransaction(){
	create pointer to Movie vector object
	while(count < numMovieTypes){
		get head pointer from vector
		while(current != NULL){
			output the object info
			move current to next object
		}
	}
}