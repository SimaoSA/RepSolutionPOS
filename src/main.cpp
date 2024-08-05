/// -------------- Read me --------------------- //
/*
--> Design Patterns Implemented for:
* 1. SystemPOS -> State Method;
* 2. Articles -> Factory Method;
* 3. Payments -> Strategy Method

--> I know that we needed other class to manager the POS for:
1. Control Invoices
2. Save all Information about transations ans sales
2. Manager sales
3. Operators
4. Others ...

--> Other Points:
1. After sale, the POS come back to State Ready


*/ // ------------------------------------- //


#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include "RuntimeStatePOS.h"
#include "ClientPayment.h"
#include "EletronicProductFactory.h"
#include "FoodProductFactory.h"
#include "FoodProduct.h"
#include "EletronicProduct.h"
#include <random>

using namespace std;


// ---  Aux Fucntions
std::unique_ptr<Article> FindProductByID(const std::vector<std::unique_ptr<Article>>& articlesBD, const int codeEAN13)
{

    for (const auto& article : articlesBD)
    {
        if (codeEAN13 == article->getIdArticle())
        {
            if (typeid(*article) == typeid(FoodProduct)) { return std::make_unique<FoodProduct>(*dynamic_cast<FoodProduct*>(article.get())); }

            else if(typeid(*article) == typeid(EletronicProduct)) { return std::make_unique<EletronicProduct>(*dynamic_cast<EletronicProduct*>(article.get())); }
        }
    }
    return nullptr;
}

void DisplayInfoToClient(const std::vector<std::unique_ptr<Article>>& listRegisteredProducts, double& SubTotal, double& SubTotal_Vat)
{
    // ---- Print Products
    SubTotal = 0;
    SubTotal_Vat = 0;
    std::cout << std::setw(12) << "Name" << "     " << std::setw(10) << "Price" << "   " << std::setw(10) << "VAT" << "%" << std::endl;
    for (const auto& product : listRegisteredProducts)
    {
        product->printArticle();
        SubTotal += product->getPriceArticle();
        SubTotal_Vat += product->getPriceArticle() * ((product->getVatArticle() / 100.0) + 1);
    }
    std::cout << endl << std::setw(20) << " SubTotal" << std::setw(10) << SubTotal << std::endl;
    std::cout << std::setw(20) << "SubTotal (VAT)" << std::setw(10) << SubTotal_Vat << std::endl;
}

// ---- Save and Read Data BD
void SaveArticlesDataBase(const std::string& filename, const std::vector<std::unique_ptr<Article>>& articles) {
    std::ofstream outFile(filename);
    if (!outFile) { throw std::runtime_error("File Open Error."); }

    for (const auto& article : articles) 
    {
        if (dynamic_cast<const FoodProduct*>(article.get())) { outFile << "FoodProduct "; }
           
        else if (dynamic_cast<const EletronicProduct*>(article.get())) { outFile << "EletronicProduct "; }
           
        article->SerializeArticle(outFile);
        outFile << std::endl;
    }
}

std::vector<std::unique_ptr<Article>> LoadArticlesDataBase(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) { throw std::runtime_error("File Open Error."); }

    std::vector<std::unique_ptr<Article>> articles;
    FoodProductFactory foodFactory;
    EletronicProductFactory eletronicFactory;
    std::string type;

    while (inFile >> type) 
    {
        try
        {
            std::unique_ptr<Article> article;

            if (type == "FoodProduct") { article = foodFactory.createArticle(0, 0, 0, "", ' '); }
            else if (type == "EletronicProduct") { article = eletronicFactory.createArticle(0, 0, 0, "", ""); }

            article->DeserializeArticle(inFile);
            articles.push_back(std::move(article));
        }
        catch(const std::exception&) { }
    }

    return articles;
}

// Invoice Generator
int generateRandomInvoiceNumber() {
    // Inicializa o gerador de n�meros aleat�rios com uma seed baseada no tempo atual
    std::mt19937 generator(static_cast<unsigned int>(std::time(0)));

    // Define o intervalo dos n�meros de fatura
    std::uniform_int_distribution<int> distribution(100000, 999999);

    // Gera e retorna um n�mero aleat�rio dentro do intervalo
    return distribution(generator);
}


int main()
{
    std::cout << std::fixed << std::setprecision(2);

    // Var to Control POS
    std::string StoreName = "    * Store Continente *    ";
    bool bPaymentOk = false;
    int64_t UserOption = 0;
    double SubTotal = 0;
    double SubTotal_Vat = 0;
    double AuxSubTotal_Vat = 0;

    // ---- Started var
	RuntimeStatePOS runtimeStatePOS(make_unique<SystemPOSIdle>());


    //List Data
    std::vector<std::unique_ptr<Article>> listRegisteredProducts; // Save Articles from client
    std::vector<std::unique_ptr<Article>> ArticlesDataBase; // All articles in BD
    std::vector<ClientPayment> listPayments; // Payments, it is possible to divide
    std::vector<int> listInvoiceNumber;

    // --- Loasd BD Articles
    ArticlesDataBase = LoadArticlesDataBase("../DataBaseArticles.txt");

 
	while(1)
	{
        if (typeid(runtimeStatePOS.getRuntimeStatePOS()) == typeid(SystemPOSIdle)) // Init State
        {
            system("clear");
            std::cout << "Login Operator: \n";
            std::cin >> UserOption;
            runtimeStatePOS.setStateSytemPOS(make_unique<SystemPOSReady>());
        }
        else if (typeid(runtimeStatePOS.getRuntimeStatePOS()) == typeid(SystemPOSReady)) // Ready
        {
            system("clear");
            listRegisteredProducts.clear();
            std::cout << "1. Logout Operator \n";
            std::cout << "Ready to Register Items \n";
            std::cin >> UserOption;

            if (UserOption == 1) { runtimeStatePOS.setStateSytemPOS(make_unique<SystemPOSIdle>()); }
            else
            { runtimeStatePOS.setStateSytemPOS(make_unique<SystemPOSItems>()); }
     
        }
        else if (typeid(runtimeStatePOS.getRuntimeStatePOS()) == typeid(SystemPOSItems)) // Register Items
        {
            static int64_t code = 1111111111110;
            if(UserOption < 1) { code++;  UserOption = code; } // Debug
            
            // Search into list of food
            std::unique_ptr<Article> foundProduct = FindProductByID(ArticlesDataBase, UserOption);
              
            // Search into list of eletronic if not found before
            if (foundProduct) { listRegisteredProducts.push_back(std::move(foundProduct)); }
   
            // ---- Print Products
            system("clear");
            DisplayInfoToClient(listRegisteredProducts, SubTotal, SubTotal_Vat);
           

            std::cout << "\n\n1. Checkout \n";
            std::cout << "2. Cancel \n";
            std::cin >> UserOption;

            if (UserOption == 1) { runtimeStatePOS.setStateSytemPOS(make_unique<SystemPOSPayments>()); }
        }
        else if (typeid(runtimeStatePOS.getRuntimeStatePOS()) == typeid(SystemPOSPayments)) // Payments
        {
            double valueInserted = 0;
            AuxSubTotal_Vat = SubTotal_Vat;

            system("clear");
            DisplayInfoToClient(listRegisteredProducts, SubTotal, AuxSubTotal_Vat);
            while (!bPaymentOk)
            {
                std::cout << "\n1. Cash Payment \n";
                std::cout << "2. Card Payment \n";
                std::cout << "3. MBWay Payment \n";
                std::cin >> UserOption;

                if (UserOption == 1) 
                { 
                    listPayments.push_back(ClientPayment(make_unique<CashPayment>()));
                    std::cout << " \n -> Selected Cash Payment \n";
                }
                else if (UserOption == 2) 
                { 
                    listPayments.push_back(ClientPayment(make_unique<CardPayment>()));
                    std::cout << "\n -> Selected Card Payment \n";
                }
                else if (UserOption == 3) 
                { 
                    listPayments.push_back(ClientPayment(make_unique<MBWAYPayment>()));
                    std::cout << "\n -> Selected MBWay Payment \n";
                }

                // Option is correct
                if (UserOption > 0 && UserOption < 4 && !listPayments.empty())
                {
                    std::cout << "Insert Value: ";
                    std::cin >> valueInserted;
                    std::cout << "\n";

                    // Last option
                    ClientPayment& clientPayment = listPayments.back();

                    if (!clientPayment.ProcessPayment(valueInserted, SubTotal_Vat) )
                    {
                        std::cout << "\n --- Incomplete Payment ---- \n";
                        std::cout << "Is Missing: " << clientPayment.getMissingToPay() << " " << endl;
                        SubTotal_Vat = clientPayment.getMissingToPay();
                    }
                    else
                    {
                        // ----- Print Invoice/Receipt
                        system("clear");
                        int invoiceNum = generateRandomInvoiceNumber();
                        listInvoiceNumber.push_back(invoiceNum);
                        std::cout << "\n****** Invoice/Receipt *****\n" << std::endl;
                        std::cout << StoreName << std::endl;
                        std::cout << "\n\nInvoice Number: " << invoiceNum << std::endl << std::endl << std::endl;

                        DisplayInfoToClient(listRegisteredProducts, SubTotal, AuxSubTotal_Vat);
                        std::cout << "\n\nYour Change: " << clientPayment.TakeYourChange() << " " << endl;
                        std::cout << "\n\n\n--- Client Payments ---- \n\n";
                        for (const ClientPayment& payment : listPayments)
                        {
                            payment.printPayment();
                        }

                        // Prepare Next Sale
                        listPayments.clear();
                        runtimeStatePOS.setStateSytemPOS(make_unique<SystemPOSReady>());
                        bPaymentOk = true;

                        std::cout << "\n\n* Thank you for your visit! * \n";
                        std::cout << "\n -> Press <1> to continue...  \n";
                        cin >> UserOption;
                    }
                }
            }

           bPaymentOk = false; //Prepare next payment
        }

        std::cout << " \n\n";
	}

	return 0;
}