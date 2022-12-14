/*#ifndef F1DA15C9_9DAD_4BF2_92D5_463AAFD6DED0
#pragma once
#include<stdio.h>
#include<stdint.h>
// #include"C:\Users\amrkh\OneDrive\Desktop\Server\Terminal\Card\Card.h"
#include "../Card/Card.h"
// #include"C:\Users\amrkh\OneDrive\Desktop\Server\Terminal\Terminal.h"
#include "../Terminal/Terminal.h"
#include <string.h>
// #include"C:\Users\amrkh\OneDrive\Desktop\Server\Terminal\Server\server.h"
#endif /* F1DA15C9_9DAD_4BF2_92D5_463AAFD6DED0 
typedef unsigned int uint32_t;
typedef enum EN_transState_t
{
	APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, FRAUD_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t;

typedef struct ST_transaction_t
{
	ST_cardData_t cardHolderData;
	ST_terminalData_t terminalData;
	EN_transState_t transState;
	uint32_t transactionSequenceNumber;
}ST_transaction_t;

typedef enum EN_serverError_t
{
	SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE, BLOCKED_ACCOUNT
}EN_serverError_t;

typedef enum EN_accountState_t
{
	RUNNING,
	BLOCKED
}EN_accountState_t;

typedef struct ST_accountsDB_t
{
	float balance;
	EN_accountState_t state;
	uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;

EN_transState_t recieveTransactionData(ST_transaction_t* transData);
EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_transaction_t* transData , ST_terminalData_t *termData);
EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence);
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData);
EN_serverError_t saveTransaction(ST_transaction_t* transData);
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData);*/
#pragma once


#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

#include "../Card/card.h"
#include "../Terminal/terminal.h"
typedef enum EN_transState_t
{
    APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, FRAUD_CARD, INTERNAL_SERVER_ERROR
}EN_transStat_t;

typedef struct ST_transaction_t
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t terminalData;
    EN_transStat_t transState;
    uint32_t transactionSequenceNumber;
}ST_transaction;

typedef enum EN_serverError_t
{
    SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE, BLOCKED_ACCOUNT
}EN_serverError_t;

typedef enum EN_accountState_t
{
    RUNNING,
    BLOCKED
}EN_accountState_t;

typedef struct ST_accountsDB_t
{
    float balance;
    EN_accountState_t state;
    uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;

EN_transStat_t recieveTransactionData(ST_transaction* transData);
EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence);
EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence);
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence);
EN_serverError_t saveTransaction(ST_transaction* transData);
void listSavedTransactions(void);


//TestFunctions
void isValidAccountTest(void);
void isBlockedAccountTest(void);
void isAmountAvailableTest(void);
void recieveTransactionDataTest(void);
void saveTransactionTest(void);
void listSavedTransactionsTest(void);

#endif /* SERVER_SERVER_H_ */