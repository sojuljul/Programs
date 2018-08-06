class BusinessLogic {
public:
    buildMovieInventory(istream&);
    buildCustomerTable(istream&);
    processTransactions(istream&);

private:
    HashTable customerTable;
    vector<vector<Movie>> mediaInventory; // 0 = movies
};

struct movieNode {
    Movie* data;
    movieNode* next;
};

// Psuedocode for building movie inventory
// buildMovieInventory(file) {
//     char movieType = '';
//     int stock, dayRelease, yearRelease = 0;
//     string directorFirstName = "";
//     string directorLastName = "";
//     string movieTitle = "";
//     string majorActorFirstName = "";
//     string majorActorLastName = "";
//
//     for (;;) {
//         if (file.eof()) {
//             break;
//         }
//         file >> movieType;
//         if (movieType == 'C') {
//             Movie newMovie = C(stock, directorFirstName, directorLastName,
//                                movieTitle, majorActorFirstName,
//                                majorActorLastName, dayRelease, yearRelease);
//             newMovie.insertMovie();
//         } else if (movieType == 'D') {
//             Movie newMovie = D(stock, directorFirstName, directorLastName,
//                                movieTitle, yearRelease);
//             newMovie.insertMovie();
//         } else if (movieType == 'F') {
//             Movie newMovie = F(stock, directorFirstName, directorLastName,
//                                 movieTitle, yearRelease);
//             newMovie.insertMovie
//         } else {
//             cout << "Error: " << movieType << " is an invalid movie type";
//         }
//     }
// }

// BuildCustomer Pseudo-Code
//
// void buildCustomer(){
//     read in the first 3 values from the txt file
//         (customer ID, first name, last name)
//     create a new customer object with the data
//     access the hashtable at the correct index (index = customerID % 10)
//     while(current->ID != newID && current->next != NULL)
//         move current to the next object in the list
//     if( current->ID == newID )
//         "customer profile already exits"
//     else
//         insert new customer at the end of the list
//
// }

// Psuedocode to read comman file
// void processTransactions(file) {
//     while (!file.eof())
//         read in first value for command type
//         if (I) {
//             display current inventory;
//         }
//         else if (H) {
//             read customer ID;
//             display customer's rental history;
//         }
//         else if (B) {
//             read customer ID, media type, movie type;
//             if (C) {
//                 read dayRelease, yearRelease, majorActor;
//                 adjust stock;
//             } else if (D) {
//                 read director, title;
//                 adjust stock;
//             } else if (F) {
//                 read title, yearRelease;
//                 adjust stock;
//             }
//         } else if (R) {
//             read customer ID, media type, movie type;
//             if (C) {
//                 read dayRelease, yearRelease, majorActor;
//                 adjust stock;
//             } else if (D) {
//                 read director, title;
//                 adjust stock;
//             } else if (F) {
//                 read title, yearRelease;
//                 adjust stock;
//             }
//         }
// }
