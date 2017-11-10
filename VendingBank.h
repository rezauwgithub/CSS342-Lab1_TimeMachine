// Reza Naeemi
#pragma once

class VendingBank
{
	private:

		const static int NUMBER_OF_EACH_TYPE_OF_COIN;
		const static double VALUE_OF_A_NICKLE_COIN;
		const static double VALUE_OF_A_DIME_COIN;
		const static double VALUE_OF_A_QUARTER_COIN;
		const static double VALUE_OF_A_HALFDOLLAR_COIN;
		const static double VALUE_OF_A_GOLDDOLLAR_COIN;

		int vendingBankID;

		double totalFunds;

		int nickleCoinCount;
		int dimeCoinCount;
		int quarterCoinCount;
		int halfDollarCoinCount;
		int goldDollarCoinCount;
		int oneDollarBillCount;
		int twoDollarsBillCount;
		int fiveDollarsBillCount;


		int lastNumberOfNickleCoinsAdded;
		int lastNumberOfDimeCoinsAdded;
		int lastNumberOfQuarterCoinsAdded;
		int lastNumberOfHalfDollarCoinsAdded;
		int lastNumberOfGoldDollarCoinAdded;

		void initilizeVendingBankFunds();

	public:


		VendingBank();
		VendingBank(int id);
		~VendingBank();

		int getVendingBankID() const;

		int getNickleCoinCount() const;
		int getDimeCoinCount() const;
		int getQuarterCoinCount() const;
		int getHalfDollarCount() const;
		int getGoldDollarCoinCount() const;
		int getOneDollarBillCount() const;
		int getTwoDollarsBillCount() const;
		int getFiveDollarsBillCount() const;


		bool depositXNumberOfNickleCoins(int x);
		bool depositXNumberOfDimeCoins(int x);
		bool depositXNumberOfQuarterCoins(int x);
		bool depositXNumberOfHalfDollar(int x);
		bool depositXNumberOfGoldDollarCoins(int x);
		bool depositXNumberOfOneDollarBills(int x);
		bool depositXNumberOfTwoDollarsBills(int x);
		bool depositXNumberOfFiveDollarsBills(int x);


		bool withdrawlXNumberOfNickleCoins(int x);
		bool withdrawlXNumberOfDimeCoins(int x);
		bool withdrawlXNumberOfQuarterCoins(int x);
		bool withdrawlXNumberOfHalfDollar(int x);
		bool withdrawlXNumberOfGoldDollarCoins(int x);
		bool withdrawlXNumberOfOneDollarBills(int x);
		bool withdrawlXNumberOfTwoDollarsBills(int x);
		bool withdrawlXNumberOfFiveDollarsBills(int x);


		void fillVendingBankWithCoins();
		double getTotalFunds() const;

};

