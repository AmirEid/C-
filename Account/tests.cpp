// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1993                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t; //acount objecs
	typedef std::vector<int>								  ints_t; //vector of ints
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t; //pair of iterators, one for account and one for int

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 }; //initial amounts for accounts
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) ); //size of amounts
	accounts_t				accounts( amounts, amounts + amounts_size );  // a vector of accounts objects initialized with values from amounts array.
	accounts_t::iterator	acc_begin	= accounts.begin(); //iterators for the beginning of account vector
	accounts_t::iterator	acc_end		= accounts.end(); //iterators for the end of account vector

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 }; //array of deposits
	size_t const		d_size( sizeof(d) / sizeof(int) ); //the number of elements in the array
	ints_t				deposits( d, d + d_size ); //a vector of integers initialized with values from d array
	ints_t::iterator	dep_begin	= deposits.begin(); //iterator for the beginning of deposits vector
	ints_t::iterator	dep_end		= deposits.end(); //iterator for the end of deposits vector

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 }; //array of withdrawals
	size_t const		w_size( sizeof(w) / sizeof(int) );	//the number of elements in the array
	ints_t				withdrawals( w, w + w_size ); //a vector of integers initialized with values from w array
	ints_t::iterator	wit_begin	= withdrawals.begin(); //iterator for the beginning of withdrawals vector
	ints_t::iterator	wit_end		= withdrawals.end(); //iterator for the end of withdrawals vector

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
	//this should display the number of accounts, the total amount, the number of deposits and the number of withdrawals

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}
	// this should add deposit

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
	//this should display information abuot the accounts ager the deposits

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}
	//this should make withdrawals

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
	//this should display information about the accounts after the withdrawals
	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
