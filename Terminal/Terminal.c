#include<stdio.h>
#include "../STD_types.h"   //STD_Types.h file includes standard types as uint8,uint16 and so on
#include "../Card/Card.h"
#include"Terminal.h"
/*EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
    EN_terminalError_t Card_Status = TERMINAL_OK;

    uint8_t transactionDate[11] = {0};

    printf(" Enter Your Transaction Date: ");
    gets(transactionDate);

    uint8_t transDateLength = strlen(transactionDate);

    if( (NULL == transactionDate) ||  (transDateLength < 10) || (transDateLength > 10) ||(transactionDate[2] != '/' || transactionDate[5] != '/') )
    {
        Card_Status = WRONG_DATE;
    }
    else
    {
        strcpy(termData -> transactionDate, transactionDate);
    }

    return Card_Status;
}
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
    EN_terminalError_t Card_Status = TERMINAL_OK;

    uint8_t CardExpirationMonth = 
    ((cardData.cardExpirationDate[0] - '0') * 10) + (cardData.cardExpirationDate[1] - '0');
    uint8_t CardExpirationYear  = 
    ((cardData.cardExpirationDate[3] - '0') * 10) + (cardData.cardExpirationDate[4] - '0');

    uint8_t TransactionMonth = 
    ((termData.transactionDate[3] - '0') * 10) + (termData.transactionDate[4] - '0');
    uint8_t TransactionYear  = 
    ((termData.transactionDate[8] - '0') * 10) + (termData.transactionDate[9] - '0');

    if( (CardExpirationYear < TransactionYear) )
    {
        Card_Status = EXPIRED_CARD;
    }
    else if( (CardExpirationYear == TransactionYear) )
    {
        if( (CardExpirationMonth < TransactionMonth) || (CardExpirationMonth == TransactionMonth) )
        { 
            Card_Status = EXPIRED_CARD; 
        }
        else {
            ;}
    }
    else {
        ;}

    return Card_Status;
}
EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData)
{
    EN_terminalError_t Card_Status = TERMINAL_OK;

    

    return Card_Status;
}
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
    EN_terminalError_t Card_Status = TERMINAL_OK;

    float transAmount = 0;
    printf(" Enter transaction amount: ");

    scanf("%f", &transAmount);

    if(transAmount <= 0)
    {
        Card_Status = INVALID_AMOUNT;
    }
    else
    {
        (termData->transAmount = transAmount);
    }
    return Card_Status;
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
    EN_terminalError_t Card_Status = TERMINAL_OK;

    if( (termData->transAmount > termData->maxTransAmount) )
    {
        Card_Status = EXCEED_MAX_AMOUNT;
    }
    else{
        ;
        }

    return Card_Status;
}


EN_terminalError_t setMaxAmount(ST_terminalData_t *termData, float maxAmount)
{
    EN_terminalError_t Card_Status = TERMINAL_OK;
    
    float maxAmount = 0;

    printf(" Enter transaction maximum amount: ");

    scanf("%f", &maxAmount);

    if(0 >= maxAmount)
    {
        Card_Status = INVALID_MAX_AMOUNT;
    }
    else
    {
        termData->maxTransAmount = maxAmount;
    }

    return Card_Status;
    EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	printf("\nPlease, Enter the transaction date in format DD/MM/YYYY  \n");
	gets(termData->transactionDate);

	if (strlen(termData->transactionDate) == 10 && termData->transactionDate[0] <= '3' && termData->transactionDate[1] <= '9' && termData->transactionDate[2] == '/' && termData->transactionDate[3] <= '1' && termData->transactionDate[4] <= '9' && termData->transactionDate[5] == '/' && termData->transactionDate[6] == '2' && termData->transactionDate[7] == '0' && termData->transactionDate[8] <= '3' && termData->transactionDate[9] <= '9')
	{
		//printf("TERMINAL_OK\n");
		return TERMINAL_OK;
	}
	else
	{
		printf(" WRONG_DATE \n");
		return WRONG_DATE;

	}
}





EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
	if (termData->transactionDate[8] <= cardData->cardExpirationDate[3] && termData->transactionDate[9] <= cardData->cardExpirationDate[4])
	{
		if ((termData->transactionDate[3] * 10 + termData->transactionDate[4]) <= (cardData->cardExpirationDate[0] * +cardData->cardExpirationDate[1]))
		{
			
			return TERMINAL_OK;
		}
		else
		{
			printf("EXPIRED_CARD \n");
			return EXPIRED_CARD;
		}
	}

	else
	{
		printf("EXPIRED_CARD \n");
		return EXPIRED_CARD;
	}
}




EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	printf("\nPlease, enter the transaction amount \n");
	scanf_s("%f", &termData->transAmount);
	if (termData->transAmount  <= 0)
	{
		printf(" INVALID_AMOUNT");
		return INVALID_AMOUNT;
	}

	else
	{
		//printf("TERMINAL_OK.");
		return TERMINAL_OK;

	}

}




EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	setMaxAmount(termData);
	if (termData->transAmount >= termData->maxTransAmount)
	{
		printf("EXCEED_MAX_AMOUNT\n");
		return EXCEED_MAX_AMOUNT;
	}

	else
	{
		//printf("TERMINAL_OK.");
		return TERMINAL_OK;
	}
}



EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
	termData->maxTransAmount = 10000;
	return TERMINAL_OK;
}*/
EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {

	if (!termData) {
		//printf("Actual Result : WRONG_DATE");
		return WRONG_DATE;
	}

	uint8_t date[12] = { 0 };
	gets(date);

	if ((strlen(date) != 10) || (date[2] != '/') || (date[5] != '/')) {
		//printf("Actual Result : WRONG_DATE");
		return WRONG_DATE;
	}
	else {
		for (int i = 0; i < 11; i++) {
			termData->transactionDate[i] = date[i];
		}
		//printf("Actual Result : TERMINAL_OK");
		return TERMINAL_OK;
	}




}




EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData) {

	// Years Check
	if ((cardData->cardExpirationDate[3] < termData->transactionDate[8]) || ((cardData->cardExpirationDate[3] == termData->transactionDate[8]) && (cardData->cardExpirationDate[4] < termData->transactionDate[9]))) {
		//printf("Actual Result : EXPIRED_CARD");
		return EXPIRED_CARD;
	}
	if ((cardData->cardExpirationDate[3] == termData->transactionDate[8]) && (cardData->cardExpirationDate[4] == termData->transactionDate[9])) {
		if ((cardData->cardExpirationDate[0] < termData->transactionDate[3]) || ((cardData->cardExpirationDate[0] == termData->transactionDate[3]) && (cardData->cardExpirationDate[1] < termData->transactionDate[4]))) {
			//printf("Actual Result : EXPIRED_CARD");
			return EXPIRED_CARD;
		}
		else {
			//printf("Actual Result : TERMINAL_OK");
			return TERMINAL_OK;
		}
	}
	else {
		//printf("Actual Result : TERMINAL_OK");
		return TERMINAL_OK;
	}

}
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {

	fseek(stdin, 0, SEEK_END); 
	float amount = 0;
	sscanf_s("%f", &amount);

	if (amount <= 0) {
		//printf("Actual Result : INVALID_AMOUNT");
		return INVALID_AMOUNT;
	}
	else {
		termData->transAmount = amount;
		//printf("Actual Result : TERMINAL_OK");
		return TERMINAL_OK;
	}


}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {

	//termData->maxTransAmount = 10000;

	if (termData->transAmount > termData->maxTransAmount) {
		//printf("Actual Result : EXCEED_MAX_AMOUNT");
		return EXCEED_MAX_AMOUNT;
	}
	else {
		//printf("Actual Result : TERMINAL_OK");
		return TERMINAL_OK;
	}


}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount) {

	if (maxAmount <= 0) {
		//printf("\nActual Result : INVALID_MAX_AMOUNT");
		return INVALID_MAX_AMOUNT;
	}
	else {
		termData->maxTransAmount = maxAmount;
		//printf("\nActual Result : TERMINAL_OK");
		return TERMINAL_OK;
	}



}



void getTransactionDateTest(void) {
	ST_terminalData_t data;

	printf("Tester Name : Abdalla Emad\n");
	printf("Function name : getTransactionDate\n");
	printf("Test Case 1 : NULL\nExpected Result : WRONG_DATE\nInput Data : ");
	getTransactionDate(&data);
	printf("\n\nTest Case 2 : 25/06/20223\nExpected Result : WRONG_DATE\nInput Data : ");
	getTransactionDate(&data);
	printf("\n\nTest Case 3 : 25/06\nExpected output : WRONG_DATE\nInput Data : ");
	getTransactionDate(&data);
	printf("\n\nTest Case 4 : 25-06-2022\nExpected Result : WRONG_DATE\nInput Data : ");
	getTransactionDate(&data);
	printf("\n\nTest Case 5 : 25/06/2022\nExpected Result : TERMINAL_OK\nInput Data : ");
	getTransactionDate(&data);


}

void isCardExpriedTest(void) {

	ST_cardData_t card;
	ST_terminalData_t data;
	printf("Tester Name : Abdalla Emad\n");
	printf("Function name : isCardExpriedTest\n");
	printf("Test Case 1 : Before\nExpected Result : EXPIRED_CARD\nInput Data : ");
	getCardExpiryDate(&card);
	getTransactionDate(&data);
	isCardExpired(&card, &data);
	printf("\n\nTest Case 2 : Equals\nExpected Result : TERMINAL_OK\nInput Data : ");
	getCardExpiryDate(&card);
	getTransactionDate(&data);
	isCardExpired(&card, &data);
	printf("\n\nTest Case 3 : After\nExpected Result : TERMINAL_OK\nInput Data : ");
	getCardExpiryDate(&card);
	getTransactionDate(&data);
	isCardExpired(&card, &data);


}


void getTransactionAmountTest(void) {
	ST_terminalData_t data;

	printf("Tester Name : Abdalla Emad\n");
	printf("Function name : getTransactionAmount\n");
	printf("Test Case 1 : 0\nExpected Result : INVALID_AMOUNT\nInput Data : ");
	getTransactionAmount(&data);
	printf("\n\nTest Case 2 : negative\nExpected Result : INVALID_AMOUNT\nInput Data : ");
	getTransactionAmount(&data);
	printf("\n\nTest Case 3 : Positive\nExpected output : TERMINAL_OK\nInput Data : ");
	getTransactionAmount(&data);
}


void isBelowMaxAmountTest(void) {

	ST_terminalData_t data;

	printf("Tester Name : Abdalla Emad\n");
	printf("Function name : isBelowMaxAmount\n");
	printf("Test Case 1 : 12000\nExpected Result : EXCEED_MAX_AMOUNT\nInput Data : ");
	getTransactionAmount(&data);
	isBelowMaxAmount(&data);
	printf("\n\nTest Case 2 : 10000\nExpected Result : TERMINAL_OK\nInput Data : ");
	getTransactionAmount(&data);
	isBelowMaxAmount(&data);
	printf("\n\nTest Case 3 : 5000\nExpected output : TERMINAL_OK\nInput Data : ");
	getTransactionAmount(&data);
	isBelowMaxAmount(&data);



}



void setMaxAmountTest(void) {
	ST_terminalData_t data;

	printf("Tester Name : Abdalla Emad\n");
	printf("Function name : setMaxAmount\n");
	printf("Test Case 1 : 0\nExpected Result : INVALID_MAX_AMOUNT\nInput Data : 0");
	setMaxAmount(&data, 0);
	printf("\n\nTest Case 2 : negative\nExpected Result : INVALID_MAX_AMOUNT\nInput Data : -12432");
	setMaxAmount(&data, -12432);
	printf("\n\nTest Case 3 : Positive\nExpected output : TERMINAL_OK\nInput Data : 32758");
	setMaxAmount(&data, 32758);
}