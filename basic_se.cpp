#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "./header/text.hpp"
#include "./header/BM25.hpp"
#include "./header/utility.hpp"

void handle_error(const std::string& err);

template<typename T>
void read_data(std::vector<T>& vec, const std::string& in_file_name);

void bm25_search(const std::vector<Text>& queries, std::vector<Document>& docs, const std::string& file_output_prefix);

void reverse_index_score(const Text& query, Document& doc);

void reverse_index_search(const std::vector<Text>& queries, std::vector<Document>& docs, const std::string& file_output_prefix);

int main(int argc, char** argv) {
	std::string file_query_name{ argv[1] }, file_doc_name{ argv[2] }, file_output_prefix{ argv[3] };
	std::vector<Text> queries;
	std::vector<Document> docs;
	
	std::cout << "Start reading data...\n";
	read_data(queries, file_query_name);
	read_data(docs, file_doc_name);
	std::cout << "Reading data done.\n";
	
	std::cout << "Start scoring docs...\n";
	bm25_search(queries, docs, file_output_prefix);
	reverse_index_search(queries, docs, file_output_prefix);
	std::cout << "Done, please check the output files.\n";

	return 0;
}

void bm25_search(const std::vector<Text>& queries, std::vector<Document>& docs, const std::string& file_output_prefix) {
	std::ofstream file_out_bm25{ file_output_prefix + "_bm25" };
	BM25 bm25{ queries, docs };
	std::string out_put{ "" };
	out_put += "\t";
	for (const auto& query : queries) {
		out_put += query.content + "\t";
	}
	out_put.back() = '\n';
	for (auto& doc : docs) {
		out_put += doc.content + "\t";
		for (const auto& query : queries) {
			doc.score = bm25.score(doc, query, docs.size());
			out_put += std::to_string(doc.score) + "\t";
		}
		out_put.back() = '\n';
	}
	file_out_bm25 << out_put;
}

void reverse_index_score(const Text& query, Document& doc) {
	doc.score = 0;
	for (const auto& tok : query.tokens) {
		if (doc.tokens.count(tok.first) > 0) {
			++doc.score;
		}
	}
}

void reverse_index_search(const std::vector<Text>& queries, std::vector<Document>& docs, const std::string& file_output_prefix) {
	std::ofstream file_out_reverse_index{ file_output_prefix + "_reverse_index" };

	std::string out_put{ "" };
	out_put += "\t";
	for (const auto& query : queries) {
		out_put += query.content + "\t";
	}
	out_put.back() = '\n';
	for (auto& doc : docs) {
		out_put += doc.content + "\t";
		for (const auto& query : queries) {
			reverse_index_score(query, doc);
			out_put += std::to_string(doc.score) + "\t";
		}
		out_put.back() = '\n';
	}
	file_out_reverse_index << out_put;
}

void handle_error(const std::string& err) {
	std::cout << "The program encountered an error:\n"
		<< err << "\nAnd now will stop.";
	std::exit(EXIT_FAILURE);
}

template<typename T>
void read_data(std::vector<T>& vec, const std::string& in_file_name) {
	std::ifstream f{ in_file_name };
	if (!f) {
		handle_error("Can't read file");
	}
	std::string s;
	while (std::getline(f, s)) {
		s = utility::remove_meaningless_char(s);
		std::transform(s.begin(), s.end(), s.begin(), ::tolower);
		vec.push_back({ s });
	}
}