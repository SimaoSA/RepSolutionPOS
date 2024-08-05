#include "EletronicProductFactory.h"
#include "EletronicProduct.h"

std::unique_ptr<Article> EletronicProductFactory::createArticle(int64_t idEAN13, double vat, double price, std::string description, std::string power)
{
	return std::make_unique<EletronicProduct>(idEAN13, vat, price, description, power);
}





