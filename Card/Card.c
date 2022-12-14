#include "Card.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../STD_types.h"   //STD_Types.h file includes standard types as uint8,uint16 and so on
/*EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
    EN_cardError_t Card_Status = CARD_OK;

    uint8_t HolderName[25] = {0};

    printf(" Enter Your name: ");
    gets(HolderName);

    uint8_t NameLength = strlen(HolderName);

    if( (NULL == HolderName) || (NameLength <= 20) || (NameLength >= 24) )
    {
        Card_Status = WRONG_NAME;
    }
    else 
    {
        strcpy(cardData->cardHolderName, HolderName);
    }

    return Card_Status;}
    EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
    EN_cardError_t Card_Status = CARD_OK;

    uint8_t ExpDate[25] = {0};

    printf(" Enter the card expiration date: ");
    gets(ExpDate);

    uint8_t DateLength = strlen(ExpDate);

    if( (NULL == ExpDate) || (DateLength !=5) || (ExpDate[2] != '/') )
    {
        Card_Status = WRONG_EXP_DATE;
    }
    else 
    {
        strcpy(cardData->cardExpirationDate, ExpDate);
    }
    return Card_Status;
    }


    EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
    EN_cardError_t Card_Status = CARD_OK;

    uint8_t cardPan[20] = {0};

    printf(" Enter Your account number : ");
    gets(cardPan);
    
    uint8_t PanLength = strlen(cardPan);

    if( (NULL == cardPan) || (PanLength <= 16) || (PanLength >= 20) )
    {
        Card_Status = WRONG_PAN;
    }
    else 
    {
        strcpy(cardData->primaryAccountNumber, cardPan);
    }
    
    return Card_Status;
}
EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	printf("\nPlease, Enter Your Name\n");
	gets(cardData->cardHolderName);

	if (strlen(cardData->cardHolderName) > 24 || strlen(cardData->cardHolderName) < 20 || cardData->cardHolderName == NULL)
	{
		printf("WRONG NAME\n");
		return WRONG_NAME;
	}
	else
	{
		//printf("CARD_OK\n");
		return CARD_OK;
	}
}




EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	printf("\nPlease, Enter Your Card Expir Date in Format  MM/YY   \n");
	gets(cardData->cardExpirationDate);

	if (strlen(cardData->cardExpirationDate) == 5 && cardData->cardExpirationDate[0] <= '1' && cardData->cardExpirationDate[1] <= '9' && cardData->cardExpirationDate[2] == '/' && cardData->cardExpirationDate[3] <= '3' && cardData->cardExpirationDate[4] <= '9')
	{
		//printf("CARD_OK\n");
		return CARD_OK;
	}
	else
	{
		printf("WRONG_EXP_DATA\n");
		return WRONG_EXP_DATE;

	}

}






EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	printf("\nPlease, Enter Your card's Primary Account Number \n");
	gets(cardData->primaryAccountNumber);

	if (strlen(cardData->primaryAccountNumber) > 19 || strlen(cardData->primaryAccountNumber) < 16 || cardData->primaryAccountNumber == NULL)
	{

		printf("WRONG_PAN\n");
		return WRONG_PAN;


	}
	else
	{
		//printf("CARD_OK\n");
		return CARD_OK;


	}

}*/
EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {


	uint8_t name[30] = { 0 };
	gets(name);

	if (name == NULL || strlen(name) < 20 || strlen(name) > 24) {   // If it is Null or not of the allowed size
		printf("Actual Result : WRONG_NAME");
		return WRONG_NAME;
	}
	else {
		uint8_t i = 0;
		for (i = 0; i < strlen(name); i++) {
			if (!isalpha(name[i]) && (name[i] != ' ')) {   // Allow to enter alphapets only
				//printf("Actual Result : WRONG_NAME");
				return WRONG_NAME;
			}
			else {  //strlen 23
				cardData->cardHolderName[i] = name[i];
			}
		}
		cardData->cardHolderName[i] = '\0';
		//printf("Actual Result : CARD_OK");
		return CARD_OK;
	}
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {

	if (!cardData) {    //Check if it is NULL
		//printf("WRONG_EXP_DATE");
		return WRONG_EXP_DATE;
	}

	uint8_t date[12] = { 0 };  // MM/YY  05/25
	gets(date);

	int i = 0;
	for (i = 0; i < 6; i++) {
		if ((strlen(date) != 5) || (date[0] > '1') || ((date[0] == '1') && (date[1] > '2')) || (date[2] != '/')) {
			//printf("Actual Result : WRONG_EXP_DATE");
			return WRONG_EXP_DATE;
		}
		else {
			cardData->cardExpirationDate[i] = date[i];
		}
	}
	//printf("Actual Result : CARD__OK");
	return CARD_OK;
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData) {

	if (!cardData) {
		//printf("Actual Result : WRONG_PAN");
		return WRONG_PAN;
	}

	uint8_t pan[25] = { 0 };
	gets(pan);

	if ((strlen(pan) < 16) || (strlen(pan) > 19)) {
		//printf("Actual Result : WRONG_PAN");
		return WRONG_PAN;
	}
	else {
		for (int i = 0; i < 18; i++) {
			cardData->primaryAccountNumber[i] = pan[i];
		}
	}
	//printf("Actual Result : CARD_OK");
	return CARD_OK;

}

void getCardHolderNameTest(void) {


	ST_cardData_t card;

	printf("Tester Name : Abdalla Emad\n");
	printf("Function name : getCardHolderName\n");
	printf("Test Case 1 : NULL\nExpected Result : WRONG_NAME\nInput Data : ");
	getCardHolderName(&card);
	printf("\n\nTest Case 2 : Abdalla\nExpected Result : WRONG_NAME\nInput Data : ");
	getCardHolderName(&card);   //Abdalla
	printf("\n\nTest Case 3 : Abdalla Emad Abdalla Awad\nExpected output : WRONG_NAME\nInput Data : ");
	getCardHolderName(&card);   //Abdalla Emad Abdalla Awad
	printf("\n\nTest Case 4 : Abdalla Emad Abdalla$$\nExpected Result : WRONG_NAME\nInput Data : ");
	getCardHolderName(&card);   //Abdalla Emad Abdalla$$
	printf("\n\nTest Case 5 : Abdalla Emad Abdalla Aw\nExpected Result : CARD_OK\nInput Data : ");
	getCardHolderName(&card);   //Abdalla Emad Abdalla Aw


}


void getCardExpiryDateTest(void) {
	ST_cardData_t card;

	printf("Tester Name : Abdalla Emad\n");
	printf("Function name : getCardExpiryDate\n");
	printf("Test Case 1 : NULL\nExpected Result : WRONG_EXP_DATE\nInput Data : ");
	getCardExpiryDate(&card);
	printf("\n\nTest Case 2 : 14/06/23\nExpected Result : WRONG_EXP_DATE\nInput Data : ");
	getCardExpiryDate(&card);
	printf("\n\nTest Case 3 : 06-23\nExpected output : WRONG_EXP_DATE\nInput Data : ");
	getCardExpiryDate(&card);
	printf("\n\nTest Case 4 : 06\nExpected Result : WRONG_EXP_DATE\nInput Data : ");
	getCardExpiryDate(&card);
	printf("\n\nTest Case 5 : 06/23\nExpected Result : CARD_OK\nInput Data : ");
	getCardExpiryDate(&card);
}



void getCardPANTest(void) {
	ST_cardData_t card;

	printf("Tester Name : Abdalla Emad\n");
	printf("Function name : getCardPAN\n");
	printf("Test Case 1 : NULL\nExpected Result : WRONG_PAN\nInput Data : ");
	getCardPAN(&card);
	printf("\n\nTest Case 2 : 123456789\nExpected Result : WRONG_PAN\nInput Data : ");
	getCardPAN(&card);
	printf("\n\nTest Case 3 : 123456789123456789123\nExpected output : WRONG_PAN\nInput Data : ");
	getCardPAN(&card);
	printf("\n\nTest Case 4 : 123456789123456789\nExpected Result : CARD_OK\nInput Data : ");
	getCardPAN(&card);
}
