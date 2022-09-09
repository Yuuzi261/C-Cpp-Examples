#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    double PurchasePrice,
           DownPayment,
           AnnualInterestRate,
           PaymentsNumber,          //total number of payments
           Principal,               //the amount you borrow = the purchase price minus the down-payment
           MonthlyInterestRate,     //equal the annual interest rate divide by 12
           PaymentPerMonth;         //how much money you should pay per month

    printf("Enter the purchase price >");
    scanf("%lf", &PurchasePrice);
    printf("Enter the down-payment >");
    scanf("%lf", &DownPayment);
    printf("Enter the annual interest rate >");
    scanf("%lf", &AnnualInterestRate);
    printf("Enter the total number of payments >");
    scanf("%lf", &PaymentsNumber);

    Principal = PurchasePrice - DownPayment;
    MonthlyInterestRate = AnnualInterestRate / 12;
    PaymentPerMonth = (MonthlyInterestRate * Principal) / (1 - pow(1 + MonthlyInterestRate, -1 * PaymentsNumber));

    printf("\nThe amount you borrow : $%.2lf\nThe monthly payment  $%.2lf\n", Principal, PaymentPerMonth);

    return 0;

}