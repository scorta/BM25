# BM25
An implementation of Okapi BM25 algorithm in C++. The library is splitted into 2 file: header (BM25.hpp) & source (BM25.cpp)

# Basic Search Engine
This program (basic_se.cpp) demonstrates the usage of BM25 library (BM25.cpp) and reverse index algorithm to score documents
Usage: ./{this program} {query_file} {doc_file} {output prefix}
{doc_file}: For simple demonstration, each doc is a line in this file. Modify the program to suit your needs.
eg. ./search queries.txt docs.txt res
it will creat 2 output file: res_bm25 & res_reverse_index with format:
<blank>	query-1	query-2	...	query-n
doc-1	score-1.1	score-1.2	... score-1.n
doc-2	score-2.1	score-2.2	... score-2.n
...
Note that reverse index algorithm is much simpler, and has worse quality than BM25.

TODO: work with non-tone Vietnamese text. We can use the function utility::remove_vn_tone() to remove tone, but how to score a non-tone text?
Eg:
query: "bún chả"
doc-1: "bún chả rất ngon"
doc-2 (non-tone version): "bun cha rat ngon"
We understand that doc-1 and doc-2 are similar, but doc-2 should have lower score than doc-1. But how much?

References:
BM25: https://en.wikipedia.org/wiki/Okapi_BM25
Reverse index: https://www.elastic.co/guide/en/elasticsearch/guide/current/inverted-index.html