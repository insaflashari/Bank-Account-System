///////INSAF LASHARI
//////PROJECT 4 MO MONEY
/////DECEMBER 5, 2023

#include <cassert>
#include <iomanip>
#include <iostream>

#include "project4.hpp"
#include "History.hpp"
#include "Transaction.hpp"

////////////////////////////////////////////////////////////////////////////////
// Definitions for Transaction class
////////////////////////////////////////////////////////////////////////////////
//
//

// Constructor - TASK 1

//The transaction class defines the objects that are nodes (or items) of linked list
//mostly data, read using get_ and updated suing set_ methods
//each transaction object has p_next pointer whic links to next node in the linked list
//last object set to = nullptr.


//contains 7 parameters
//PUBLIC MEMBER FUNCTIONS
//Creates and initializes a Transaction object with the appropriate data values
Transaction::Transaction( std::string ticker_symbol,  
                          unsigned int day_date,  
                          unsigned int month_date,  
                          unsigned year_date, 
                          bool buy_sell_trans,  
                          unsigned int number_shares,  
                          double trans_amount ):

                          //this constructor assigns the parameters to their respective
                         //private member variables and appropriately initializes all the 
                        //other private member variables


//PRIVATE MEMBER VARIABLES

  // ticker symbol
    symbol{ticker_symbol},

    // day of the trade date
    day{day_date},

    //month of the trade date
    month{month_date},

   // year of the trade date
    year{year_date},

   // transaction type. Value must be either "buy" or "sell"
    trans_type{},

    // number of shares involved in the transaction
    shares{number_shares},

    //total dollar amount of transaction, always positive
    amount{trans_amount},

    // unique transaction identifier for every transaction
    trans_id{assigned_trans_id},

    // intitialized value, will be assigned
    acb{},
    acb_per_share{},
    share_balance{},
    cgl{},
    p_next{}

    //initializes the transaction ID, then incremented ++

    {
        if (buy_sell_trans) {
            trans_type = "Buy";
        } else {
            trans_type = "Sell";
        }
        assigned_trans_id++;
    }





// Destructor - TASK 2

//Destroys the Transaction object and deallocates any dynamic memory used
Transaction::~Transaction() {
  p_next = nullptr;  //set to null value
}



// Overloaded < operator - TASK 3


   //Returns true if this transaction comes chronologically before the other, 
  //and false otherwise. If both transactions occurred on the same date, returns 
//true if this transaction has a lower ID, and false otherwise.
bool Transaction::operator< (Transaction const &other) {

  //  first check which date comes first
  // of both have the same date, check the trans_id
 
    // Compare years
    if ( year < other.get_year()) {
        return true;
    } else if ( year > other.get_year()) {
        return false;
    }
    
    // Years are equal, compare months
    if ( month < other.get_month()) {
        return true;
    } else if ( month > other.get_month()) {
        return false;
    }

    // months are equal, compare days
    if ( day < other.get_day()) {
        return true;
    } else if ( day > other.get_day()) {
        return false;
    }

    // if dates are same, compare transaction IDs
    return ( trans_id < other.get_trans_id() );
   
}

// GIVEN
// Member functions to get values.
//
std::string Transaction::get_symbol() const { return symbol; }
unsigned int Transaction::get_day() const { return day; }
unsigned int Transaction::get_month() const { return month; }
unsigned int Transaction::get_year() const { return year; }
unsigned int Transaction::get_shares() const { return shares; }
double Transaction::get_amount() const { return amount; }
double Transaction::get_acb() const { return acb; }
double Transaction::get_acb_per_share() const { return acb_per_share; }
unsigned int Transaction::get_share_balance() const { return share_balance; }
double Transaction::get_cgl() const { return cgl; }
bool Transaction::get_trans_type() const { return (trans_type == "Buy") ? true: false ; }
unsigned int Transaction::get_trans_id() const { return trans_id; }
Transaction *Transaction::get_next() { return p_next; }

// GIVEN
// Member functions to set values.
//
void Transaction::set_acb( double acb_value ) { acb = acb_value; }
void Transaction::set_acb_per_share( double acb_share_value ) { acb_per_share = acb_share_value; }
void Transaction::set_share_balance( unsigned int bal ) { share_balance = bal ; }
void Transaction::set_cgl( double value ) { cgl = value; }
void Transaction::set_next( Transaction *p_new_next ) { p_next = p_new_next; }

// GIVEN
// Print the transaction.
//
void Transaction::print() {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << std::setw(4) << get_trans_id() << " "
    << std::setw(4) << get_symbol() << " "
    << std::setw(4) << get_day() << " "
    << std::setw(4) << get_month() << " "
    << std::setw(4) << get_year() << " ";


  if ( get_trans_type() ) {
    std::cout << "  Buy  ";
  } else { std::cout << "  Sell "; }

  std::cout << std::setw(4) << get_shares() << " "
    << std::setw(10) << get_amount() << " "
    << std::setw(10) << get_acb() << " " << std::setw(4) << get_share_balance() << " "
    << std::setw(10) << std::setprecision(3) << get_acb_per_share() << " "
    << std::setw(10) << std::setprecision(3) << get_cgl()
    << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
// Definitions for the History class
////////////////////////////////////////////////////////////////////////////////
//
//contains head pointer that holds the complete linked-list
//also contains fncs for creating and manipulating linked list


// Constructor - TASK 4
//default constructor, initializes linked-list to be empty
History::History() {
   p_head = nullptr;
}
 


// Destructor - TASK 5
//clears up any data created by the project
History::~History() {

  Transaction *p_temp = nullptr;
  //loop will stop once get_p_head points to the nullptr and is not a transaction

//while it is not the end of the list
  while( get_p_head() != nullptr) {
    //walk through linked list
    p_temp = get_p_head();
    p_head = get_p_head() -> get_next();
    //deallocate
    delete p_temp;
    p_temp = nullptr;
  }
  //deallocate
   p_head = nullptr;
   p_temp = nullptr;
  
}


//adds the passed Transaction instance to the end of the linked list of transaction
//keeps them in transaction id order
// TODO - TASK 6
void History::insert(Transaction *p_new_trans) {

    p_new_trans->set_next(nullptr);
        Transaction *node_trans{get_p_head()};

        if (node_trans != nullptr) {
            while(node_trans->get_next() != nullptr) {
                node_trans = node_trans->get_next();
            }
            node_trans->set_next(p_new_trans);
        } else {
            p_head = p_new_trans;
        }

        node_trans = nullptr;
        p_new_trans = nullptr;

}

//reads the transaction history from the input file (transaction_history.txt) 
//and creates the linked-list. helper fncs for reading the input file are provided 
//in the project4.hpp/.cpp files
//calls the insert fncs to add the new transaction to the linked-list (same order they
//are read from the output file)

// TODO - TASK 7
void History::read_history() {

//test: std::cout << "open file" << std::endl;
     ece150::open_file();

    while(ece150::next_trans_entry()) {
        std::string new_symbol{ece150::get_trans_symbol()};
        unsigned int new_day{ece150::get_trans_day()};
        unsigned int new_month{ece150::get_trans_month()};
        unsigned new_year{ece150::get_trans_year()};
        bool bs_trans{ece150::get_trans_type()};
        unsigned int new_share_number{ece150::get_trans_shares()};
        double new_trans_amount{ece150::get_trans_amount()};

        Transaction *new_transaction{new Transaction{new_symbol, 
                                                    new_day, 
                                                    new_month, 
                                                    new_year, 
                                                    bs_trans, 
                                                    new_share_number, 
                                                    new_trans_amount}};

//test:  std::cout << "New Transaction Created" << std::endl;

        insert(new_transaction);
        new_transaction = nullptr;
    }

    ece150::close_file();
//test: std::cout << "Closing File" << std::endl;
}


// print to console output the transaction history
// TODO - TASK 8
void History::print() {

std::cout << "========== BEGIN TRANSACTION HISTORY ============" << std::endl;
    Transaction *node_transaction{get_p_head()};
    while (node_transaction != nullptr)
    {
        node_transaction->print();
        node_transaction = node_transaction->get_next();
    }
    std::cout << "========== END TRANSACTION HISTORY ============" << std::endl;

    node_transaction = nullptr;

}






// sort_by_date(): Sort the linked list by trade date
// TASK 9
void History::sort_by_date() {

  //intialize head of unsorted original linked list
    Transaction *p_node = get_p_head();

 //pointer to walk through the linked list and check the smallest transaction
//intialize with head of unsorted original linked list
    Transaction *p_small_trans = get_p_head();

  //intialize head of new empty linked list that will be sorted
    Transaction *p_sorted = nullptr;


//EDGE CASE: if linked list is empty or contains 1 element)
//returns p_head = p_sorted
    if ( (p_node == nullptr) || (p_node->get_next() == nullptr))  {  

    }
 
 //FINDING THE SMALLEST NODE IN THE HISTORY LIST

 //big while loop to walk through the linked list
    while (get_p_head() != nullptr) {
        p_node = get_p_head();
        p_small_trans = get_p_head();

        //must break out of loop if walking pointer 
       //exceeds last element in linked list
        while (p_node != nullptr) {
     //comparing values therefore need to dereference*
              if (*(p_small_trans) < *(p_node)) {
               // return nothing;
            } else if (*(p_node) < *(p_small_trans)) {
                p_small_trans = p_node;
            } else if (p_small_trans->get_trans_id() < p_node->get_trans_id()) {
                // return nothing
            } else {
                p_small_trans = p_node;
            }
            p_node = p_node->get_next();
        }
    
    //REMOVING NODE FROM ORIGINAL LIST
            p_node = get_p_head();
            if (p_small_trans == get_p_head()) {
                p_head = p_small_trans->get_next();
            } else {
                  while (p_node->get_next() != nullptr) {
                    if (p_node->get_next() == p_small_trans) {
                        p_node->set_next(p_small_trans->get_next());
                        continue;
                    }
                    p_node = p_node->get_next();
                }
            }


            p_small_trans->set_next(nullptr);

        // ADDING TO THE SORTED LIST
        Transaction *p_sorted_node = p_sorted;
        if (p_sorted_node != nullptr) {
            // Adding to sorted list
            while(p_sorted_node->get_next() != nullptr) {
                p_sorted_node = p_sorted_node->get_next();
            }
            p_sorted_node->set_next(p_small_trans);
        } else {
            p_sorted = p_small_trans;
        }
        p_sorted_node = nullptr;

    }
            p_head = p_sorted;

//cleanup
    p_node = nullptr;
    p_sorted = nullptr;
    p_small_trans = nullptr;

}




// update_acb_cgl(): Updates the ACB and CGL values.
// TASK 10
void History::update_acb_cgl() {

  //linked list must be sorted before calculations
  sort_by_date();

//initialize
Transaction *p_node{get_p_head()};
    double new_acb{};
    double new_acb_per_share{};
    unsigned int new_share_balance{};
    double new_cgl{};

//walk through linked list
    while ( p_node != nullptr ) {

        // CALCULATING SHARE BALANCE
        if (p_node->get_trans_type()) {
          //for Buy: we add the share balance from the previous transaction 
         //with the number of shares purchased with the new transaction.
            new_share_balance += p_node->get_shares();
        } else {
        //for Sell: previous Share Balance minus the number of shares sold
            new_share_balance -= p_node->get_shares();
        }
        p_node->set_share_balance(new_share_balance);


        // CALCULATING ACB
        if (p_node->get_trans_type()) {
        //for BUY: accumulate the total amount paid for the purchases
            new_acb += p_node->get_amount();
        //for SELL: subtract the number of shares sold multiplied 
        //by the ACB/Share resulting from the previous transaction 
        } else {
            new_acb -= p_node->get_shares()*new_acb_per_share;
        }
        p_node->set_acb(new_acb);


 //CALCUALTING ACB AND $HARE
        if (p_node->get_trans_type())  {
          if (p_node->get_share_balance() != 0) {
        //To compute the ACB/Share on a Buy, divide the ACB by the Share Balance
                new_acb_per_share = p_node->get_acb() / p_node->get_share_balance();
            } else {
                new_acb_per_share = 0;
            }
        }
        p_node->set_acb_per_share(new_acb_per_share);


        // CALCULATING CGL
        //To compute the CGL, we subtract the number of shares 
        //sold multiplied by the ACB/Share from the previous transaction
        if (!(p_node->get_trans_type())) {
           new_cgl = (p_node->get_amount() - (p_node->get_shares()*p_node->get_acb_per_share()));
           p_node->set_cgl(new_cgl);
        }

        p_node = p_node->get_next(); 
    }
    p_node = nullptr;

    return;
}

// compute_cgl(): )Compute the ACB, and CGL.
// TASK 11
double History::compute_cgl(unsigned int year) {
    update_acb_cgl();
    Transaction *p_node{get_p_head()};
    double total_cgl{};

//walk though the linked list
    while ( p_node != nullptr ) {
        if (p_node->get_year() == year && !(p_node->get_trans_type())) {
            total_cgl += p_node->get_cgl();
        }
        p_node = p_node->get_next();
    }

    p_node = nullptr;

    return total_cgl;

  return 0;

}


// GIVEN
// get_p_head(): Full access to the linked list.
//
Transaction *History::get_p_head() { return p_head; }


