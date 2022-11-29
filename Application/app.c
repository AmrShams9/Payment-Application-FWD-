#include <stdio.h>
// #include"C:\Users\amrkh\OneDrive\Desktop\Server\Terminal\Card\Card.h"
// #include "C:\Users\amrkh\OneDrive\Desktop\Server\Terminal\Terminal.h"
// #include "C:\Users\amrkh\OneDrive\Desktop\Server\Terminal\Server\server.h"
// #include "C:\Users\amrkh\OneDrive\Desktop\Server\Terminal\Card\Application\app.h"
#include "../Card/Card.h"
#include "../Terminal/Terminal.h"
#include "../srvr/server.h"
#include"../Application/app.h"
#include "../STD_types.h"   //STD_Types.h file includes standard types as uint8,uint16 and so on
/*ST_cardData_t cardData;
ST_terminalData_t termData;
ST_transaction_t transData;
uint32_t transactionSequenceNumber=0;
void appStart(void){
{
	while (1)
	{
		if (getCardHolderName(&(transData.cardHolderData)) == CARD_OK)
		{
			if (getCardExpiryDate(&(transData.cardHolderData)) == CARD_OK)
			{
				if (getTransactionDate(&transData.terminalData) == TERMINAL_OK)
				{
					if (isCardExpired(&(transData.cardHolderData),&(transData.terminalData)) == TERMINAL_OK)
					{
						if (isValidAccount(&(transData.cardHolderData), &transData, &termData) == APPROVED)
						{
							if (recieveTransactionData(&transData) == APPROVED)
							{
								saveTransactionDate(&transData);
								getTransactionDate(transactionSequenceNumber, &transData);
							}
						}

					}
				}
			}
		}
	}
}
   }*/
   void appStart(void) {
	ST_transaction trans;
	EN_transStat_t transvariable =  recieveTransactionData(&trans);
	// In receive I checked if the account is blocked and if it is valid or if the amount available
	ST_accountsDB_t ref;
	if (isCardExpired(&trans.cardHolderData, &trans.terminalData) == TERMINAL_OK) {
		//getTransactionAmount(&trans.terminalData);
		if (isBelowMaxAmount(&trans.terminalData) == TERMINAL_OK) {
			if (isValidAccount(&trans.cardHolderData, &ref) == SERVER_OK) {
				//recieveTransactionData(&trans);
				if (transvariable == APPROVED)
				{
					if (saveTransaction(&trans) == SERVER_OK)
					{
						printf("\nTranscation Saved");
					}
					else
						printf("\nSaving Failed");
				}
				else if (transvariable == DECLINED_STOLEN_CARD)
				{
					printf("\nDeclined Invalid Account");
				}
				else if (transvariable == DECLINED_INSUFFECIENT_FUND) {
					printf("\nInsuffecient Funds");
				}
				else {
					printf("Hello");
				}
					
			}
		}
		else if (isBelowMaxAmount(&trans.terminalData) == EXCEED_MAX_AMOUNT) {
			printf("Exceed Max Amount");
		}
	}
	else if (isCardExpired(&trans.cardHolderData, &trans.terminalData) == EXPIRED_CARD) {
		printf("Expired Card");
	}


}