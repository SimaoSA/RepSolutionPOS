#pragma once
#include <iostream>
#include <string>
#include <fstream>

// ---- Design Pattern -> Factory Method

class Article
{
	protected:
		int64_t _IdEAN13;
		double _VAT;
		double _Price;
		std::string _Description;

		Article(int64_t idEAN13, double vat, double price, std::string description);


	public:
		Article():  _IdEAN13(0), _VAT(0.0), _Price(0.0), _Description("") {}
		virtual ~Article() {}
		int getIdArticle() const;
		double getVatArticle() const;
		double getPriceArticle() const;
		std::string getDescriptionArticle() const;		
		virtual void printArticle() const = 0;
		virtual void SerializeArticle(std::ofstream& output) const;
		virtual void DeserializeArticle(std::ifstream& input);

};

