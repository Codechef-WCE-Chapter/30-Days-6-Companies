class Transaction {
    public:
    string personName;
    int transactionTime; 
    int transactionAmount;
    string transactionCity;
        
    Transaction(string name, int time, int amount, string city)
    {
        this->personName = name;
        this->transactionTime = time;
        this->transactionAmount = amount;
        this->transactionCity = city;
    }
};

class Solution {
public:

    vector<string> invalidTransactions(vector<string>& transactions) {
        int numTransactions = transactions.size();
        vector<bool> isValid(numTransactions, true);
        vector<Transaction> inputTransactions;
        
        for(int i=0; i<numTransactions; i++)
        {
            string currTransaction = transactions[i];
            string name = "", time = "", amount = "", city = "";
            int j = 0;
            
            while(currTransaction[j] != ',')
            {
                name += currTransaction[j++];
            }
            j++;
            while(currTransaction[j] != ',')
            {
                time += currTransaction[j++];
            }
            j++;
            while(currTransaction[j] != ',')
            {
                amount += currTransaction[j++];
            }
            j++;
            while((j < currTransaction.size()) && (currTransaction[j] != ','))
            {
                city += currTransaction[j++];
            }
            
            Transaction newTransaction(name, stoi(time), stoi(amount), city);
            inputTransactions.push_back(newTransaction);
        }
        
        for(int i=0;i<inputTransactions.size(); i++)
        {
            if(inputTransactions[i].transactionAmount > 1000)
                isValid[i] = false;
        }
        
        for(int i=0;i<(inputTransactions.size()); i++)
        {
            for(int j=0; j<inputTransactions.size(); j++)
            {
                if(i == j)
                    continue;
                    int timeDiff = abs(inputTransactions[j].transactionTime - inputTransactions[i].transactionTime);
                if(timeDiff <= 60)
                {
                    if((inputTransactions[j].personName == inputTransactions[i].personName) && (inputTransactions[j].transactionCity != inputTransactions[i].transactionCity))
                    {
                        isValid[i] = false;
                        isValid[j] = false;
                    }
                }
        }
    }
    vector<string> invalidTransactions;
    for(int i=0;i<inputTransactions.size(); i++)
    {
        if(!isValid[i])
            invalidTransactions.push_back(transactions[i]);
    }
    
    return invalidTransactions;
}
};