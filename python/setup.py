# Author: Vlad Morariu
# Created: 2012-01-25
from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext
import numpy
import sys
import os

CURRENT_DIR = os.path.dirname(os.path.realpath(__file__))
FIGTREE_PATH = os.path.join(*os.path.split(CURRENT_DIR)[:-1])
LIB_PATH = os.path.join(FIGTREE_PATH, "lib")
INCLUDE_PATH = os.path.join(FIGTREE_PATH, "include")

if not sys.platform == 'win32':
   include_dirs=[INCLUDE_PATH, numpy.get_include()]
   library_dirs=[LIB_PATH]
   libraries=['figtree', 'ann_figtree_version']
   extra_compile_args=['-DNDEBUG', '-O2']
else:
   include_dirs=[INCLUDE_PATH, numpy.get_include()]
   library_dirs=[LIB_PATH]
   libraries=['figtree', 'ann_figtree_version']
   extra_compile_args=['-O2']

ext_modules = [Extension(
                         "figtree",
                         ["figtree.pyx"],
                         language="c++",
                         include_dirs=include_dirs,
                         library_dirs=library_dirs,
                         libraries=libraries,
                         extra_compile_args=extra_compile_args,
                         extra_link_args=[])]

for e in ext_modules:
   e.pyrex_directives={'embedsignature': True}

setup(
    ext_modules=ext_modules,
    cmdclass={'build_ext' : build_ext}
)
