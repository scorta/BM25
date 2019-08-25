#ifndef BM25_H
#define BM25_H

#include <cmath>
#include <unordered_map>
#include <string>
#include <vector>
// #include "BM25.hpp"
#include "text.hpp"

class BM25 {
public:
	static constexpr double k = 1.2;
	static constexpr double b = 0.75;

	BM25(const std::vector<Text>& queries, const std::vector<Document>& docs);
	double score(const Document& doc, const Text& query, const size_t& n_of_docs) const;

private:
	void calc_avg_length(const std::vector<Document>& docs);
	void init_fqi_all(const std::vector<Text>& queries, const std::vector<Document>& docs);
	double idf(const std::string& qi, const size_t& n_of_docs) const;
	size_t fqi(const std::string& tok, const Document& doc) const;
	std::unordered_map<std::string, size_t> fqi_all; //f(qi) number of docs that contain term qi
};

#endif // !BM25_H