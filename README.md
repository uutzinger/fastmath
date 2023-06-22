fastmath
========
This was implemented to learn C bindings for python and to experiment with the
[fast inverse square root function](https://en.wikipedia.org/wiki/Fast_inverse_square_root)

The fast inverse square root implementation in ```C``` is slower than value**-0.5 in Python.
There is no speed increase from regular inverse square root to fast inverse square root.

Built with [pybind11](https://github.com/pybind/pybind11).
This requires Python 3.7+; for older versions of Python, check the commit
history.

Urs Utzinger 2023

Installation
------------

 - clone this repository
 - ```pip install .``` or add ```-e``` switch to create symbolic links

Test
----

```
python
import fastmath
fastmath.invSqrt_fast(4.321)
```

Also check the tests folder.
