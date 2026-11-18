#include "GeometryPrimitives.h"

std::vector<Vertex> GeometryPrimitives::createCubeVertices()
{
    std::vector<Vertex> cubeVertices;

    // Define the 8 unique vertices of the cube
    glm::vec3 positions[] = {
        {-0.5f, -0.5f, -0.5f}, // 0
        { 0.5f, -0.5f, -0.5f}, // 1
        { 0.5f,  0.5f, -0.5f}, // 2
        {-0.5f,  0.5f, -0.5f}, // 3
        {-0.5f, -0.5f,  0.5f}, // 4
        { 0.5f, -0.5f,  0.5f}, // 5
        { 0.5f,  0.5f,  0.5f}, // 6
        {-0.5f,  0.5f,  0.5f}  // 7
    };

    // Define the normals for each face of the cube
    glm::vec3 normals[] = {
        { 0.0f,  0.0f, -1.0f}, // Front face
        { 0.0f,  0.0f,  1.0f}, // Back face
        {-1.0f,  0.0f,  0.0f}, // Left face
        { 1.0f,  0.0f,  0.0f}, // Right face
        { 0.0f, -1.0f,  0.0f}, // Bottom face
        { 0.0f,  1.0f,  0.0f}  // Top face
    };

    // Define a color for each face
    glm::vec3 colors[] = {
        {1.0f, 0.0f, 0.0f}, // Red
        {0.0f, 1.0f, 0.0f}, // Green
        {0.0f, 0.0f, 1.0f}, // Blue
        {1.0f, 1.0f, 0.0f}, // Yellow
        {1.0f, 0.0f, 1.0f}, // Magenta
        {0.0f, 1.0f, 1.0f}  // Cyan
    };

    // Define the indices for the 12 triangles of the cube
    unsigned int indices[] = {
        0, 1, 2,  2, 3, 0,  // Front face
        4, 5, 6,  6, 7, 4,  // Back face
        0, 3, 7,  7, 4, 0,  // Left face
        1, 5, 6,  6, 2, 1,  // Right face
        0, 1, 5,  5, 4, 0,  // Bottom face
        3, 2, 6,  6, 7, 3   // Top face
    };

    // Construct the vertex data for each triangle
    for (int i = 0; i < 36; i++)
    {
        unsigned int index = indices[i];
        int face = i / 6; // Determine the face based on the triangle index

        Vertex vertex;
        vertex.position = positions[index];
        vertex.normal = normals[face];
        vertex.color = colors[face];

        cubeVertices.push_back(vertex);
    }

    return cubeVertices;
}

std::vector<Vertex> GeometryPrimitives::createPyramidVertices()
{
    std::vector<Vertex> pyramidVertices;

    // 5 унікальних вершин піраміди: 4 кути основи та вершина (апекс)
    glm::vec3 positions[] = {
        {-0.5f, -0.5f, -0.5f}, // 0
        { 0.5f, -0.5f, -0.5f}, // 1
        { 0.5f, -0.5f,  0.5f}, // 2
        {-0.5f, -0.5f,  0.5f}, // 3
        { 0.0f,  0.5f,  0.0f}  // 4 - apex
    };

    // Колір для кожної грані
    glm::vec3 colors[] = {
        {1.0f, 0.0f, 0.0f}, // Front face  - Red
        {0.0f, 1.0f, 0.0f}, // Right face  - Green
        {0.0f, 0.0f, 1.0f}, // Back face   - Blue
        {1.0f, 1.0f, 0.0f}, // Left face   - Yellow
        {1.0f, 0.0f, 1.0f}  // Bottom face - Magenta
    };

    // Індекси 6 трикутників: 4 бічні грані по одному трикутнику і основа з двох
    unsigned int indices[] = {
        0, 1, 4,          // Front face
        1, 2, 4,          // Right face
        2, 3, 4,          // Back face
        3, 0, 4,          // Left face
        0, 2, 1,  0, 3, 2 // Bottom face
    };

    // Номер грані для кожного трикутника (основа складається з двох трикутників)
    int triangleFace[] = { 0, 1, 2, 3, 4, 4 };

    // Центр піраміди: нормаль кожної грані має бути напрямлена від нього назовні
    const glm::vec3 center(0.0f, -0.25f, 0.0f);

    for (int t = 0; t < 6; t++)
    {
        const glm::vec3& a = positions[indices[t * 3 + 0]];
        const glm::vec3& b = positions[indices[t * 3 + 1]];
        const glm::vec3& c = positions[indices[t * 3 + 2]];

        // Нормаль грані - векторний добуток двох її ребер
        glm::vec3 normal = glm::normalize(glm::cross(b - a, c - a));
        glm::vec3 faceCenter = (a + b + c) / 3.0f;
        if (glm::dot(normal, faceCenter - center) < 0.0f)
            normal = -normal;

        for (int k = 0; k < 3; k++)
        {
            Vertex vertex;
            vertex.position = positions[indices[t * 3 + k]];
            vertex.normal = normal;
            vertex.color = colors[triangleFace[t]];
            pyramidVertices.push_back(vertex);
        }
    }

    return pyramidVertices;
}
