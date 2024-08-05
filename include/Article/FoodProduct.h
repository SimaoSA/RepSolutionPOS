#pragma once
#include "Article.h"


class FoodProduct : public Article
{
	private:
		char _Score;

	public:
		FoodProduct(): _Score(' ') {}
		~FoodProduct() {}
		FoodProduct(int64_t idEAN13, double vat, double price, std::string description, char score);

	    void printArticle() const override;
		void SerializeArticle(std::ofstream& output) const override;
		void DeserializeArticle(std::ifstream& input) override;
		char getScoreFoodProduct() const;
		
};