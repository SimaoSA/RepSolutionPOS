#include "FoodProductFactory.h"
#include "FoodProduct.h"

std::unique_ptr<Article> FoodProductFactory::createArticle(int64_t idEAN13, double vat, double price, std::string description, char score)  
{
	return std::make_unique<FoodProduct>(idEAN13, vat, price, description, score);
}





