/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Collision3D
*/

inline bool Raylib::Collision3D::checkCollision(Vector3 center1, float radius1, Vector3 center2, float radius2)
{
    return ::CheckCollisionSpheres(center1.getCStruct(), radius1, center2.getCStruct(), radius2);
}

inline bool Raylib::Collision3D::checkCollision(::BoundingBox box1, ::BoundingBox box2)
{
    return ::CheckCollisionBoxes(box1, box2);
}

inline bool Raylib::Collision3D::checkCollision(::BoundingBox box1, Vector3 center, float radius)
{
    return ::CheckCollisionBoxSphere(box1, center.getCStruct(), radius);
}

inline bool Raylib::Collision3D::checkCollision(::Ray ray, Vector3 center, float radius)
{
    return ::CheckCollisionRaySphere(ray, center.getCStruct(), radius);
}

inline bool Raylib::Collision3D::checkCollision(::Ray ray, Vector3 center, float radius, Vector3 &collisionPoint)
{
    ::Vector3 collisionVector;
    bool res = ::CheckCollisionRaySphereEx(ray, center.getCStruct(), radius, &collisionVector);

    collisionPoint = collisionVector; //TODO: sure ??
    return res;
}

inline bool Raylib::Collision3D::checkCollision(::Ray ray, ::BoundingBox box)
{
    return ::CheckCollisionRayBox(ray, box);
}

inline ::RayHitInfo Raylib::Collision3D::getCollisionRay(::Ray ray, ::Mesh mesh, ::Matrix transform)
{
    return ::GetCollisionRayMesh(ray, mesh, transform);
}

inline ::RayHitInfo Raylib::Collision3D::getCollisionRay(::Ray ray, ::Model model)
{
    return ::GetCollisionRayModel(ray, model);
}

inline ::RayHitInfo Raylib::Collision3D::getCollisionRay(::Ray ray, Vector3 p1, Vector3 p2, Vector3 p3)
{
    return ::GetCollisionRayTriangle(ray, p1.getCStruct(), p2.getCStruct(), p3.getCStruct());
}

inline ::RayHitInfo Raylib::Collision3D::getCollisionRay(::Ray ray, float groundHeight)
{
    return ::GetCollisionRayGround(ray, groundHeight);
}

