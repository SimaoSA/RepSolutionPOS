#include "Article.h"
#include <iostream>
#include <iomanip>


Article::Article(int64_t idEAN13, double vat, double price, std::string description ) :
	_IdEAN13(idEAN13), _VAT(vat), _Price(price), _Description(description) {}

int Article::getIdArticle() const { return _IdEAN13; }

double Article::getVatArticle() const { return _VAT; }

double Article::getPriceArticle() const { return _Price; }

std::string Article::getDescriptionArticle() const { return _Description; }

void Article::SerializeArticle(std::ofstream& output) const
{
	output << _IdEAN13 << ' ' << _VAT << ' ' << _Price << ' ' << _Description << ' ';
}

void Article::DeserializeArticle(std::ifstream& input)
{
	input >> _IdEAN13 >> _VAT >> _Price;
	input.ignore(); 
	std::getline(input, _Description, ' ');
}