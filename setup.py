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
)

# from setuptools import setup, Extension
# from setuptools.command.build_ext import build_ext


# # class BuildExtCommand(build_ext):
# #     def run(self):
# #         build_ext.run(self)
# #         self.run_command('build_ext')
# #         self.run_command('build_ext', inplace=True)
        
# bm25_module = Extension('bm25',
#                         sources=['BM25.cpp', 'text.cpp', 'utility.cpp'],
#                         include_dirs=['header'],
#                         language='c++')

# setup(
#     name='bm25',
#     version='1.0',
#     description='BM25 search algorithm',
#     ext_modules=[bm25_module],
#     py_modules=['bm25_search'],
#     # install_requires=[
#     #     'ctypes',
#     # ],
#     # cmdclass={
#     #     'build_ext': BuildExtCommand,
#     # },
# )