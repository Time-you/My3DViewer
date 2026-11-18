#pragma once

#include "Vertex.h"
#include <vector>

namespace GeometryPrimitives
{
    std::vector<Vertex> createCubeVertices();

    // Чотирикутна піраміда: квадратна основа 1x1 на висоті y = -0.5,
    // вершина в точці (0, 0.5, 0). 6 трикутників (4 бічні грані + 2 в основі).
    std::vector<Vertex> createPyramidVertices();
}
