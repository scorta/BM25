import ctypes
# import bm25

# # Define the necessary C++ data types
class Text(ctypes.Structure):
    _fields_ = [
        ('content', ctypes.c_char_p),
        ('tokens', ctypes.POINTER(ctypes.c_char_p)),
        ('length', ctypes.c_size_t)
    ]

class Document(ctypes.Structure):
    _fields_ = [
        ('content', ctypes.c_char_p),
        ('tokens', ctypes.POINTER(ctypes.c_char_p)),
        ('length', ctypes.c_size_t),
        ('score', ctypes.c_double)
    ]

# class BM25(ctypes.Structure):
#     pass

# # Define the function prototypes
# bm25.BM25_new.argtypes = [ctypes.POINTER(Text), ctypes.c_size_t, ctypes.POINTER(Document), ctypes.c_size_t]
# bm25.BM25_new.restype = ctypes.POINTER(BM25)

# bm25.BM25_delete.argtypes = [ctypes.POINTER(BM25)]
# bm25.BM25_delete.restype = None

# bm25.BM25_score.argtypes = [ctypes.POINTER(BM25), ctypes.POINTER(Document), ctypes.POINTER(Text), ctypes.c_size_t]
# bm25.BM25_score.restype = ctypes.c_double

# # Utility functions
# bm25.remove_vn_tone.argtypes = [ctypes.c_char_p]
# bm25.remove_vn_tone.restype = ctypes.c_char_p

# bm25.remove_meaningless_char.argtypes = [ctypes.c_char_p]
# bm25.remove_meaningless_char.restype = ctypes.c_char_p

# def create_text(content):
#     text = Text()
#     text.content = content.encode('utf-8')
#     return text

# def create_document(content):
#     doc = Document()
#     doc.content = content.encode('utf-8')
#     return doc

# def bm25_search(queries, docs):
#     query_array = (Text * len(queries))()
#     for i, query in enumerate(queries):
#         query_array[i] = create_text(query)

#     doc_array = (Document * len(docs))()
#     for i, doc in enumerate(docs):
#         doc_array[i] = create_document(doc)

#     bm25_obj = bm25.BM25_new(query_array, len(queries), doc_array, len(docs))

#     scores = []
#     for doc in doc_array:
#         score = bm25.BM25_score(bm25_obj, ctypes.byref(doc), query_array, len(queries))
#         scores.append(score)

#     bm25.BM25_delete(bm25_obj)

#     return scores

# def remove_vn_tone(text):
#     return bm25.remove_vn_tone(text.encode('utf-8')).decode('utf-8')

# def remove_meaningless_char(text):
#     return bm25.remove_meaningless_char(text.encode('utf-8')).decode('utf-8')

# # Example usage
# if __name__ == '__main__':
#     queries = ['Smooth as sandpaper', 'Rock Feeling']
#     docs = [
#         'The Twist Feeling',
#         'Smooth Rock',
#         'Smooth Party Rock Anthem mix',
#         'I Gotta Feeling',
#         'Macarena (Bayside Boys mix)'
#     ]

#     scores = bm25_search(queries, docs)
#     print(scores)

# import bm25

# def bm25_search(queries, docs):
#     bm25_obj = bm25.BM25(queries, docs)
#     scores = []
#     for doc in docs:
#         score = bm25_obj.score(doc, queries[0], len(docs))
#         scores.append(score)
#     return scores

# def remove_vn_tone(text):
#     return bm25.remove_vn_tone(text)

# def remove_meaningless_char(text):
#     return bm25.remove_meaningless_char(text)

# # Example usage
# if __name__ == '__main__':
#     queries = ['Smooth as sandpaper', 'Rock Feeling']
#     docs = [
#         'The Twist Feeling',
#         'Smooth Rock',
#         'Smooth Party Rock Anthem mix',
#         'I Gotta Feeling',
#         'Macarena (Bayside Boys mix)'
#     ]

#     scores = bm25_search(queries, docs)
#     print(scores)

import bm25

def bm25_search(queries, docs):
    query_texts = [bm25.Text(query) for query in queries]
    doc_texts = [bm25.Document(doc) for doc in docs]
    
    bm25_obj = bm25.BM25(query_texts, doc_texts)
    scores = []
    for doc in doc_texts:
        score = bm25_obj.score(doc, query_texts[0], len(doc_texts))
        scores.append(score)
    return scores

def remove_vn_tone(text):
    return bm25.remove_vn_tone(text)

def remove_meaningless_char(text):
    return bm25.remove_meaningless_char(text)

# Example usage
if __name__ == '__main__':
    queries = ['Smooth as sandpaper', 'Rock Feeling']
    docs = [
        'The Twist Feeling',
        'Smooth Rock',
        'Smooth Party Rock Anthem mix',
        'I Gotta Feeling',
        'Macarena (Bayside Boys mix)'
    ]

    scores = bm25_search(queries, docs)
    print(scores)