# simplex
Simplex Optimization Algorithm and Implemetation in C++ Programming

# Introduction
The downhill simplex algorithm was invented by Nelder and Mead [1]. It is a method to find the minimum of a function in more than one independent variable. The method only requires function evaluations, no derivatives. Thus make it a compelling optimization algorithm when analytic derivative formula is difficult to write out. In this article, I will discuss the simplex algorithm, provide source code and testing code in C++, show rich examples and applications. I will basically follow the spirit of reference [1], in addition, I try to explain the algorithm in a more "example-oriented" manner.

# Background concepts
The downhill simplex algorithm has a vivid geometrical natural interpretation. A simplex is a geometrical polytope which has n + 1 vertexes in a n-dimensional space, e.g. a line segment in 1-dimensional space, a triangle in a plane, a tetrahedron in a 3-dimensional space and so on. In most cases, the dimension of the space represents the number of independent parameters that need to be optimized in order to minimize the value of a function: f(takes a vector of n parameters), where n is the dimension of the space.

To carry out the algorithm, firstly, a set of n+1 points is picked in the n-dimensional space, so that an initial simplex could be constructed. Clearly, the simplex is a n by n+1 matrix, each column is a point (in fact, a vector of size n) in the n-dimensional space. The simplex consists of n+1 such vectors. The initial simplex is constructed to be non-degenerate.
Secondly, the target function f is evaluated for all the n+1 vertexes on the simplex. So we can sort the results and have f(X_1) < f(X_2) . . . < f(X_n) < f( X_{n+1}) . Notice that each X_k is a vector of size n. Because our goal is to minimize the f, so we define the worst point as Xw=X_{n+1} and the best point is X_1.

Thirdly, the algorithm iteratively updates the worst point Xw by four possible actions: 1) reflection, 2) expansion, 3) 1-dimensional contraction, 4) multiple contraction. The following Fig. 1 sketches the actions in a 3-D space with a tetrahedron as the simplex.
