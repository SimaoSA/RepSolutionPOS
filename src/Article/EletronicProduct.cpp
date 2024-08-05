#include "EletronicProduct.h"
#include <iostream>
#include <iomanip>


EletronicProduct::EletronicProduct(int64_t idEAN13, double vat, double price, std::string description, std::string power) :
								 _Power(power), Article(idEAN13, vat, price, description) { }

std::string  EletronicProduct::getPowerEletronicProduct() const { return _Power; }

void EletronicProduct::printArticle() const
{
	std::cout << std::setw(12) << _Description << "     " << std::setw(10) << _Price << "   " << std::setw(10) << _VAT << "%" << std::endl;
}


void EletronicProduct::SerializeArticle(std::ofstream& output) const
{
	Article::SerializeArticle(output);
	output << _Power << '\n';
}

void EletronicProduct::DeserializeArticle(std::ifstream& input)
{
	Article::DeserializeArticle(input);
	std::getline(input, _Power);
}


