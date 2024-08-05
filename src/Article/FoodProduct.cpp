#include "FoodProduct.h"
#include <iostream>
#include <iomanip>


FoodProduct::FoodProduct(int64_t idEAN13, double vat, double price, std::string description, char score) :
						_Score(score), Article(idEAN13, vat, price, description) {}


char FoodProduct::getScoreFoodProduct() const { return _Score; }

void FoodProduct::printArticle() const
{
	std::cout << std::setw(12) << _Description << "     " << std::setw(10) << _Price << "   " << std::setw(10) << _VAT << "%" << std::endl;
}

void FoodProduct::SerializeArticle(std::ofstream& output) const
{
	Article::SerializeArticle(output);
	output << _Score << '\n';
}

void FoodProduct::DeserializeArticle(std::ifstream& input)
{
	Article::DeserializeArticle(input);
	input >> _Score;
}


