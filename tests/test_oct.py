
from ctypes import CDLL

import pytest

@pytest.fixture
def liboct():
    yield CDLL("../bin/lib_oct_converter.so")

@pytest.mark.parametrize("dec,oct", [(0, 0), (1, 1), (8, 10), (70, 106), (707, 1303), (-1, -1), (-8, -10), (-70, -106), (-707, -1303)])
def test_oct_conv(liboct, dec : int, oct : int):
    assert liboct.dec_to_oct(dec) == oct
