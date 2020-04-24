from distutils.core import setup
from distutils.extension import Extension
import os


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

    fig_path, _ = os.path.split(os.path.realpath(__file__))
    fig_src_path = os.path.join(fig_path, "src")
    fig_include_path = os.path.join(fig_path, "include")

    ann_path = os.path.join(fig_path, "external", "ann_1.1.1")
    ann_src_path = os.path.join(ann_path, "src")
    ann_include_path = os.path.join(ann_path, "include")

    fig_sources = [os.path.join(fig_src_path, f) for f in os.listdir(fig_src_path) if f[-4:] == ".cpp"]
    ann_sources = [os.path.join(ann_src_path, f) for f in os.listdir(ann_src_path) if f[-4:] == ".cpp"]

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
            ann_src_path,
            ann_include_path,
            fig_include_path,
            numpy_include_dir],
    )
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
