from distutils.core import setup
from distutils.extension import Extension
import os


PY_DIR, _ = os.path.split(os.path.realpath(__file__))
FIG_PATH, _ = os.path.split(PY_DIR)

INCLUDE_PATH = os.path.join(FIG_PATH, "include")
ANN_PATH = os.path.join(FIG_PATH, "external", "ann_1.1.1")
ANN_INCLUDE_PATH = os.path.join(ANN_PATH, "include")
ANN_SRC_PATH = os.path.join(ANN_PATH, "src")
SRC_PATH = os.path.join(FIG_PATH, "src")


__version_str__ = "1.0.0"


class lazy_cythonize(list):
    def __init__(self, callback):
        self._list, self.callback = None, callback
    def c_list(self):
        if self._list is None: self._list = self.callback()
        return self._list
    def __iter__(self):
        for e in self.c_list(): yield e
    def __getitem__(self, ii): return self.c_list()[ii]
    def __len__(self): return len(self.c_list())


def extensions():
    import numpy
    from Cython.Build import cythonize

    fig_sources = [os.path.join(SRC_PATH, f) for f in os.listdir(SRC_PATH) if f[-4:] == ".cpp"]
    ann_sources = [os.path.join(ANN_SRC_PATH, f) for f in os.listdir(ANN_SRC_PATH) if f[-4:] == ".cpp"]

    print(fig_sources)
    print(ann_sources)

    numpy_include_dir = numpy.get_include()
    figtree_module = Extension(
        "figtree",
        [
            "figtree.pyx",
            *fig_sources,
            *ann_sources
        ],
        language="c++",
        include_dirs=[
            ANN_SRC_PATH,
            ANN_INCLUDE_PATH,
            INCLUDE_PATH,
            numpy_include_dir],
    )
    print(figtree_module.sources)
    return cythonize([figtree_module])

setup(
    name="Figtree",
    version=__version_str__,
    description="An implementation of the Fast Gauss Transform",
    author="Vlad Morariu",
    url="https://github.com/mikeswhitney33/figtree",
    ext_modules=lazy_cythonize(extensions),
    requires=['numpy','Cython'],
    setup_requires=['numpy', 'Cython']
)