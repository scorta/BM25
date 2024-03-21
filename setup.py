from setuptools import setup, Extension
import pybind11

bm25_module = Extension('bm25',
                        sources=['bm25_binding.cpp', 'BM25.cpp', 'text.cpp', 'utility.cpp'],
                        include_dirs=['header', pybind11.get_include()],
                        language='c++')

setup(
    name='bm25',
    version='1.0',
    description='BM25 search algorithm',
    ext_modules=[bm25_module],
    py_modules=['bm25_search'],
    requires=['pybind11']
)
