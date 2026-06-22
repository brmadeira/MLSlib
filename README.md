MLS Surface Library
-------------------

1) About

This software was developed by Bruno Madeira during the course 3D Reconstruction Methods, offered at IMPA in 2007, by the professors Thomas Lewiner and Luiz Velho.
  It is a library written in C++, that implements the algorithm presented in the paper “Defining Point-Set Surfaces”, by Nina Amenta and Yong Joo Kil, in the Siggraph 2004. 
  This algorithm allow us to sample points over a surface defined by a point cloud.
  As pointed in the paper above, Moving Least Squares (MLS) Surfaces define a specific class of Extremal Surfaces. Thus, we decided to provide one C++ class to represent Extremal Surfaces, and so, specialize this concept in a class that represents MLS Surfaces. This approach allow us to extend the library in the future, reducing the effort by code reuse, and keeping the compatibility with the general concept of Extremal Surface using the C++ polymorphism.

3) Requirementes
GSL Library

4) To Install
Type make.

5) To test
Execute the program /demo/mlstest.

6) To Use
Read the documentation in /doc
