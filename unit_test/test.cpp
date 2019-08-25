#include <iostream>
#include <cassert>
#include <cmath>
#include "../header/BM25.hpp"
#include "../header/text.hpp"

int main() {
    constexpr double eps = 0.00001;
    constexpr double test_score_1 = 0.919734;
    constexpr double test_score_2 = 1.05281;
    constexpr double test_score_3 = 0.734137;
    
    Document doc1 {"The Twist Feeling"};
    Document doc2 {"Smooth Rock"};
    Document doc3 {"Smooth Party Rock Anthem mix"};
    Document doc4 {"I Gotta Feeling"};
    Document doc5 {"Macarena (Bayside Boys mix)"};
    
    Text query1 {"Smooth as sandpaper"};
    Text query2 {"Rock Feeling"};
    
    std::vector<Document> list_docs {doc1, doc2, doc3, doc4, doc5};
    std::vector<Text> list_queries {query1, query2};
    
    BM25 bm25 { list_queries, list_docs};

    assert((std::fabs(bm25.score(doc1, query2, list_docs.size()) - test_score_1) < eps));
    assert((std::fabs(bm25.score(doc2, query1, list_docs.size()) - test_score_2) < eps));
    assert((std::fabs(bm25.score(doc3, query1, list_docs.size()) - test_score_3) < eps));
    std::cout << "All tests passed\n";
    
    return 0;
}