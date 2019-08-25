#include "./header/BM25.hpp"

double avg_length;

BM25::BM25(const std::vector<Text>& queries, const std::vector<Document>& docs) {
	calc_avg_length(docs);
	init_fqi_all(queries, docs);
}

void BM25::calc_avg_length(const std::vector<Document>& docs) {
	avg_length = 0.0;
	for (const auto& doc : docs) {
		avg_length += doc.get_length();
	}
	avg_length /= docs.size();
}

void BM25::init_fqi_all(const std::vector<Text>& queries, const std::vector<Document>& docs) {
	for (const auto& query : queries) {
		for (const auto& tok : query.tokens) {
			if (fqi_all.count(tok.first) > 0) continue; //this tok is checked
			for (auto& doc : docs) {
				if (doc.tokens.find(tok.first) != doc.tokens.end()) {
					++fqi_all[tok.first]; //increase the number of doc that contains tok
				}
			}
		}
	}
}

double BM25::idf(const std::string& tok, const size_t& n_of_docs) const {
	const auto it = fqi_all.find(tok);
	size_t fqi_val = 0;
	if (it != fqi_all.end()) {
		fqi_val = it->second;
	}
	return log(1 + (n_of_docs - fqi_val + 0.5) / (fqi_val + 0.5));
}

size_t BM25::fqi(const std::string& tok, const Document& doc) const {
	auto it = doc.tokens.find(tok);
	if (it != doc.tokens.end()) {
		return it->second;
	} else {
		return 0;
	}

}

double BM25::score(const Document& doc, const Text& query, const size_t& n_of_docs) const {
	double ans = 0.0;
	size_t i = 0;
	for (const auto& it : query.tokens) {
		std::string tok = it.first;
		auto fqi_val = fqi(tok, doc);
		ans += idf(tok, n_of_docs) * (fqi_val * (k + 1)) / (fqi_val + k * (1 - b + b * doc.get_length() / avg_length));
	}
	return ans;
}
