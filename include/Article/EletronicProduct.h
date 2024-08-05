#pragma once
#include "Article.h"


class EletronicProduct : public Article
{
	private:
		std::string _Power;

	public:
		EletronicProduct(): _Power("") {}
		~EletronicProduct() {}
		
		EletronicProduct(int64_t idEAN13, double vat, double price, std::string description, std::string power);

		void printArticle() const override;
		void SerializeArticle(std::ofstream& output) const override;
		void DeserializeArticle(std::ifstream& input) override;
		std::string getPowerEletronicProduct() const;
};
