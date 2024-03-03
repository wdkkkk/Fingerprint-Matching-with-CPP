import os
import pybind11

from setuptools import setup, Extension

cpp_files = ['match.cpp']

module = Extension(
    'match',
    sources=cpp_files,
    include_dirs=[pybind11.get_include()]
)

setup(
    name='match',
    version='0.1',
    ext_modules=[module]
)
