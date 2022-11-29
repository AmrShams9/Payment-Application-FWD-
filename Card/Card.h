
#include<stdio.h>
#include<stdint.h>
#include <string.h>
#include "../New header/STD_types.h"   //STD_Types.h file includes standard types as uint8,uint16 and so on
/*typedef struct ST_cardData_t
{
     uint8_t cardHolderName[25];
     uint8_t primaryAccountNumber[20];
     uint8_t cardExpirationDate[6];
}ST_cardData_t;
typedef enum EN_cardError_t
{
     CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;

/*ST_cardData_t x;
EN_cardError_t getCardHolderName(ST_cardData_t *cardData){
    x.cardHolderName[25];
    printf("Enter your name : ");
    scanf("%d", &x.cardHolderName);
    if (sizeof(x.cardHolderName) <= 24 && sizeof(x.cardHolderName) >= 20)
    {
        return CARD_OK;
    }else
    {
        return WRONG_NAME;
    }
}
    
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData){
    x.cardExpirationDate[6];
    printf("Enter Your Card expiry Date : ");
    scanf("%s\n", &x.cardExpirationDate);
    if (x.cardExpirationDate[2] == '/' && sizeof(x.cardExpirationDate) == 5)
    {
        return CARD_OK;
    }else
    {
        return WRONG_EXP_DATE;
    }


}
   EN_cardError_t getCardPAN(ST_cardData_t *cardData){
     printf("Enter Your Card PAN Number : ");
     scanf("%d\n", x.primaryAccountNumber);
     if (sizeof(x.primaryAccountNumber) <=19  && sizeof(x.primaryAccountNumber) >=16)
     {
          return CARD_OK;
     }else
     {
          return WRONG_PAN;
     }
     
     

   }*/
   
   #pragma once

#ifndef CARD_CARD_H_
#define CARD_CARD_H_

typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[7];
}ST_cardData_t;

typedef enum EN_cardError_t
{
    CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;


EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);

//Test functions
void getCardHolderNameTest(void);
void getCardExpiryDateTest(void);
void getCardPANTest(void);

#endif /* CARD_CARD_H_ */
